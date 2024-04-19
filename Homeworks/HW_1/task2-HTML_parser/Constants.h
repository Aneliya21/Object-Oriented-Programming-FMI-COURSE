#pragma once

namespace Constants {

    constexpr size_t BUFFER_SIZE = 1024;

    constexpr size_t FIELD_MAX_SIZE = 50; //after transf char entity ref

    constexpr size_t MAX_FIELDS_ROW = 15;
    constexpr size_t MAX_ROWS_SIZE = 100;

    constexpr size_t FILE_TO_READ_LENGTH = 64;

    //TAGS
    const char TH_OPEN_TAG[] = "th";
    const char TD_OPEN_TAG[] = "td";

    const char TH_CLOSE_TAG[] = "/th";
    const char TD_CLOSE_TAG[] = "/td";

    //SEPARATORS
    const char SEPARATOR_LEFT = '<';
    const char SEPARATOR_RIGHT = '>';

    //COMMANDS
    const char ADD[] = "add";
    const char REMOVE[] = "remove";
    const char EDIT[] = "edit";
    const char PRINT[] = "print";
    const char END[] = "end";

}