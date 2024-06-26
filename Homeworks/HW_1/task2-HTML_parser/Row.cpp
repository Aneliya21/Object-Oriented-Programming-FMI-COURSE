#include "Row.h"

const Field& Row::getFieldAtIndex(size_t index) const {
    return fields[index];
}

bool Row::getHeaderAtIndex(size_t index) const {
    return headers[index];
}

void Row::setFieldAtIndex(size_t index, const char* buff) {
    if ((strlen(buff) > Constants::FIELD_MAX_SIZE) || (index < 0) || (index > Constants::MAX_FIELDS_ROW)) {
        return;
    }
    strcpy(fields[index], buff);
}
void Row::setHeaderAtIndex(size_t index, bool value) {
    if (index >= 0 && index < Constants::MAX_FIELDS_ROW) {
        headers[index] = value;
    }
    else {
        return;
    }
}

void Row::parseFields(std::ifstream& ifs, const char* curr, size_t& cols, const char* closeTag) {

    char buff[Constants::BUFFER_SIZE + 1];
    buff[Constants::BUFFER_SIZE] = '\0';

    strcpy(buff, curr); //current open tag

    char buffClose[Constants::BUFFER_SIZE + 1];
    buffClose[Constants::BUFFER_SIZE] = '\0';

    strcpy(buffClose, closeTag); //current close tag

    bool isTH = false; //is <th> tag
    bool isTD = false; //is <td> tag

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
        ifs.getline(buff, Constants::BUFFER_SIZE, Constants::SEPARATOR_LEFT);

        //check if header
        if (isTH)
            setHeaderAtIndex(cols, true);

        else if (isTD)
            setHeaderAtIndex(cols, false);

        //if buffer is empty string
        if (strcmp(buff, "") == 0) {
            strcpy(fields[cols++], buff);
        }

        else { //handle character entity reference cases
            
            char res[Constants::FIELD_MAX_SIZE + 1] = "";
            strcpy(res, AdditionalFunciotns::handleHTMLcodes(buff));

            //set current field
            setFieldAtIndex(cols++, res);
        }

        //geting the close tag (read until '>')
        ifs.getline(buffClose, Constants::BUFFER_SIZE, Constants::SEPARATOR_RIGHT);

        //if it is a close tag, skip if there are spaces, new lines or other until the next '<'
        if (strcmp(buffClose, Constants::TH_CLOSE_TAG) == 0 || strcmp(buffClose, Constants::TD_CLOSE_TAG) == 0) {
            ifs.getline(buff, Constants::BUFFER_SIZE, Constants::SEPARATOR_LEFT);
        }
        //get the next tag
        ifs.getline(buff, Constants::BUFFER_SIZE, '>');

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

//save current row to file
void Row::saveRow(std::ofstream& ofs, size_t currentRowIndex, size_t colsCount) const {
    for (size_t i = 0; i < colsCount; i++) {
        if (headers[i]) {
            ofs << "   <th>" << getFieldAtIndex(i) << "</th>";
            ofs << std::endl;
        }
        else {
            ofs << "   <td>" << getFieldAtIndex(i) << "</td>";
            ofs << std::endl;
        }
    }
}