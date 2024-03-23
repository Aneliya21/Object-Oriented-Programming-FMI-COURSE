#include "Row.h"

void Row::parseFields(std::ifstream& ifs, const char* curr, size_t& cols, const char* closeTag) {

    char buff[Constants::FIELD_MAX_SIZE + 1];
    buff[Constants::FIELD_MAX_SIZE] = '\0';

    strcpy(buff, curr);

    bool isTH = false; //is <th> tag
    bool isTD = false; //is <td> tag

    char buffClose[Constants::FIELD_MAX_SIZE + 1];
    buffClose[Constants::FIELD_MAX_SIZE] = '\0';

    strcpy(buffClose, closeTag); //current close tag

    //if it is a header tag
    if (strcmp(curr, Constants::TH_OPEN_TAG) == 0) {
        isTH = true;
    }

    //if it is a field tag
    else if (strcmp(curr, Constants::TD_OPEN_TAG) == 0) {
        isTD = true;
    }

    while (isTH || isTD) {

        //field text (read until '<')
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_LEFT);

        //check if header
        if (isTH)
            headers[cols] = true;

        else if (isTD)
            headers[cols] = false;

        //if buffer is empty string
        if (strcmp(buff, "") == 0) {
            strcpy(fields[cols++], buff);
        }
        else { //handle character entity reference cases
            char res[Constants::FIELD_MAX_SIZE + 1] = "";
            strcpy(res, AdditionalFunciotns::handleHTMLcodes(buff));
            strcpy(fields[cols++], res); //set current field
        }

        //geting the close tag (read until '>')
        ifs.getline(buffClose, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_RIGHT);

        //if it is a close tag, skip if there are spaces, new lines or other until the next '<'
        if (strcmp(buffClose, Constants::TH_CLOSE_TAG) == 0 || strcmp(buffClose, Constants::TD_CLOSE_TAG) == 0) {
            ifs.getline(buff, Constants::FIELD_MAX_SIZE, Constants::SEPARATOR_LEFT);
        }
        //get the next tad
        ifs.getline(buff, Constants::FIELD_MAX_SIZE, '>');

        //check if it is a field tag
        if (strcmp(buff, Constants::TH_OPEN_TAG) == 0) {
            isTH = true;
            isTD = false;
        }
        else if (strcmp(buff, Constants::TD_OPEN_TAG) == 0) {
            isTD = true;
            isTH = false;
        }
        //if it is not, then break
        else {
            break;
        }
    }
}

void Row::saveRow(std::ofstream& ofs, size_t currentRowIndex, size_t colsCount) const { //save current row to file
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