/*Напишете програма, която отпечатва собствения си код.*/

#include <iostream>
#include <fstream>

int main() {
	std::ifstream ifs("pract_2_task_3.cpp");
	if (!ifs.is_open()) {
		std::cout << "Error";
		return 0;
	}
	while (!ifs.eof()) {
		char buff[1024];
		ifs.getline(buff, 1024);
		std::cout << buff << std::endl;
	}

	ifs.close();
}