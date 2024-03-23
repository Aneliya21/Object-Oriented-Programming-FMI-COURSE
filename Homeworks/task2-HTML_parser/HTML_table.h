#pragma once

#include "Row.h"

#pragma warning (disable:4996)

class HTML_table {
private:
    Row rows[Constants::MAX_ROWS_SIZE];
    size_t rowsCount = 0;
    size_t colsCount = 0;

    char fileToReadTable[Constants::FILE_TO_READ_LENGTH];

    size_t getLongestFieldOnColLength(size_t currCol) const;

    void swapRows(Row&, Row&);

    void shiftRows(size_t);

    void printOffsets(size_t) const;

    void parseRows(std::ifstream&, size_t&);

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

