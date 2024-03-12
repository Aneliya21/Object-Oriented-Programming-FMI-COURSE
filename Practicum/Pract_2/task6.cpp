/*Създайте структура City, която описва град и има име (до 63 символа) и брой жители. 
Създайте и структура District, която съдържа в себе си до 20 града и пази текущия си размер.

Напишете функция, която записва във файл една област.
Напишете друга функция, която прочита област от файл, след което сортира градовете 
в областта според броя на жителите им във възходящ ред и записва резултата в друг файл.*/

#include <iostream>
#include <fstream>

struct City {
	char name[64] = "";
	unsigned countOfCitizens = 0;
};

void wirteCityToFile(const City& city, std::ofstream& ofs) {
	if (!ofs.is_open()) {
		std::cerr << "Error";
		return;
	}
	ofs << city.name;
	ofs << " ";
	ofs << city.countOfCitizens;
}

void readCityFromFile(City& city, std::ifstream& ifs) {
	if (!ifs.is_open()) {
		std::cerr << "Error";
		return;
	}
	ifs >> city.name;
	ifs.ignore();
	ifs >> city.countOfCitizens;
	ifs.ignore();
}

void printCity(const City& city) {
	std::cout << "Name: " << city.name << ", Count of citizens: " << city.countOfCitizens << std::endl;
}

struct District {
	City cities[20];
	unsigned currCount = 0;
};

void writeDistrictToFile(const District& distr, const char* filename) {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) {
		std::cerr << "Error";
		return;
	}
	ofs << distr.currCount;
	ofs << std::endl;
	for (unsigned i = 0; i < distr.currCount; i++) {
		wirteCityToFile(distr.cities[i], ofs);
		ofs << std::endl;
	}
	ofs.close();
}

void readDistrictFromFile(District& distr, const char* filename) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cerr << "Error";
		return;
	}
	ifs >> distr.currCount;
	ifs.ignore();
	for (unsigned i = 0; i < distr.currCount; i++) {
		readCityFromFile(distr.cities[i], ifs);
	}
	ifs.close();
}

void swapCities(City& city1, City& city2) {
	City temp = city1;
	city1 = city2;
	city2 = temp;
}

void sortCitiesByCountOfCitizens(District& distr) {
	for (unsigned i = 0; i < distr.currCount - 1; i++) {
		unsigned min = i;
		for (unsigned j = i + 1; j < distr.currCount; j++) {
			if (distr.cities[j].countOfCitizens < distr.cities[min].countOfCitizens)
				min = j;
		}
		if (min != i) {
			swapCities(distr.cities[i], distr.cities[min]);
		}
	}
}

void printDistrict(const District& distr) {
	std::cout << distr.currCount << std::endl;
	for (unsigned i = 0; i < distr.currCount; i++) {
		printCity(distr.cities[i]);
	}
}

int main() {
	City city1{ "sofia", 200 };
	City city2{ "plovdiv", 150 };
	City city3{ "istambul", 360 };
	District distr{ {city1, city2, city3}, 3 };
	writeDistrictToFile(distr, "file.txt");
	
	readDistrictFromFile(distr, "file.txt");

	sortCitiesByCountOfCitizens(distr);

	writeDistrictToFile(distr, "sorted.txt");
}