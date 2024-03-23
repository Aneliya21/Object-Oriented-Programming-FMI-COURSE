
#include "Additional_Functions.h"

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