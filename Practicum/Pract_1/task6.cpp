/*Да се напише програма, която симулира изпълнение на тест.
Всеки тест представлява структура, съдържаща константен брой въпроси (вие изберете този брой).
Всеки въпрос има заглавие (до 50 символа), четири възможни отговора, верен отговор (може да е A, B, C или D),
и точки, които се дават за правилно отговорен въпрос.
Всеки отговор съдържа символен низ с до 50 символа.
Потребителят трябва да може да отговаря на въпросите, като избира една от четирите възможности.
След като потребителят отговори на всички въпроси, програмата да извежда общия брой точки, които е спечелил потребителят.*/

#include <iostream>

struct Question {
	char title[51] = "";
	char ans[4];
	char correctAns = '0';
	unsigned points = 2;
};

struct Test {
	Question questions[5];
	unsigned size = 5;
};

bool isValidAns(char correctAns) {
	return correctAns == 'A' || correctAns == 'B' || correctAns == 'C' || correctAns == 'D';
}

void initQuestion(Question& q) {
	std::cout << "Question title: ";
	std::cin >> q.title;
	while (strlen(q.title) > 50) {
		std::cerr << "Too many characters used for the title!" << std::endl;
		std::cout << "Question title: ";
		std::cin >> q.title;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 4; i++) {
		std::cout << "Answear " << i << ": ";
		std::cin>>q.ans[i];
		while (!isValidAns(q.ans[i])) {
			std::cerr << "Invalid answear!" << std::endl;
			std::cout << "Answear " << i << ": ";
			std::cin >> q.ans[i];
		}
	}
	std::cout << std::endl;

	std::cout << "Correct answear: ";
	std::cin >> q.correctAns;
	while (!isValidAns(q.correctAns)) {
		std::cerr << "Invalid answear!" << std::endl;
		std::cout << "Correct answear: ";
		std::cin >> q.correctAns;
	}
	std::cout << std::endl;

	std::cout << "Points: ";
	std::cin >> q.points;
	std::cout << std::endl;
}

void initTest(Test& test) {
	for (size_t i = 0; i < 5; i++) {
		std::cout << "Question: " << std::endl;
		initQuestion(test.questions[i]);
		std::cout << std::endl;
	}
}

unsigned testSimulator(const Test& test) {
	unsigned sumOfPoints = 0;
	char ans;
	for (size_t i = 0; i < 5; i++) {
		std::cout << test.questions[i].title << std::endl;
		std::cout << "Possible answears: " 
				<< test.questions[i].ans[0] << "), " 
				<< test.questions[i].ans[1] << "), " 
				<< test.questions[i].ans[2] << "), " 
				<< test.questions[i].ans[3] << "). " << std::endl;
		std::cout << "Your answear: ";
		std::cin >> ans;
		while (!isValidAns(ans)) {
			std::cerr << "Invalid caracter";
			std::cout << "Your answear: ";
			std::cin >> ans;
		}
		if (ans == test.questions[i].correctAns) {
			sumOfPoints += test.questions[i].points;
		}
	}
	return sumOfPoints;
}

int main() {
	Test t;
	initTest(t);
	std::cout << testSimulator(t);
}