#include "HTML_table.h"

size_t AdditionalFunctions::getFileSize(std::ifstream& ifs) {
    size_t curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);

    size_t size = ifs.tellg();
    ifs.seekg(curr);

    return size;
}

//source: https://github.com/Angeld55/Introduction_to_programming_FMI/blob/main/Sem.%2010/search_in_text.cpp
bool AdditionalFunctions::isPrefix(const char* pattern, const char* text) {
    while (*text != '\0' && *pattern != '\0') {
        if (*text != *pattern)
            return false;
        text++;
        pattern++;
    }
    return *pattern == '\0';
}
bool AdditionalFunctions::searchInText(const char* text, const char* pattern) {
    size_t textLen = strlen(text);
    size_t patternLen = strlen(pattern);
    while (patternLen <= textLen) {
        if (isPrefix(pattern, text))
            return true;
        text++; //подминаваме първия символ
        textLen--;
    }
    return false;
}

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
    return rowsCount;
}

size_t HTML_table::getLongestFieldLength() const {
    size_t max = 0;
    size_t current = 0;
    for (size_t i = 0; i < rowsCount; i++) {
        for (size_t j = 0; j < colsCount; j++) {
            current = strlen(rows[i].fields[j]);
            if (current > max) {
                max = current;
            }
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
    for (size_t i = rowsCount - 2; i >= startIndex; i--) {
        swapRows(rows[i + 1], rows[i]);
    }
}

void HTML_table::printOffsets(size_t offset) const {
    for (size_t i = 0; i < offset; i++) {
        std::cout << ' ';
    }
}

void HTML_table::parseFields(std::ifstream& ifs, const char* curr, size_t rowIndex, size_t& cols, const char* closeTag) {
    char buff[Constants::FIELD_MAX_SIZE];
    strcpy(buff, curr);

    bool isTH = false;
    bool isTD = false;

    char buffClose[Constants::FIELD_MAX_SIZE];
    strcpy(buffClose, closeTag);

    if (strcmp(curr, "th") == 0) {
        isTH = true;
    }
    else if (strcmp(curr, "td") == 0) {
        isTD = true;
    }

    while (isTH || isTD) {

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');

        if (isTH)
            rows[rowIndex].headers[cols] = true;

        else if (isTD)
            rows[rowIndex].headers[cols] = false;

        strcpy(rows[rowIndex].fields[cols++], buff);

        ifs.getline(buffClose, Constants::FIELD_MAX_SIZE, '>');

        //if (strcmp(buff, closeTag) == 0) {
        if (strcmp(buffClose, "/th") == 0 || strcmp(buffClose, "/td") == 0)
            ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

        if (strcmp(buff, "th") == 0) {
            isTH = true;
            isTD = false;
        }
        else if (strcmp(buff, "td") == 0) {
            isTD = true;
            isTH = false;
        }
        else {
            //strcpy(curr, buff);
            break;
        }
        //}
       /* else {
            break;
        }*/
    }
}

void HTML_table::parseRows(std::ifstream& ifs, size_t& rowIndex/*, const char* separatorOpen, const char* separatorClose*/) {
    char buff[Constants::FIELD_MAX_SIZE];

    size_t cols = 0;
    size_t maxCols = 0;


    size_t currPos = 0;

    char closeTag[Constants::FIELD_MAX_SIZE];

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

        parseFields(ifs, buff, rowIndex, cols, closeTag);
        rowIndex++;
        if (cols > maxCols) {
            maxCols = cols;
        }
        cols = 0;
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

    }
    colsCount = maxCols;
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

}

void HTML_table::saveRow(std::ofstream& ofs, size_t currentRowIndex) const {
    for (size_t i = 0; i < colsCount; i++) {
        if (rows[currentRowIndex].headers[i]) {
            ofs << "   <th>" << rows[currentRowIndex].fields[i] << "</th>";
            ofs << std::endl;
        }
        else {
            ofs << "   <td>" << rows[currentRowIndex].fields[i] << "</td>";
            ofs << std::endl;
        }
    }
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
    for (size_t i = 0; i < rowsCount; i++) {
        ofs << " <tr>" << std::endl;
        saveRow(ofs, i);
        ofs << " </tr>" << std::endl;
    }
    ofs << "</table>" << std::endl;
}

void HTML_table::add(size_t rowNumber, const Row& toAdd) {
    if (rowNumber > rowsCount) {
        return;
    }
    rowsCount++;
    shiftRows(rowNumber - 1);
    rows[rowNumber - 1] = toAdd;
}
void HTML_table::remove(size_t rowNumber) {
    if (rowNumber > rowsCount) {
        return;
    }

    swapRows(rows[rowNumber - 1], rows[rowsCount - 1]);
    rowsCount--;
}
void HTML_table::edit(size_t rowNumber, size_t colNumber, const char* newValue) {
    if (rowNumber > getRowsCount() || colNumber > getColsCount() || !newValue) {
        return;
    }

    strcpy(rows[rowNumber - 1].fields[colNumber - 1], newValue);
}
void HTML_table::print()  const {
    size_t setwVal = getLongestFieldLength();

    size_t offset = 0;
    size_t currFieldLen = 0;

    setwVal += 2;

    /*size_t rows = getRowsCount();
    size_t cols = getColsCount();*/

    for (size_t i = 0; i < rowsCount; ++i) {
        for (size_t j = 0; j < colsCount; ++j) {

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

