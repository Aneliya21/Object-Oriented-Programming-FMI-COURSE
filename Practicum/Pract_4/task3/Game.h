/*Task
Имплементирайте клас Game, който съдържа следните член-данни (полета): 
		title, price, isAvailable. 
Член-данната title е от тип символен низ с максимална дължина 64.

Бележка. 
	В реалните софтуерни продукти не се използват floating-point числа, за да се моделират пари и други данни, изискващи прецизност. 
	Тук го моделираме по този начин за целите на упражнението.

Нека Game да съдържа:

	Конструктор по подразбиране.
	Параметризирани конструктори
	Селектори (getter)
	Мутатори (setter)
	isFree() - връща информация дали играта е безплатна
	print() - отпечатва информация за играта в подходящ формат

Проектирайте клас GamePlatform (платформа за игри).
Целта му е да съдържа библиотека от игри (Games).

За да работим с GamePlatform, се нуждаем от следните функции:

Добавяне на игра, ако има място.
Извеждане на игра по индекс.
Извеждане на списък с всички игри в платформата.
Извеждане на най-евтината / скъпата игра в платформата.
Извеждане на всички безплатни игри.
Премахване на игра от библиотеката.
Възможност за запазване на данните от платформата във файл (human-readable).
Възможност за изчитане на данните от файл (human-readable) и запазване в платформата за игри.
*/

#include <iostream>
#include <fstream>

#pragma warning (disable : 4996)

class Game {
	char title[64] = "";
	double price = 0.0;
	bool isAvailable = false;

public:
	Game() = default;
	Game(const char* title, double price, bool isAvailable);

	void setTitle(const char* title);
	void setPrice(double price);
	void setIsAvailable(bool isAvailable);

	const char* getTitle() const;
	double getPrice() const;
	bool getIsAvailable() const;

	bool isFree() const;
	void print() const;

	void save(std::ofstream& ifs) const;
};