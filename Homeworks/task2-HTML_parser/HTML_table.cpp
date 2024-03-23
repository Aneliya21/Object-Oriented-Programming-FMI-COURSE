#include "HTML_table.h"

unsigned AdditionalFunciotns::fromCharToInt(char ch) {
    return ch - '0';
}

bool AdditionalFunciotns::isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

char* AdditionalFunciotns::handleHTMLcodes(const char* str) {
    if (!str) {
        return nullptr;
    }
    char result[Constants::FIELD_MAX_SIZE + 1];
    size_t strLength = strlen(str);
    result[strLength - 1] = '\0';

    size_t resInd = 0;

    size_t asciiCode = 0;

    while (*str) {
        if (*str == '&') {
            str++;
            if (*str == '#') {
                str++;
                while (isDigit(*str)) {
                    asciiCode *= 10;
                    asciiCode += AdditionalFunciotns::fromCharToInt(*str);
                    str++;
                }
                result[resInd++] = (char)(asciiCode);
            }
        }
        else {
            result[resInd++] = *str;
            str++;
        }
    }
    result[resInd] = '\0';
    return result;
}

void AdditionalFunciotns::printCommands() {
    std::cout << "Commands: " << std::endl;
    std::cout << '\t' << "> add" << std::endl;
    std::cout << '\t' << "> remove" << std::endl;
    std::cout << '\t' << "> edit" << std::endl;
    std::cout << '\t' << "> print" << std::endl;
    std::cout << '\t' << "> end" << std::endl;
}

//Row functions
void Row::parseFields(std::ifstream& ifs, const char* curr, size_t rowIndex, size_t& cols, const char* closeTag) {

    char buff[Constants::FIELD_MAX_SIZE + 1];
    buff[Constants::FIELD_MAX_SIZE] = '\0';

    strcpy(buff, curr);

    bool isTH = false;
    bool isTD = false;

    char buffClose[Constants::FIELD_MAX_SIZE + 1];
    buffClose[Constants::FIELD_MAX_SIZE] = '\0';

    strcpy(buffClose, closeTag);

    //if it is a header tag
    if (strcmp(curr, Constants::TH_OPEN_TAG) == 0) {
        isTH = true;
    }

    //if it is a field tag
    else if (strcmp(curr, Constants::TD_OPEN_TAG) == 0) {
        isTD = true;
    }

    while (isTH || isTD) {

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_LEFT);

        if (isTH)
            headers[cols] = true;

        else if (isTD)
            headers[cols] = false;

        if (strcmp(buff, "") == 0) {
            strcpy(fields[cols++], buff);
        }
        else {
            char res[Constants::FIELD_MAX_SIZE + 1] = "";
            strcpy(res, AdditionalFunciotns::handleHTMLcodes(buff));
            strcpy(fields[cols++], res);
        }

        ifs.getline(buffClose, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_RIGHT);

        if (strcmp(buffClose, Constants::TH_CLOSE_TAG) == 0 || strcmp(buffClose, Constants::TD_CLOSE_TAG) == 0) {
            ifs.getline(buff, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_LEFT);
        }

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

        if (strcmp(buff, Constants::TH_OPEN_TAG) == 0) {
            isTH = true;
            isTD = false;
        }
        else if (strcmp(buff, Constants::TD_OPEN_TAG) == 0) {
            isTD = true;
            isTH = false;
        }
        else {
            break;
        }
    }
}

void Row::saveRow(std::ofstream& ofs, size_t currentRowIndex, size_t colsCount) const {
    for (size_t i = 0; i < colsCount; i++) {
        if (headers[i]) {
            ofs << "   <th>" << fields[i] << "</th>";
            ofs << std::endl;
        }
        else {
            ofs << "   <td>" << fields[i] << "</td>";
            ofs << std::endl;
        }
    }
}

//HTML_table functions
HTML_table::HTML_table(const char* fileName) {
    strcpy(fileToReadTable, fileName);
    parseTable(fileToReadTable);
}

void HTML_table::setFileName(const char* fileName) {
    if (!fileName) {
        return;
    }
    strcpy(fileToReadTable, fileName);
}
void HTML_table::setRowsCount(size_t rowsCount) {
    if (rowsCount > Constants::MAX_ROWS_SIZE) {
        return;
    }
    this->rowsCount = rowsCount;
}
void HTML_table::setColsCount(size_t colsCount) {
    if (colsCount > Constants::MAX_FIELDS_ROW) {
        return;
    }
    this->colsCount = colsCount;
}

const char* HTML_table::getFileName() const {
    return fileToReadTable;
}
size_t HTML_table::getRowsCount() const {
    return rowsCount;
}
size_t HTML_table::getColsCount() const {
    return colsCount;
}

