/*Напишете клас Teacher, която описва преподавател. Класът трябва да съдържа:

Име (с фиксирана дължина)
Възраст (число от 18 до 70)
Предмет (enum с учебни предмети)
Заплата (положително число над 500 лева)
Създайте подходящи конструктори, get и set член-функции.*/

#include <iostream>
#include <fstream>

#pragma warning (disable : 4996)

namespace Constants {
	constexpr unsigned NAME_LEN = 64;
}

enum class Subjects {
	UP,
	OOP,
	DiscreetMath,
	Algebra,
	Other
};

class Teacher {
private:
	char name[Constants::NAME_LEN + 1];
	unsigned age;
	Subjects subject;
	double salary;

public:
	Teacher() : name(""), age(18), subject(Subjects::Other), salary(0.0) {}
	Teacher(const char* name, unsigned age, Subjects subject, double salary) {
		setName(name);
		setAge(age);
		setSubject(subject);
		setSalary(salary);
	}
	void setName(const char* name) {
		if (!name || strlen(name) > 64) {
			return;
		}
		strcpy(this->name, name);
	}
	void setAge(unsigned age) {
		if (age < 18 || age >70) {
			return;
		}
		this->age = age;
	}
	void setSubject(Subjects subject) {
		this->subject = subject;
	}
	void setSalary(double salary) {
		if (salary <= 500) {
			return;
		}
		this->salary = salary;
	}

	const char* getName() const {
		return name;
	}
	unsigned getAge() const {
		return age;
	}
	Subjects getSubject() const {
		return subject;
	}
	double getSalary() const {
		return salary;
	}
};

int main() {

}