#pragma once
#include "Time.h"

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

public:
    Song() = default;

    Song(const char* name, unsigned hours, unsigned mins, unsigned seconds,
        const char* genre, const char* content);

    void setName(const char* name);
    void setDuration(unsigned hours, unsigned mins, unsigned seconds);
    void setGenre(const char* genre);
    void setContent(const char* content);

    const char* getName() const;
    const Time& getDuration() const;
    char getGenre() const;
    const char* getContent() const;

    //0010 1011 | 0110 1001 | 0110 1100 ,2
    //           
    //to edit!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void addRithm(unsigned bit);

    char* readContentFromBinaryFile(const char* fileName)  const;

    void saveSongToFile(std::ofstream& ofs) const;

    void printGenre() const;

    void printSong() const;

    bool compareDurations(const Time& first, const Time& second) const;
};

