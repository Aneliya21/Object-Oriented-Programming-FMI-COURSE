#include "Row.h"

void Row::parseFields(std::ifstream& ifs, const char* curr, size_t rowIndex, size_t& cols, const char* closeTag) {

    char buff[Constants::FIELD_MAX_SIZE + 1];
    buff[Constants::FIELD_MAX_SIZE] = '\0';

    strcpy(buff, curr);

    bool isTH = false;
    bool isTD = false;

    char buffClose[Constants::FIELD_MAX_SIZE + 1];
    buffClose[Constants::FIELD_MAX_SIZE] = '\0';

    strcpy(buffClose, closeTag);

    //if it is a header tag
    if (strcmp(curr, Constants::TH_OPEN_TAG) == 0) {
        isTH = true;
    }

    //if it is a field tag
    else if (strcmp(curr, Constants::TD_OPEN_TAG) == 0) {
        isTD = true;
    }

    while (isTH || isTD) {

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_LEFT);

        if (isTH)
            headers[cols] = true;

        else if (isTD)
            headers[cols] = false;

        if (strcmp(buff, "") == 0) {
            strcpy(fields[cols++], buff);
        }
        else {
            char res[Constants::FIELD_MAX_SIZE + 1] = "";
            strcpy(res, AdditionalFunciotns::handleHTMLcodes(buff));
            strcpy(fields[cols++], res);
        }

        ifs.getline(buffClose, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_RIGHT);

        if (strcmp(buffClose, Constants::TH_CLOSE_TAG) == 0 || strcmp(buffClose, Constants::TD_CLOSE_TAG) == 0) {
            ifs.getline(buff, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_LEFT);
        }

        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

        if (strcmp(buff, Constants::TH_OPEN_TAG) == 0) {
            isTH = true;
            isTD = false;
        }
        else if (strcmp(buff, Constants::TD_OPEN_TAG) == 0) {
            isTD = true;
            isTH = false;
        }
        else {
            break;
        }
    }
}

void Row::saveRow(std::ofstream& ofs, size_t currentRowIndex, size_t colsCount) const {
    for (size_t i = 0; i < colsCount; i++) {
        if (headers[i]) {
            ofs << "   <th>" << fields[i] << "</th>";
            ofs << std::endl;
        }
        else {
            ofs << "   <td>" << fields[i] << "</td>";
            ofs << std::endl;
        }
    }
}