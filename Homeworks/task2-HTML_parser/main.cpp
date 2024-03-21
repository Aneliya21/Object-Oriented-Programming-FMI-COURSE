#include <iostream>
#include "HTML_table.h"

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

    char fileName[64];

    std::cin >> fileName;

    HTML_table t(fileName);

    std::cout << "Commands: " << std::endl;
    std::cout << '\t' << "> add" << std::endl;
    std::cout << '\t' << "> remove" << std::endl;
    std::cout << '\t' << "> edit" << std::endl;
    std::cout << '\t' << "> print" << std::endl;
    std::cout << '\t' << "> end" << std::endl;

    char command[10];

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (strcmp(command, Constants::ADD) == 0) {

        }
        else if (strcmp(command, Constants::REMOVE) == 0) {
            size_t rowInd = 0;
            std::cout << "row index: ";
            std::cin >> rowInd;
            t.remove(rowInd);
        }
        else if (strcmp(command, Constants::EDIT) == 0) {
            size_t rowNum = 0, colNum = 0;
            char newVal[Constants::FIELD_MAX_SIZE];
            std::cout << "row index: ";
            std::cin >> rowNum;
            std::cout << std::endl;
            std::cout << "column index: ";
            std::cin >> colNum;
            std::cout << std::endl;
            std::cout << "new value: ";
            std::cin >> newVal;
            t.edit(rowNum, colNum, newVal);
        }
        else if (strcmp(command, Constants::PRINT) == 0) {
            t.print();
        }
        else if (strcmp(command, "end") == 0) {
            break;
        }
    }
    return 0;
}