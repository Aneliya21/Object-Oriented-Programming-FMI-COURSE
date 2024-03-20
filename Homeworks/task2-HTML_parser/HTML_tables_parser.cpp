#include "HTML_tables_parser.h"

char AdditionalFunctions::getSeparatorFromString(const char* str) {
    //TABLE TAGS - SEPARATORS
    if (strcmp(str, "<table") == 0) {
        return Constants::TABLE_OPEN_TAG;
    }
    else if (strcmp(str, "</table") == 0) {
        return Constants::TABLE_CLOSE_TAG;
    }
    //TABLE HEADER TAGS - SEPARATORS
    else if (strcmp(str, "<th") == 0) {
        return Constants::HEADER_OPEN_TAG;
    }
    else if (strcmp(str, "</th") == 0) {
        return Constants::HEADER_CLOSE_TAG;
    }

    //TABLE ROW TAGS - SEPARATORS
    else if (strcmp(str, "<tr") == 0) {
        return Constants::ROW_OPEN_TAG;
    }
    else if (strcmp(str, "</tr") == 0) {
        return Constants::ROW_CLOSE_TAG;
    }

    //TABLE FIELD TAGS - SEPARATOR
    else if (strcmp(str, "<td") == 0) {
        return Constants::FIELD_OPEN_TAG;
    }
    else if (strcmp(str, "</td") == 0) {
        return Constants::FIELD_CLOSE_TAG;
    }

    else
        return '0';
}

size_t AdditionalFunctions::getFileSize(std::ifstream& ifs) {
    size_t curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);

    size_t size = ifs.tellg();
    ifs.seekg(curr);

    return size;
}

char* AdditionalFunctions::getStringFromFile(const char* fileName) {
    if (!fileName) {
        return nullptr;
    }

    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open()) {
        return nullptr;
    }

    size_t fileSize = getFileSize(ifs);

    char* buffer = new char[fileSize + 1];
    buffer[fileSize] = '\0';

    ifs.read(buffer, fileSize);

    ifs.close();

    return buffer;
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

char* HTML_table::getCurrentString(std::ifstream& ifs) {
    char* result = new char[Constants::FIELD_MAX_SIZE];
    ifs.getline(result, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR);
    return result;
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

void HTML_table::parseRows(std::ifstream& ifs, size_t rowIndex, const char* separatorOpen, const char* separatorClose) {
    char buff[Constants::FIELD_MAX_SIZE];

    size_t cols = 0;

    while (!ifs.eof()) {

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');
        // "th"
        while (strcmp(buff, separatorOpen) == 0) {

            ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
            strcpy(rows[rowIndex].fields[cols++], buff);

            ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');
            // "/th"
            if (strcmp(buff, separatorClose) == 0) {
                ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
                ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');
                continue;
            }
            else {
                break;
            }
        }

        if (strcmp(buff, "/tr") == 0) {
            colsCount = cols;
            break;
        }
    }
}

void HTML_table::parseTable(const char* fileName) {
    if (!fileName) {
        return;
    }
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        return;
    }

    bool table = false;
    bool row = true;

    char buff[Constants::FIELD_MAX_SIZE];

    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');
    if (strcmp(buff, "table") == 0) {
        table = true;
    }

    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '<');
    ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');
    if (strcmp(buff, "tr") == 0) {
        row = true;
    }

    parseRows(ifs, 0, "th", "/th");
    //
    parseRows(ifs, 1, "td", "/td");
    parseRows(ifs, 2, "td", "/td");
    parseRows(ifs, 3, "td", "/td");

}

size_t HTML_table::parseCountOfRowsFromFile(std::ifstream& ifs) {
    size_t count = 0;
    char buff[Constants::MAX_SYMBOLS_ON_ROW];
    while (!ifs.eof()) {

        ifs.getline(buff, Constants::MAX_SYMBOLS_ON_ROW);

        if (AdditionalFunctions::searchInText(buff, "<tr>")) {
            count++;
        }
    }
    return count;
}

size_t HTML_table::parseCountOfColsFromFile(std::ifstream& ifs) {
    size_t count = 0;
    size_t max = 0;
    char buff[Constants::MAX_SYMBOLS_ON_ROW];
    while (!ifs.eof()) {

        ifs.getline(buff, Constants::MAX_SYMBOLS_ON_ROW);

        if (AdditionalFunctions::searchInText(buff, "<td>")) {
            count++;
            if (max < count) {
                max = count;
            }
        }
    }
    return max;
}

//void parseTable(std::ifstream& ifs, HTML_table& result) {
//    //HTML_table result;
//    
//    char buff[Constants::MAX_SYMBOLS_ON_ROW];
//    while (!ifs.eof()) {
//        ifs.getline(buff, Constants::MAX_SYMBOLS_ON_ROW);
//        if (AdditionalFunctions::searchInText(buff, "<tr>")) {
//            std::stringstream ss(buff);
//            char currField[Constants::FIELD_MAX_SIZE + 4];
//            size_t currColCount = 0;
//            while (!ss.eof()) {
//                ss.getline(currField, Constants::FIELD_MAX_SIZE + 4, '<');
//                if (AdditionalFunctions::searchInText(currField, "<td>")) {
//                    char data[Constants::FIELD_MAX_SIZE];
//                    ss.getline(data, Constants::FIELD_MAX_SIZE, '>');
//                    ss.getline(data, Constants::FIELD_MAX_SIZE, '<');
//                    strcpy(result.rows[result.rowsCount].fields[currColCount++], data);
//                }
//            }
//            result.colsCount = currColCount > result.colsCount ? currColCount : result.colsCount;
//            ++result.rowsCount;
//        }
//    }
//}

/*void parseFromFile(const char* fileName, HTML_table& table) {
    if (!fileName) {
        return ;
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        return ;
    }

    parseTable(ifs, table);
}*/

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
    if (rowNumber > rowsCount || colNumber > colsCount || !newValue) {
        return;
    }

    strcpy(rows[rowNumber - 1].fields[colNumber - 1], newValue);
}

void HTML_table::print()  const {
    size_t setwVal = getLongestFieldLength();

    size_t offset = 0;
    size_t currFieldLen = 0;

    //print headers
    for (size_t i = 0; i < colsCount; i++) {
        currFieldLen = strlen(rows[0].fields[i]);
        offset = setwVal - currFieldLen;
        std::cout << "|*" << rows[0].fields[i];
        printOffsets(offset);
        std::cout << "*";
    }
    std::cout << '|' << std::endl;

    setwVal += 2;

    //print rows
    for (size_t i = 1; i < rowsCount; ++i) {
        for (size_t j = 0; j < colsCount; ++j) {

            currFieldLen = strlen(rows[i].fields[j]);
            offset = setwVal - currFieldLen;

            std::cout << '|' << rows[i].fields[j];
            printOffsets(offset);
        }
        std::cout << '|' << std::endl;
    }
}


int main() {

    /*Row row1 = {"str1gsd", "str2", "str3"};
    Row row2 = { "str1", "str2", "str3" };
    //
    Row row3 = { "str3", "str3", "str3" };

    Row toAdd = { "fsad", "gre", "rsda", "tewfc"};

    HTML_table t = { row1, row2, row3 };

    t.colsCount = 3;
    t.rowsCount = 3;

    t.print();*/

    HTML_table t;
    t.parseTable("file.txt");
    t.colsCount = 3;
    t.rowsCount = 4;
    t.print();

    
}