#include "Playlist.h"

void Playlist::swapSongs(Song& s1, Song& s2) {
    Song temp = s1;
    s1 = s2;
    s2 = temp;
}

bool Playlist::isSongInPlaylist(const Song& song) const {
    for (size_t i = 0; i < currentCount; i++) {
        if (songs[i].getName() != song.getName()) {
            return false;
        }
    }
    return true;
}

void Playlist::sortPlaylist(bool(*isLess)(const Song& first, const Song& second)) {
    for (size_t i = 0; i < currentCount - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < currentCount; j++) {
            if (isLess(songs[j], songs[min])) {
                min = j;
            }
        }
        if (min != i) {
            swapSongs(songs[min], songs[i]);
        }
    }
}

void Playlist::addToPlaylist(const char* name, unsigned hours, unsigned mins, unsigned seconds,
    const char* genre, const char* fileNameToReadContent) {
    if (currentCount >= Constants::MAX_SONGS_COUNT) {
        return;
    }

    Song toAdd;

    char* contentOfSong = toAdd.readContentFromBinaryFile(fileNameToReadContent);

    toAdd.setContent(contentOfSong);
    toAdd.setName(name);
    toAdd.setDuration(hours, mins, seconds);
    toAdd.setGenre(genre);

    songs[currentCount++] = toAdd;
}

void Playlist::printPlaylist() const {
    for (size_t i = 0; i < currentCount; i++) {
        songs[i].printSong();
    }
}

int Playlist::getIndexInListByName(const char* name) const {
    for (size_t i = 0; i < currentCount; i++) {
        if (strcmp(songs[i].getName(), name) == 0) {
            return i;
        }
    }
    return -1;
}
void Playlist::searchByName(const char* name) const {
    for (size_t i = 0; i < currentCount; i++) {
        if (strcmp(songs[i].getName(), name) == 0) {
            songs[i].printSong();
        }
    }
    return;
}
void Playlist::searchByGenre(char ch)  const {

    Genre genre;
    switch (ch) {
    case 'r': genre = Genre::Rock; break;
    case 'p': genre = Genre::Pop; break;
    case 'j': genre = Genre::Jazz; break;
    case 'h': genre = Genre::HipHop; break;
    case 'e': genre = Genre::Electric; break;
    default: return;
    }

    for (size_t i = 0; i < currentCount; i++) {
        if ((songs[i].getGenre() & genre) == genre) {
            songs[i].printSong();
        }
    }

    return;
}

void Playlist::sortByName() {
    sortPlaylist([](const Song& first, const Song& second)
        { return strcmp(first.getName(), second.getName()) < 0; });
}
void Playlist::sortByDuration() {
    sortPlaylist([](const Song& first, const Song& second)
        { return  first.compareDurations(first.getDuration(), second.getDuration()); });
}

void Playlist::addRithmToSongByName(const char* name, unsigned bit) {
    if (!name || bit > 8) {
        return;
    }

    int songIndex = getIndexInListByName(name);
    if (songIndex == -1) {
        return;
    }
    songs[songIndex].addRithm(bit);
}
void Playlist::mix(const char* first, const char* second) {

    int firstIndex = getIndexInListByName(first);
    int secondIndex = getIndexInListByName(second);

    if (firstIndex == 1 || secondIndex == -1) {
        return;
    }

    size_t baseContentLen = strlen(songs[firstIndex].getContent());
    size_t mixWithContentLen = strlen(songs[secondIndex].getContent());

    size_t minContentLen = (baseContentLen < mixWithContentLen) ?
        baseContentLen : mixWithContentLen;

    char tempContent[Constants::MAX_CONTENT_LEN + 1];
    strcpy(tempContent, songs[firstIndex].getContent());

    size_t index = 0;
    while (index < minContentLen) {
        tempContent[index++] ^= songs[secondIndex].getContent()[index];
    }

    if (index + 1 < baseContentLen) {
        while (index < baseContentLen) {
            tempContent[index++] = songs[firstIndex].getContent()[index];
        }
    }

    songs[firstIndex].setContent(tempContent);
}

void Playlist::serializeSongByNameToBinaryFile(const char* songName, const char* fileName) const {
    if (!songName || !fileName || (getIndexInListByName(songName) == -1)) {
        return;
    }

    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open()) {
        return;
    }

    int songIndex = getIndexInListByName(songName);

    songs[songIndex].saveSongToFile(ofs);
}