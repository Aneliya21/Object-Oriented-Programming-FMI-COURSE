#include "Additional_Functions.h"

unsigned AdditionalFunctions::powerOfTwo(unsigned n) {
    return 1 << n;
}

size_t AdditionalFunctions::getFileSize(std::ifstream& ifs) {
    size_t currentPosition = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t fileSize = ifs.tellg();
    ifs.seekg(currentPosition);

    return fileSize;
}