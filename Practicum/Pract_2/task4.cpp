/*Напишете програма, която отваря два текстови файла и сравнява техните съдържания, 
извеждайки на екрана първия ред, на който двата файла се различават.*/

#include <iostream>
#include <fstream>

void compareTextFiles(const char* fileName1, const char* fileName2) {
    std::ifstream first(fileName1);
    if (!first.is_open()) {
        std::cout << "Error, file1" << std::endl;
        return;
    }
    std::ifstream second(fileName2);
    if (!second.is_open()) {
        first.close();
        std::cout << "Error, file2" << std::endl;
        return;
    }
    while (!first.eof() || !second.eof()) {
        char buffFirst[1024];
        char buffSecond[1024];
        first.getline(buffFirst, 1024);
        second.getline(buffSecond, 1024);
        if (strcmp(buffFirst, buffSecond) != 0) {
            std::cout << buffFirst;
            return;
        }
    }
}

int main() {
    compareTextFiles("text1.txt", "text2.txt");
}