size_t HTML_table::getLongestFieldOnColLength(size_t currCol) const {
    size_t max = 0;
    size_t current = 0;

    /*for (size_t i = 0; i < rowsCount; i++) {
        for (size_t j = 0; j < colsCount; j++) {
            current = strlen(rows[i].fields[j]);
            if (current > max) {
                max = current;
            }
        }
    }*/
    for (size_t i = 0; i < getRowsCount(); i++) {
        current = strlen(rows[i].fields[currCol]);
        if (current > max) {
            max = current;
        }
    }
    return max;
}

void HTML_table::swapRows(Row& first, Row& sec) {
    Row temp = first;
    first = sec;
    sec = temp;
}

void HTML_table::shiftRows(size_t startIndex) {
    for (size_t i = getRowsCount() - 2; i >= startIndex; i--) {
        swapRows(rows[i + 1], rows[i]);
        if (i == 0) {
            break;
        }
    }
}

void HTML_table::printOffsets(size_t offset) const {
    for (size_t i = 0; i < offset; i++) {
        std::cout << ' ';
    }
}

void HTML_table::parseRows(std::ifstream& ifs, size_t& rowIndex) {

    char buff[Constants::FIELD_MAX_SIZE + 1];
    buff[Constants::FIELD_MAX_SIZE] = '\0';

    size_t cols = 0;
    size_t maxCols = 0;

    size_t currPos = 0;

    char closeTag[Constants::FIELD_MAX_SIZE + 1];
    closeTag[Constants::FIELD_MAX_SIZE] = '\0';

    while (!ifs.eof()) {

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

        if (strcmp(buff, "th") == 0) {
            strcpy(closeTag, "/th");
        }
        else if (strcmp(buff, "td") == 0) {
            strcpy(closeTag, "/td");
        }
        else {
            break;
        }

        rows[rowIndex].parseFields(ifs, buff, rowIndex, cols, closeTag);

        rowIndex++;
        if (cols > maxCols) {
            maxCols = cols;
        }

        cols = 0;

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

    }
    setColsCount(maxCols);
}

void HTML_table::parseTable(const char* fileName) {
    if (!fileName) {
        return;
    }
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        return;
    }

    char buff[Constants::FIELD_MAX_SIZE];
    //skip <table>
    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

    //skip <tr>
    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

    parseRows(ifs, rowsCount);

    ifs.close();
}

void HTML_table::serializeTable(const char* fileName) const {
    if (!fileName) {
        return;
    }

    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        return;
    }

    ofs << "<table>" << std::endl;
    for (size_t i = 0; i < getRowsCount(); i++) {

        ofs << " <tr>" << std::endl;

        rows[i].saveRow(ofs, i, getColsCount());

        ofs << " </tr>" << std::endl;
    }

    ofs << "</table>" << std::endl;

    ofs.close();
}

void HTML_table::add(size_t rowNumber, const Row& toAdd) { ////////////////////////NOT WORKING PROPERLY, add a column
    if (rowNumber > getRowsCount()) {
        return;
    }

    setRowsCount(getRowsCount() + 1);
   
    if (rowNumber > 1) {
        shiftRows(rowNumber - 1);
    }
    else if (rowNumber == 1) {
        shiftRows(rowNumber - 1);
    }
    
    rows[rowNumber - 1] = toAdd;
}

void HTML_table::remove(size_t rowNumber) { ////////also not working, delete a column
    if (rowNumber > getRowsCount()) {
        return;
    }

    swapRows(rows[rowNumber - 1], rows[getRowsCount() - 1]);
    rowsCount--;
}
void HTML_table::edit(size_t rowNumber, size_t colNumber, const char* newValue) {
    if (rowNumber > getRowsCount() || colNumber > getColsCount() || !newValue) {
        return;
    }

    strcpy(rows[rowNumber - 1].fields[colNumber - 1], newValue);
}
void HTML_table::print()  const {

    size_t setwVal = 0;

    size_t offset = 0;
    size_t currFieldLen = 0;

    for (size_t i = 0; i < getRowsCount(); ++i) {
        for (size_t j = 0; j < getColsCount(); ++j) {

            setwVal = getLongestFieldOnColLength(j) + 2;

            currFieldLen = strlen(rows[i].fields[j]);

            offset = setwVal - currFieldLen;

            if (rows[i].headers[j]) {
                std::cout << "|*" << rows[i].fields[j];
                printOffsets(offset - 2);
                std::cout << "*";
            }
            else {
                std::cout << '|' << rows[i].fields[j];
                printOffsets(offset);
            }
        }
        std::cout << '|' << std::endl;
    }
}

HTML_table::~HTML_table() {
    serializeTable(getFileName());
}

