#pragma once

#include "Row.h"

#pragma warning (disable:4996)

class HTML_table {
private:
    //array of rows
    Row rows[Constants::MAX_ROWS_SIZE];

    //current sizes of the table
    size_t rowsCount = 0;
    size_t colsCount = 0;
    
    //variable that keeps the name of the file from which the table has been loaded
    char fileToReadTable[Constants::FILE_TO_READ_LENGTH] = "";


    //for the alignment, when the table is printed on the console
    size_t getLongestFieldOnColLength(size_t currCol) const;

    //for the remove() function
    void swapRows(Row&, Row&);

    //for the add() function
    void shiftRows(size_t);

    //for the alignment, when the table is printed on the console
    void printOffsets(size_t) const;

    //to read the rows from the table
    void parseRows(std::ifstream&, size_t&);

    //to read the whole table
    void parseTable(const char*);

    //to save the table to file
    void serializeTable(const char* fileName) const;

    //to print each field on a row
    void printRow(size_t i) const;

public:
    //converting constructior with one parameter - the file from which to read the table
    HTML_table(const char* fileName);

    //setters
    void setFileName(const char* fileName);
    void setRowsCount(size_t rowsCount);
    void setColsCount(size_t colsCount);

    //getters
    const char* getFileName() const;
    size_t getRowsCount() const;
    size_t getColsCount() const;

    //add row at "rowNumber" index in the loaded table
    void add(size_t rowNumber, const Row& toAdd);

    //remove row at "rowNumber" index in the loaded table
    void remove(size_t rowNumber);

    //edit a particular field from the table
    void edit(size_t rowNumber, size_t colNumber, const char* newValue);

    //print the table
    void print()  const;

    //in the destructor save the table in the same file from where it has been loaded
    ~HTML_table();

};

