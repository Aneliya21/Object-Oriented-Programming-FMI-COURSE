#include "HTML_table.h"

HTML_table::HTML_table(const char* fileName) {
    setFileName(fileName);
    parseTable(fileToReadTable);
}

void HTML_table::setFileName(const char* fileName) {
    if (!fileName || strlen(fileName)>Constants::FILE_TO_READ_LENGTH) {
        return;
    }
    strcpy(fileToReadTable, fileName);
}
void HTML_table::setRowsCount(size_t rowsCount) {
    if (rowsCount < 0 || rowsCount > Constants::MAX_ROWS_SIZE) {
        return;
    }
    this->rowsCount = rowsCount;
}
void HTML_table::setColsCount(size_t colsCount) {
    if (colsCount < 0 || colsCount > Constants::MAX_FIELDS_ROW) {
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

//for the columns alignment
size_t HTML_table::getLongestFieldOnColLength(size_t currCol) const {
    size_t max = 0;
    size_t current = 0;

    //find the size of the longest string on col
    for (size_t i = 0; i < getRowsCount(); i++) {

        current = strlen(rows[i].getFieldAtIndex(currCol));

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

//if a new row is added to shift the rows and make space for the new row
void HTML_table::shiftRows(size_t startIndex) {
    for (size_t i = getRowsCount() - 2; i >= startIndex; i--) {

        swapRows(rows[i + 1], rows[i]);
        if (i == 0) {
            break;
        }
    }
}

//printing spaces to align the columns
void HTML_table::printOffsets(size_t offset) const {
    for (size_t i = 0; i < offset; i++) {
        std::cout << ' ';
    }
}

void HTML_table::parseRows(std::ifstream& ifs, size_t& rowIndex) {

    char buff[Constants::BUFFER_SIZE + 1];
    buff[Constants::BUFFER_SIZE] = '\0';

    size_t cols = 0;
    size_t maxCols = 0;

    size_t currPos = 0;

    char closeTag[Constants::BUFFER_SIZE + 1];
    closeTag[Constants::BUFFER_SIZE] = '\0';

    while (!ifs.eof()) {

        //rows count validation
        if (rowIndex > Constants::MAX_ROWS_SIZE) {
            break;
        }

        //find the current open tag
        ifs.getline(buff, Constants::BUFFER_SIZE, Constants::SEPARATOR_LEFT);
        ifs.getline(buff, Constants::BUFFER_SIZE, Constants::SEPARATOR_RIGHT);

        //find the current close tag of the found tag 
        if (strcmp(buff, Constants::TH_OPEN_TAG) == 0) {
            strcpy(closeTag, Constants::TH_CLOSE_TAG);
        }
        else if (strcmp(buff, Constants::TD_OPEN_TAG) == 0) {
            strcpy(closeTag, Constants::TD_CLOSE_TAG);
        }
        else {
            break;
        }

        //parse current row
        rows[rowIndex].parseFields(ifs, buff, cols, closeTag);

        //increase rows with 1
        rowIndex++;

        //find the max count of columns
        if (cols > maxCols) {
            maxCols = cols;
        }

        cols = 0;
        //to skip the <tr> tag
        ifs.getline(buff, Constants::BUFFER_SIZE, Constants::SEPARATOR_LEFT);
        ifs.getline(buff, Constants::BUFFER_SIZE, Constants::SEPARATOR_RIGHT);

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

    //parse the rest
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

void HTML_table::add(size_t rowNumber, const Row& toAdd) {
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
void HTML_table::remove(size_t rowNumber) {
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

    rows[rowNumber - 1].setFieldAtIndex(colNumber - 1, newValue);
}

void HTML_table::printRow(size_t i) const {

    size_t setwVal = 0;

    size_t offset = 0;
    size_t currFieldLen = 0;

    for (size_t j = 0; j < getColsCount(); ++j) {

        setwVal = getLongestFieldOnColLength(j) + 2;

        currFieldLen = strlen(rows[i].getFieldAtIndex(j));

        offset = setwVal - currFieldLen;

        if (rows[i].getHeaderAtIndex(j)) {

            std::cout << "|*" << rows[i].getFieldAtIndex(j);

            printOffsets(offset - 2);
            std::cout << "*";
        }
        else {

            std::cout << "|" << rows[i].getFieldAtIndex(j);

            printOffsets(offset);
        }
    }
}

void HTML_table::print()  const {

    for (size_t i = 0; i < getRowsCount(); ++i) {
        printRow(i);
        std::cout << '|' << std::endl;
    }
}

HTML_table::~HTML_table() {

    serializeTable(getFileName());

}

