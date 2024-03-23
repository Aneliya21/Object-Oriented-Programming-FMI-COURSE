#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Constants.h"

namespace AdditionalFunciotns {
    unsigned fromCharToInt(char ch);
    bool isDigit(char ch);
    char* handleHTMLcodes(const char* str);

    void printCommands();
}

