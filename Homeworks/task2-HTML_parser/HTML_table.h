#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#pragma warning (disable:4996)

namespace Constants {
    constexpr size_t FIELD_MAX_SIZE = 50; //after transf char entity ref
    constexpr size_t MAX_FIELDS_ROW = 15;
    constexpr size_t MAX_ROWS_SIZE = 100;

    constexpr size_t BUFFER_SIZE = 1024;

    //COMMANDS
    const char ADD[] = "add";
    const char REMOVE[] = "remove";
    const char EDIT[] = "edit";
    const char PRINT[] = "print";

}

namespace AdditionalFunctions {

    size_t getFileSize(std::ifstream& ifs);

    //source: https://github.com/Angeld55/Introduction_to_programming_FMI/blob/main/Sem.%2010/search_in_text.cpp
    bool isPrefix(const char* pattern, const char* text);

    bool searchInText(const char* text, const char* pattern);
}

typedef char Field[Constants::FIELD_MAX_SIZE];

struct Row {
    Field fields[Constants::FIELD_MAX_SIZE]{ "" };
    bool headers[Constants::FIELD_MAX_SIZE]{ false };
};

class HTML_table {
private:
    Row rows[Constants::MAX_ROWS_SIZE];
    size_t rowsCount = 0;
    size_t colsCount = 0;

    char fileToReadTable[64];

    size_t getLongestFieldLength() const;

    void swapRows(Row&, Row&);

    void shiftRows(size_t);

    void printOffsets(size_t) const;

    void saveRow(std::ofstream& ofs, size_t currentRowIndex) const;

    void parseFields(std::ifstream&, const char*, size_t, size_t&, const char*);

    void parseRows(std::ifstream&, size_t&/*, const char* separatorOpen, const char* separatorClose*/);

    void parseTable(const char*);

    void serializeTable(const char* fileName) const;

public:

    HTML_table(const char* fileName);

    void setFileName(const char* fileName);
    void setRowsCount(size_t rowsCount);
    void setColsCount(size_t colsCount);

    const char* getFileName() const;
    size_t getRowsCount() const;
    size_t getColsCount() const;


    void add(size_t rowNumber, const Row& toAdd);

    void remove(size_t rowNumber);

    void edit(size_t rowNumber, size_t colNumber, const char* newValue);

    void print()  const;


    ~HTML_table();

};

