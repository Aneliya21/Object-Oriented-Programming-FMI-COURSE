#include <iostream>

namespace HelperFunctions {
	size_t getCountOfDigitsInNumber(int number) {
		size_t size = 0;
		while (number != 0) {
			number /= 10;
			size++;
		}
		return size;
	}
	bool isNumberWithFiveDigits(int number) {
		return getCountOfDigitsInNumber(number) == 5;
	}
	bool isAverageGradeValid(double averageGrade) {
		return averageGrade >= 0 && averageGrade <= 6;
	}
}

enum Course {
	Undefined = 0,
	First = 1,
	Second = 2,
	Third = 3,
	Fourth = 4
};

struct Student {
	int fn = 0;
	Course course = Course::Undefined;
	double averageGrade = 0.0;
};

void setCourse(Student& student, int n) {
	switch (n) {
	case 1:
		student.course = Course::First;
	case 2:
		student.course = Course::Second;
	case 3:
		student.course = Course::Third;
	case 4:
		student.course = Course::Fourth;
	default:
		student.course = Course::Undefined;
	}
}

void initStudent(Student& student) {
	std::cin >> student.fn;
	while (!HelperFunctions::isNumberWithFiveDigits(student.fn)) {
		std::cerr << "Invalid faculty number!" << std::endl;
		std::cin >> student.fn;
	}

	int course;
	std::cin >> course;
	setCourse(student, course);

	std::cin >> student.averageGrade;
	while (!HelperFunctions::isAverageGradeValid(student.averageGrade)) {
		std::cerr << "Average grade is NOT valid!" << std::endl;
		std::cin >> student.averageGrade;
	}
}

void printStudent(const Student& student) {
	std::cout << "Faculty number: " << student.fn << ", "
		<< "Course: " << student.course << ", "
		<< "Average grade: " << student.averageGrade << std::endl;
}

struct Group {
	Student students[5];
	size_t countOfStudents = 5;
	double averageGradesOfGroup = 0.0;
};

void createGroup(Group& group) {
	double sum = 0;
	for (size_t i = 0; i < group.countOfStudents; i++) {
		initStudent(group.students[i]);
		sum += group.students[i].averageGrade;
	}
	group.averageGradesOfGroup = sum / group.countOfStudents;
}
void swapStudents(Student& st1, Student& st2) {
	Student temp = st1;
	st1 = st2;
	st2 = temp;
}

void sortStudentsWithScholarship(Student* st, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		size_t maxInd = i;
		for (size_t j = i + 1; j < size; j++) {
			if (st[j].averageGrade > st[maxInd].averageGrade) {
				maxInd = j;
			}
		}
		if (maxInd != i) {
			swapStudents(st[maxInd], st[i]);
		}
	}
}

Student* getCountOfStudentsWithScholarship(const Group& group, double minAvGradeForScholarship, size_t& sizeOfStudentsArray) {
	Student arr[5];
	size_t indexOfArr = 0;
	for (size_t i = 0; i < group.countOfStudents; i++) {
		if (group.students[i].averageGrade >= minAvGradeForScholarship) {
			arr[indexOfArr++] = group.students[i];
		}
	}
	sizeOfStudentsArray = indexOfArr + 1;
	sortStudentsWithScholarship(arr, sizeOfStudentsArray);
	return arr;
}

void printStudentsWithScholarships(const Student* st, size_t size) {
	for (size_t i = 0; i < size; i++) {
		printStudent(st[i]);
	}
}

int main() {
	Student st1 = { 12345, Course::First, 4.4 };
	Student st2 = { 12345, Course::First, 6 };
	Student st3 = { 42312, Course::First, 5 };
	Student st4 = { 53242, Course::First, 4.5 };
	Student st5 = { 65323, Course::First, 3.6 };

	Group gr{
		{st1, st2, st3, st4, st5},
		5, 4.7
	};
	size_t size = 0;
	printStudentsWithScholarships(getCountOfStudentsWithScholarship(gr, 4.5, size), 3);
}