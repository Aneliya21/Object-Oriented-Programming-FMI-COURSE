#include "LoggedUser.h"

LoggedUser::LoggedUser() {
    char password[MAX_PASS_LEN + 1];
    std::cin >> password;
    setPassword(password);
}

bool LoggedUser::levelUp() {
    if (getPoints() >= 2048) {
        levelUpBasedOnPoints(getPoints(), 2048, Stars::Five);
        return true;
    }
    else if (getPoints() >= 1024) {
        levelUpBasedOnPoints(getPoints(), 1024, Stars::Four);
        return true;
    }
    else if (getPoints() >= 512) {
        levelUpBasedOnPoints(getPoints(), 512, Stars::Three);
        return true;
    }
    else if (getPoints() >= 256) {
        levelUpBasedOnPoints(getPoints(), 256, Stars::Two);
        return true;
    }
    else {
        return false;
    }
}

bool LoggedUser::logIn(const char* password) {
    if (strcmp(this->password, password) == 0) {
        setLogged(true);
        return true;
    }
    return false;
}

void LoggedUser::setPassword(const char* newPassword) {
    if (strlen(newPassword) <= 8) {
        strcpy(password, newPassword);
    }
}
void LoggedUser::setLogged(bool isLogged) {
    logged = isLogged;
}