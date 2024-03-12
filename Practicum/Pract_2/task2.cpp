/*Напишете програма, която прочита от текстов файл дължината на списък от числа 
и после самите числа (до 64 броя), и извежда на екрана най-често срещаното число.*/

#include <iostream>
#include <fstream>

int* getArrayOfNumbers(const char* filename, size_t& size) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		return nullptr;
	}
	size_t sizeOfArray = 0;
	ifs >> sizeOfArray;
	size = sizeOfArray;
	int* result = new int[sizeOfArray];
	int currNumber = 0;
	for (size_t i = 0; i < sizeOfArray; i++) {
		ifs >> currNumber;
		result[i] = currNumber;
	}
	ifs.close();
	return result;
}

size_t getCountOfOccur(const int* nums, size_t size, int current) {
	size_t count = 0;
	for (size_t i = 0; i < size; i++) {
		if (current == nums[i]) {
			count++;
		}
	}
	return count;
}

int getMostCommonNumber(const int* nums, size_t size) {
	int mostCommon = nums[0];
	size_t currOccur = 0;
	size_t mostOccur = getCountOfOccur(nums, size, mostCommon);
	for (size_t i = 1; i < size; i++) {
		currOccur = getCountOfOccur(nums, size, nums[i]);
		if (currOccur > mostOccur) {
			mostOccur = currOccur;
			mostCommon = nums[i];
		}
	}
	return mostCommon;
}

int main() {
	size_t size = 0;
	
	int* arr = getArrayOfNumbers("task2.txt", size);
	std::cout << getMostCommonNumber(arr, size);

	delete[] arr;

}