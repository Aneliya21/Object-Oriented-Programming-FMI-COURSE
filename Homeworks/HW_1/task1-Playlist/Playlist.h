#pragma once
#include "Song.h"

class Playlist {

private:

    Song songs[Constants::MAX_SONGS_COUNT];
    size_t currentCount = 0;


    void swapSongs(Song& s1, Song& s2);

    bool isSongInPlaylist(const Song& song) const;

    void sortPlaylist(bool(*isLess)(const Song& first, const Song& second));

    int getIndexInListByName(const char* name) const;

public:

    Playlist() = default;

    void addToPlaylist(const char* name, unsigned hours, unsigned mins, unsigned seconds,
        const char* genre, const char* fileNameToReadContent);

    void printPlaylist() const;

    void searchByName(const char* name) const;
    void searchByGenre(char ch)  const;

    void sortByName();
    void sortByDuration();

    void addRithmToSongByName(const char* name, unsigned bit);
    void mix(const char* first, const char* second);

    void serializeSongByNameToBinaryFile(const char* songName, const char* fileName) const;
};

