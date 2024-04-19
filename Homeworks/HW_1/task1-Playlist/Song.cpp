#include "Song.h"

//there is a problem with this function
char* Song::getGenreString() const {
    char result[Constants::MAX_NAME_LEN + 1] = ""; //the result string should be a pointer to the heap because the function returns char* !!!
    result[Constants::MAX_NAME_LEN] = '\0';

    size_t resultLen = 0;

    if ((genre & Genre::Rock) == Genre::Rock) {
        strcat(result, "Rock&");
        resultLen += 5;
    }
    if ((genre & Genre::Pop) == Genre::Pop) {
        strcat(result, "Pop&");
        resultLen += 4;
    }
    if ((genre & Genre::Jazz) == Genre::Jazz) {
        strcat(result, "Jazz&");
        resultLen += 5;
    }
    if ((genre & Genre::HipHop) == Genre::HipHop) {
        strcat(result, "HipHop&");
        resultLen += 7;
    }
    if ((genre & Genre::Electric) == Genre::Electric) {
        strcat(result, "Electric&");
        resultLen += 9;
    }
    result[resultLen - 1] = '\0';
    return result;
}


void Song::addRithmToByte(unsigned bit, char& current, size_t& counter) {
    unsigned mask = 1;

    while (mask < Constants::MAX_CONTENT_LEN) {
        
        if (counter == bit) {          
            current |= mask;
            counter = 0;
        }

        counter++;        
        mask <<= 1;
    }
}

Song::Song(const char* name, unsigned hours, unsigned mins, unsigned seconds,
    const char* genre, const char* content) {
    setName(name);
    setDuration(hours, mins, seconds);
    setGenre(genre);
    setContent(content);
}

void Song::setName(const char* name) {
    if (!name || strlen(name) > Constants::MAX_NAME_LEN) {
        return;
    }
    strcpy(this->name, name);
}
void Song::setDuration(unsigned hours, unsigned mins, unsigned seconds) {
    duration.setHours(hours);
    duration.setMins(mins);
    duration.setSeconds(seconds);
}
void Song::setGenre(const char* genre) {
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
}
void Song::setContent(const char* content) {
    strcpy(this->content, content);
}

const char* Song::getName() const {
    return this->name;
}
const Time& Song::getDuration() const {
    return this->duration;
}
char Song::getGenre() const {
    return this->genre;
}
const char* Song::getContent() const {
    return this->content;
} 

void Song::addRithm(unsigned bit) {
    size_t contentLen = strlen(content);
    size_t counter = 1;
    
    for (int i = contentLen - 1; i >= 0; i--) {
        addRithmToByte(bit, content[i], counter);     
    }
}

char* Song::readContentFromBinaryFile(const char* fileName)  const {
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
}

void Song::saveSongToFile(std::ofstream& ofs) const {
    if (!ofs.is_open()) {
        return;
    }
    ofs << name << ", " << duration.getHours() << ", " << duration.getMins() << ", "
        << duration.getSeconds() << ", ";
    /*if ((genre & Genre::Rock) == Genre::Rock) {
        ofs << "Rock&";
    }
    if ((genre & Genre::Pop) == Genre::Pop) {
        ofs << "Pop&";
    }
    if ((genre & Genre::Jazz) == Genre::Jazz) {
        ofs << "Jazz&";
    }
    if ((genre & Genre::HipHop) == Genre::HipHop) {
        ofs << "HipHop&";
    }
    if ((genre & Genre::Electric) == Genre::Electric) {
        ofs << "Electric&";
    }*/
    char genreString[Constants::MAX_NAME_LEN + 1];
    strcpy(genreString, getGenreString());
    ofs << genreString;
    ofs << ", " << content << std::endl;;
}

void Song::printGenre() const {

    /*if ((genre & Genre::Rock) == Genre::Rock) {
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
    }*/
    char genreString[Constants::MAX_NAME_LEN + 1];
    strcpy(genreString, getGenreString());
    std::cout << genreString;
}

void Song::printSong() const {
    std::cout << "Name: " << name << ", ";
    std::cout << "Duration: ";
    duration.printTime();
    std::cout << ", ";
    std::cout << "Genre: ";
    printGenre();
    std::cout << std::endl;
    /*std::cout << ", ";
    std::cout << "Content: " << content << std::endl;*/
}

bool Song::compareDurations(const Time& first, const Time& second) const {       //if first is less return true
    return first.getSecondsFromMidnight() < second.getSecondsFromMidnight();
}
