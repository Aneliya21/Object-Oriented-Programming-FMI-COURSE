/*Да се създаде структура Pair, която представя наредена двойка от естествени числа. 
Да се създаде структура, която представя релация. В релацията има най-много 25 наредени двойки и структурата пази текущия си размер.

Да се създаде функция, която прочита релация от даден файл.
Да се напише функция, която добавя наредена двойка към релацията.
Да се създаде функция, която записва релацията в даден файл.*/

#include <iostream>
#include <fstream>

struct Pair {
	unsigned first = 0;
	unsigned second = 0;
};

void printPair(const Pair& p) {
	std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
}

struct Relation {
	Pair pairs[25]{ 0,0 };
	unsigned currentSize = 0;
};

Relation readRelation(const char* filename) {
	std::ifstream ifs(filename);
	Relation result{ {0,0},1 };
	if (!ifs.is_open()) {
		std::cerr << "Error";
		return result;
	}
	unsigned currInd = 0;
	while (!ifs.eof()) {
		Pair current;
		ifs >> current.first;
		ifs >> current.second;
		result.pairs[currInd++] = current;
	}
	result.currentSize = currInd;
	ifs.close();
	return result;
}

void addPairToRel(Relation& rel, const Pair& toAdd) {
	if (rel.currentSize >= 25) {
		std::cerr << "No space left";
		return;
	}
	rel.pairs[rel.currentSize++] = toAdd;
}

void printRelation(const Relation& rel) {
	for (unsigned i = 0; i < rel.currentSize; i++) {
		printPair(rel.pairs[i]);
	}
}

void writeRelation(const char* fileName, const Relation& toWrite) {
	std::ofstream ofs(fileName);
	if (!ofs.is_open()) {
		std::cerr << "Error";
		return;
	}
	for (unsigned i = 0; i < toWrite.currentSize; i++) {
		ofs << "(" << toWrite.pairs[i].first << "," << toWrite.pairs[i].second << ")" << std::endl;
	}
	ofs.close();
}

int main() {
	Relation rel;
	rel = readRelation("relations.txt");
	writeRelation("result.txt", rel);
	printRelation(rel);
}
