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

size_t getCountOfStudentsWithScholarship(const Group& group, double minAvGradeForScholarship) {
	size_t res = 0;
	for (size_t i = 0; i < group.countOfStudents; i++) {
		if (group.students[i].averageGrade >= minAvGradeForScholarship) {
			res++;
		}
	}
	return res;
}

int main() {
	
}