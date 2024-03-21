#include "Song.h"

void Song::addRithmToByte(unsigned bit, char& current) {
    unsigned mask = 0;
    unsigned iter = 1;

    while (mask <= Constants::MAX_CONTENT_LEN) {
        mask = AdditionalFunctions::powerOfTwo(iter++);

        if (iter % bit == 0) {
            current |= mask;
        }
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

//0010 1011 | 0110 1001 | 0110 1100 ,2
    //           
    //to edit!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Song::addRithm(unsigned bit) {
    size_t contentLen = strlen(content);
    /*for (size_t i = 0; i < contentLen; i++) {
        addRithmToByte(bit, content[i]);
    }*/
    for (int i = contentLen - 1; i >= 0; i--) {
        addRithmToByte(bit, content[i]);
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
        << duration.getSeconds() << ", " << genre << ", " << content << std::endl;;
}

void Song::printGenre() const {

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