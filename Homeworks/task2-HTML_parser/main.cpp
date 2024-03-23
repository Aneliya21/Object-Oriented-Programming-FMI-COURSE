#include <iostream>
#include "HTML_table.h"

int main() {

    char fileName[Constants::FILE_TO_READ_LENGTH];

    std::cout << "file name to read table from: ";

    std::cin >> fileName;
    std::cout << std::endl;

    if (!fileName || strlen(fileName) > Constants::FILE_TO_READ_LENGTH) {
        std::cout << "Invalid file name" << std::endl;
        return -1;
    }

    HTML_table t(fileName);

    AdditionalFunciotns::printCommands();

    char command[10];

    while (true) {
        std::cout << std::endl << "> ";
        std::cin >> command;

        if (!command || strlen(command) > 10) {
            std::cout << "Invald command" << std::endl;
            return -1;
        }

        if (strcmp(command, Constants::ADD) == 0) {
            std::cout << "add at index: ";
            size_t index = 0;
            std::cin >> index;

            while (index<0 || index>t.getRowsCount()) {
                std::cout << "Invalid index" << std::endl << "Try again" << std::endl;
                std::cin >> index;
                std::cout << std::endl;
            }

            Row toAdd;

            std::cout << "fields count: ";
            size_t count = 0;
            std::cin >> count;
            std::cout << std::endl;

            while (count > t.getColsCount()) {
                std::cout << "Invalid fields count" << std::endl << "Try again" << std::endl;
                std::cin >> count;
                std::cout << std::endl;
            }

            char field[Constants::FIELD_MAX_SIZE + 1];
            field[Constants::FIELD_MAX_SIZE] = '\0';

            char headerAns[4]; //4, because strlen(yes) = 3 + 1 for the '\0'
            headerAns[3] = '\0';

            for (size_t i = 0; i < count; i++) {
                std::cout << "field name: ";
                std::cin >> field;
                std::cout << std::endl;

                while (!field || strlen(field) > Constants::FIELD_MAX_SIZE) {
                    std::cout << "Invalid field name" << std::endl << "Try again" << std::endl;
                    std::cin >> field;
                    std::cout << std::endl;
                }

                std::cout << "->is field header: ";
                std::cin >> headerAns;
                std::cout << std::endl;

                if (strcmp(headerAns, "yes") == 0) {
                    toAdd.headers[i] = true;
                }
                else if (strcmp(headerAns, "no") == 0) {
                    toAdd.headers[i] = false;
                }
                else {
                    while (strcmp(headerAns, "yes") != 0 || strcmp(headerAns, "no") != 0) {
                        std::cout << "Invalid answer" << std::endl << "Try again" << std::endl;
                        std::cin >> headerAns;
                        std::cout << std::endl;
                    }
                }

                strcpy(toAdd.fields[i], field);
            }

            t.add(index, toAdd);

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
        else if (strcmp(command, Constants::END) == 0) {
            break;
        }
        else {
            std::cout << "Invalid command" << std::endl << "Try again: ";
            continue;
        }
    }
    return 0;
}
