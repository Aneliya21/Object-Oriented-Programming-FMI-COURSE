#pragma once

namespace Constants {
    constexpr size_t MAX_NAME_LEN = 64;
    constexpr size_t MAX_CONTENT_LEN = 256;
    constexpr size_t MAX_SONGS_COUNT = 30;

    const char ROCK_GENRE = 'r';
    const char POP_GENRE = 'p';
    const char JAZZ_GENRE = 'j';
    const char HIP_HOP_GENRE = 'h';
    const char ELECTRIC_GENRE = 'e';

    constexpr unsigned SECONDS_IN_HOURS = 3600;
    constexpr unsigned SECONDS_IN_MINUTE = 60;
    constexpr unsigned DAY_SECONDS = 24 * 3600;
}