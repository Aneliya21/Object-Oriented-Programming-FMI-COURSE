/*Да се напише функция, която чете от конзолата 2 числа и 
записва във файл с име result1.txt сумата и разликата им. 
Да се напише функция, която чете от файла result1.txt сумата
и разликата на двете числа и отпечатва на конзолата кои са били оригиналните числа.*/

#include <iostream>
#include <fstream>


int main() {
	int num1 = 0, num2 = 0;
	std::cin >> num1 >> num2;
	std::ofstream ofs("result.txt");
	if (!ofs.is_open()) {
		return 0;
	}
	ofs << num1 + num2 << std::endl;
	ofs << num1 - num2;

	ofs.close();

	std::ifstream ifs("result.txt");
	if (!ifs.is_open()) {
		return 0;
	}
	int num1_1, num2_2;
	ifs >> num1_1 >> num2_2;
	std::cout << num1_1 << " " << num2_2;
	ifs.close();
}
