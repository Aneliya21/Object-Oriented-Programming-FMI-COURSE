#pragma once
#include "Additional_Functions.h"

#pragma warning (disable:4996)

typedef char Field[Constants::FIELD_MAX_SIZE + 1];

struct Row {
    Field fields[Constants::FIELD_MAX_SIZE]{ "" };
    bool headers[Constants::FIELD_MAX_SIZE]{ false };

    void parseFields(std::ifstream&, const char*, size_t, size_t&, const char*);

    void saveRow(std::ofstream& ofs, size_t currentRowIndex, size_t colsCount) const;
};

