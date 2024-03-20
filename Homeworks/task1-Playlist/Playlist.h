#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

#pragma warning (disable:4996)

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

namespace AdditionalFunctions {
    unsigned powerOfTwo(unsigned n);
    /*unsigned powerOfTwo(unsigned n) {
        return 1 << n;
    }*/
    size_t getFileSize(std::ifstream&);
    /*size_t getFileSize(std::ifstream& ifs) {
        size_t currentPosition = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t fileSize = ifs.tellg();
        ifs.seekg(currentPosition);

        return fileSize;
    }*/
}

class Time {

private:
    unsigned secondsFromMidnight;

    bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldVlaue, unsigned multiplier);
    /*bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldVlaue, unsigned multiplier) {
        if (newValue >= lowerBound && newValue <= upperBound) {
            (secondsFromMidnight -= (oldVlaue * multiplier)) += (newValue * multiplier);
            return true;
        }
        else
            return false;
    }*/

public:

    Time();
    /*Time() : secondsFromMidnight(0) {}*/
    Time(unsigned hours, unsigned mins, unsigned seconds); 
    /* {
        setHours(hours);
        setMins(mins);
        setSeconds(seconds);
    }*/

    unsigned getHours() const;
    /* {
        return secondsFromMidnight / Constants::SECONDS_IN_HOURS;
    }*/
    unsigned getMins() const;
    /* {
        return (secondsFromMidnight / 60) % 60;
    }*/
    unsigned getSeconds() const;
    /* {
        return secondsFromMidnight % 60;
    }*/

    unsigned getSecondsFromMidnight() const;
    /* {
        return secondsFromMidnight;
    }*/

    bool setHours(unsigned hours);
    /* {
        return validateAndSet(0, 23, hours, getHours(), Constants::SECONDS_IN_HOURS);
    }*/
    bool setMins(unsigned mins);
    /* {
        return validateAndSet(0, 59, mins, getMins(), Constants::SECONDS_IN_MINUTE);
    }*/
    bool setSeconds(unsigned seconds);
    /* {
        return validateAndSet(0, 59, seconds, getSeconds(), 1);
    }*/

    void serialize(std::ostream& os) const;
    /* {
        os << std::setw(2) << std::setfill('0') << getHours() << ":"
            << std::setw(2) << std::setfill('0') << getMins() << ":"
            << std::setw(2) << std::setfill('0') << getSeconds() << std::endl;
    }*/

    void printTime() const;
    /* {
        std::cout << std::setw(2) << std::setfill('0') << getHours() << ":"
            << std::setw(2) << std::setfill('0') << getMins() << ":"
            << std::setw(2) << std::setfill('0') << getSeconds();
    }*/
};

enum Genre : char {
    Rock = 1,  //0000 0001
    Pop = 2,  //0000 0010
    Jazz = 4, //0000 0100
    HipHop = 8,  //0000 1000
    Electric = 16, //0001 0000
};

class Song {

private:
    char name[Constants::MAX_NAME_LEN + 1] = "";
    Time duration;
    char genre;
    char content[Constants::MAX_CONTENT_LEN + 1] = "";

    void addRithmToByte(unsigned bit, char& current);
    /* {
        unsigned mask = 0;
        unsigned iter = 1;

        while (mask <= Constants::MAX_CONTENT_LEN) {
            mask = AdditionalFunctions::powerOfTwo(iter++);

            if (iter % bit == 0) {
                current |= mask;
            }
        }
    }*/

public:
    Song() = default;

    Song(const char* name, unsigned hours, unsigned mins, unsigned seconds,
        const char* genre, const char* content);
    /* {
        setName(name);
        setDuration(hours, mins, seconds);
        setGenre(genre);
        setContent(content);
    }*/

    void setName(const char* name);
        /* {
            if (!name || strlen(name) > Constants::MAX_NAME_LEN) {
                return;
            }
            strcpy(this->name, name);
        }*/
    void setDuration(unsigned hours, unsigned mins, unsigned seconds); 
    /* {
    duration.setHours(hours);
    duration.setMins(mins);
    duration.setSeconds(seconds);
    }*/

    void setGenre(const char* genre);
    /* {
        if (!genre || strlen(genre) > 5) {
            return;
        }

        this->genre = NULL;

        while (*genre) {
            if (*genre == Constants::ROCK_GENRE) {
                this->genre |= Genre::Rock;
                genre++;
                continue;
            }
            else if (*genre == Constants::POP_GENRE) {
                this->genre |= Genre::Pop;
                genre++;
                continue;
            }
            else if (*genre == Constants::JAZZ_GENRE) {
                this->genre |= Genre::Jazz;
                genre++;
                continue;
            }
            else if (*genre == Constants::HIP_HOP_GENRE) {
                this->genre |= Genre::HipHop;
                genre++;
                continue;
            }
            else if (*genre == Constants::ELECTRIC_GENRE) {
                this->genre |= Genre::Electric;
                genre++;

            }
            return;
        }
    }*/
    void setContent(const char* content);
    /* {
        strcpy(this->content, content);
    }*/

    const char* getName() const;
    /* {
        return this->name;
    }*/
    const Time& getDuration() const;
    /* {
        return this->duration;
    }*/
    char getGenre() const;
    /* {
        return this->genre;
    }*/
    const char* getContent() const;
    /* {
        return this->content;
    }*/

