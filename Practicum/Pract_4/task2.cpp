/*
Стойчо, подготвяйки задачите за контролното по ООП, реши, че е добра идея да внимава точно как пише задачите.
Всеки можеше да отвори лаптопа му и да открадне тази безценна информация.
Помогнете на Стойчо да опази задачите от изпита - създайте клас Secret.
Класът трябва да съдържа:
	Условие на задачата
	Парола
	Брой неуспешни влизания
	Направете подходящи конструктори.

Да се напише функция getTask(const char*pwd), която връща условието тогава и само тогава когато сме въвели правилната парола.
Да се напише функция setPassword(const char* newPassword, const char* oldPassword), която променя паролата, но само ако сме въвели правилно старата парола.
Да се напише функция setTask(const char* newTask, const char* passwd), която променя условието на задачата ако сме въвели правилна парола.
Да се напише функция getLoginFails(), която връща броя на неуспешните влизания.
	Всеки път когато сме въвели неправилна парола броят на неуспешните влизания се увеличава. 
*/

#include <iostream>
#include <fstream>

#pragma warning (disable:4996)

class Secret {
	char task[64] = "";
	char password[64] = "pass";
	mutable unsigned unsuccessfulLogs = 0;

public:
	Secret(const char* task, const char* newPassword, const char* oldPassword);
	Secret(const char* task, const char* password);

	const char* getTask(const char* password) const;

	void setPassword(const char* newPassword, const char* oldPassword);

	void setTask(const char* newTask, const char* password);

	unsigned getLogInFails() const;
};

Secret::Secret(const char* task, const char* newPassword, const char* oldPassword) {
	setTask(task, oldPassword);
	setPassword(newPassword, oldPassword);
}

Secret::Secret(const char* task, const char* password) {
	setTask(task, password);
}

const char* Secret::getTask(const char* password) const {
	if (strcmp(this->password, password) == 0) {
		return task;
	}
	this->unsuccessfulLogs++;
	std::cout << "Err";
	return "";
}

void Secret::setPassword(const char* newPassword, const char* oldPassword) {
	if (strcmp(this->password, oldPassword) == 0 
					&& strlen(newPassword) < 64) 
	{
		strcpy(this->password, newPassword);
		return;
	}
	this->unsuccessfulLogs++;
}

void Secret::setTask(const char* newTask, const char* password) {
	if (strcmp(this->password, password) == 0 
				&& strlen(newTask) < 64) 
	{
		strcpy(this->task, newTask);
		return;
	}
	this->unsuccessfulLogs++;
}

unsigned Secret::getLogInFails() const {
	return this->unsuccessfulLogs;
}

int main() {
	char task[] = "newTask";
	char pass[10];
	std::cin >> pass;
	Secret s(task, "newPass", pass);
	std::cin >> pass;
	std::cout << s.getTask(pass);
	std::cout << std::endl;
	std::cout << s.getLogInFails();
}