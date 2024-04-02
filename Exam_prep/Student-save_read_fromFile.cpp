#include <iostream>
#include <fstream>

#pragma warning (disable: 4996)

namespace Consts {
	constexpr unsigned MAX_NAME_LEN = 22;

	constexpr size_t stCount = 4;
}

namespace Funcs {
	bool isLower(char ch) {
		return ch >= 'a' && ch <= 'z';
	}

	bool areAllLower(const char* str) {
		if (!str) {
			return false;
		}

		while (*str) {
			if (!isLower(*str)) {
				return false;
			}
			str++;
		}
		return true;
	}
	bool isUpper(char ch) {
		return ch >= 'A' && ch <= 'Z';
	}

	size_t getFileSize(std::ifstream& ifs) {
		size_t currentPos = ifs.tellg();
		ifs.seekg(0, std::ios::end);

		size_t fileSize = ifs.tellg();
		ifs.seekg(currentPos);

		return fileSize;
	}
}

struct Student {
	char name[Consts::MAX_NAME_LEN + 1] = "";
	bool isMale = false;
	unsigned fn = 0;
};

bool isNameValid(const char* name) {
	if (!name || strlen(name) > Consts::MAX_NAME_LEN) {
		return false;
	}
	return (Funcs::isUpper(*name) && Funcs::areAllLower(name + 1));
}

void initStudent(Student& st, const char* name, bool isMale, unsigned fn) {
	if (isNameValid(name)) {
		strcpy(st.name, name);
	}
	else {
		strcpy(st.name, "Unknown");
	}
	st.isMale = isMale;
	st.fn = fn;
}

void writeToBinaryFile(const Student* st, size_t count, const char* fileName) {
	if (!fileName) {
		return;
	}

	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open()) {
		return;
	}

	ofs.write((const char*)st, count * sizeof(Student));

	ofs.close();
}

void readFromBinaryFile(Student*& st, size_t& count, const char* fileName) {
	if (!fileName) {
		return;
	}

	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open()) {
		return;
	}

	size_t fileSize = Funcs::getFileSize(ifs);
	count = fileSize / sizeof(Student);

	st = new Student[count];

	ifs.read((char*)st, fileSize);

	ifs.close();
}



int main() {
	Student* ptr = new Student[Consts::stCount];
	initStudent(ptr[0], "Ivan", true, 12345);
	initStudent(ptr[1], "Alex", true, 12353);
	initStudent(ptr[2], "Petur", true, 53241);
	initStudent(ptr[3], "Aneliya", false, 21122);

	writeToBinaryFile(ptr, Consts::stCount, "students.dat");

	delete[] ptr;


	Student* arr;
	size_t count;
	
	readFromBinaryFile(arr, count, "students.dat");

	for (int i = 0; i < count; i++)
		std::cout << "Name: " << arr[i].name << ", fn: " << arr[i].fn << ", is male: " << arr[i].isMale << std::endl;

	delete[] arr;

	return 0;
}