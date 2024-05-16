#pragma once
#include "Player.h"

constexpr unsigned MAX_PASS_LEN = 8;

class LoggedUser : Player {

public:
	LoggedUser();

	bool levelUp() override;

	bool logIn(const char* password);

protected:
	void setPassword(const char* newPassword);
	void setLogged(bool isLogged);

private:
	char password[MAX_PASS_LEN + 1];
	bool logged = false;
};

