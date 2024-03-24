#pragma once
#include "Additional_Functions.h"

#pragma warning (disable:4996)

typedef char Field[Constants::FIELD_MAX_SIZE + 1];

struct Row {
private:
    Field fields[Constants::FIELD_MAX_SIZE]{ "" };
    bool headers[Constants::FIELD_MAX_SIZE]{ false };

public:

    const Field& getFieldAtIndex(size_t index) const;
    bool getHeaderAtIndex(size_t index) const;

    void setFieldAtIndex(size_t index, const char* buff);
    void setHeaderAtIndex(size_t index, bool value);

    void parseFields(std::ifstream&, const char*, size_t&, const char*);
    void saveRow(std::ofstream& ofs, size_t currentRowIndex, size_t colsCount) const;
};