    //0010 1011 | 0110 1001 | 0110 1100 ,2
    //           
    //to edit!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void addRithm(unsigned bit);
    /* {
        size_t contentLen = strlen(content);
        for (size_t i = 0; i < contentLen; i++) {
            addRithmToByte(bit, content[i]);
        }
        for (int i = contentLen - 1; i >= 0; i--) {
            addRithmToByte(bit, content[i]);
        }
    }*/

    char* readContentFromBinaryFile(const char* fileName)  const;
    /* {
        if (!fileName) {
            return nullptr;
        }

        std::ifstream ifs(fileName, std::ios::binary);
        if (!ifs.is_open()) {
            return nullptr;
        }

        size_t fileSize = 0;
        fileSize = AdditionalFunctions::getFileSize(ifs);
        if (fileSize > Constants::MAX_NAME_LEN) {
            return nullptr;
        }

        char buffer[Constants::MAX_CONTENT_LEN + 1];
        buffer[fileSize] = '\0';

        ifs.read((char*)buffer, fileSize);

        ifs.close();

        return buffer;
    }*/

    void saveSongToFile(std::ofstream& ofs) const;
    /* {
        if (!ofs.is_open()) {
            return;
        }
        ofs << name << ", " << duration.getHours() << ", " << duration.getMins() << ", "
            << duration.getSeconds() << ", " << genre << ", " << content << std::endl;;
    }*/

    void printGenre() const;
    /* {

        if ((genre & Genre::Rock) == Genre::Rock) {
            std::cout << "Rock&";
        }
        if ((genre & Genre::Pop) == Genre::Pop) {
            std::cout << "Pop&";
        }
        if ((genre & Genre::Jazz) == Genre::Jazz) {
            std::cout << "Jazz&";
        }
        if ((genre & Genre::HipHop) == Genre::HipHop) {
            std::cout << "HipHop&";
        }
        if ((genre & Genre::Electric) == Genre::Electric) {
            std::cout << "Electric&";
        }
    }*/

    void printSong() const;
    /* {
        std::cout << "Name: " << name << ", ";
        std::cout << "Duration: ";
        //std::cout << duration.getHours() << ":" << duration.getMins() << ":" << duration.getSeconds();
        duration.printTime();
        std::cout << ", ";
        std::cout << "Genre: ";
        printGenre();
        std::cout << ", ";
        std::cout << "Content: " << content << std::endl;
    }*/

    bool compareDurations(const Time& first, const Time& second) const;
    /* {       //if first is less return true
        return first.getSecondsFromMidnight() < second.getSecondsFromMidnight();
    }*/
};

class Playlist {

private:

    Song songs[Constants::MAX_SONGS_COUNT];
    size_t currentCount = 0;

    void swapSongs(Song& s1, Song& s2);
    /* {
        Song temp = s1;
        s1 = s2;
        s2 = temp;
    }*/

    bool isSongInPlaylist(const Song& song) const;
    /* {
        for (size_t i = 0; i < currentCount; i++) {
            if (songs[i].getName() != song.getName()) {
                return false;
            }
        }
        return true;
    }*/

    void sortPlaylist(bool(*isLess)(const Song& first, const Song& second));
    /* {
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
    }*/

    //Genre getGenreFromChar(char ch) {
    //}

public:

    Playlist() {}

    void addToPlaylist(const char* name, unsigned hours, unsigned mins, unsigned seconds,
        const char* genre, const char* fileNameToReadContent);
    /* {
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
    }*/

    void printPlaylist() const;
    /* {
        for (size_t i = 0; i < currentCount; i++) {
            songs[i].printSong();
        }
    }*/

    int getIndexInListByName(const char* name) const;
    /* {
        for (size_t i = 0; i < currentCount; i++) {
            if (strcmp(songs[i].getName(), name) == 0) {
                return i;
            }
        }
        return -1;
    }*/
    void searchByName(const char* name) const;
    /* {
        for (size_t i = 0; i < currentCount; i++) {
            if (strcmp(songs[i].getName(), name) == 0) {
                songs[i].printSong();
            }
        }
        return;
    }*/
    void searchByGenre(char ch)  const;
    /* {

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
    }*/

    void sortByName();
    /* {
        sortPlaylist([](const Song& first, const Song& second)
            { return strcmp(first.getName(), second.getName()) < 0; });
    }*/
    void sortByDuration();
    /* {
        sortPlaylist([](const Song& first, const Song& second)
            { return  first.compareDurations(first.getDuration(), second.getDuration()); });
    }*/

    void addRithmToSongByName(const char* name, unsigned bit);
    /* {
        if (!name || bit > 8) {
            return;
        }

        int songIndex = getIndexInListByName(name);
        if (songIndex == -1) {
            return;
        }
        songs[songIndex].addRithm(bit);
    }*/
    void mix(const char* first, const char* second);
    /* {

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
    }*/

    void serializeSongByNameToBinaryFile(const char* songName, const char* fileName) const;
    /* {
        if (!songName || !fileName || (getIndexInListByName(songName) == -1)) {
            return;
        }

        std::ofstream ofs(fileName, std::ios::binary);
        if (!ofs.is_open()) {
            return;
        }

        int songIndex = getIndexInListByName(songName);

        songs[songIndex].saveSongToFile(ofs);
    }*/
};