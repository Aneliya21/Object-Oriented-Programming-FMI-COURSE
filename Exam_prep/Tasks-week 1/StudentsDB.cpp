#include <iostream>
#include <assert.h>

enum class Major {
	Undef,
	Inf,
	Cs,
	S
};

const char* getMajor(Major m) {
	switch (m) {
	case Major::Inf:
		return "Inf";
	case Major::Cs:
		return "Cs";
	case Major::S:
		return "S";
	default:
		return "";
	}
}

struct Student {
	char name[100] = "";
	unsigned fn = 0;
	Major major = Major::Undef;
};

void printStudent(const Student& st) {
	std::cout << st.name << " " << st.fn << " " << getMajor(st.major) << std::endl;
}

const int STUDENTS_MAX_SIZE = 10;
struct StudentsDB {
	unsigned studentsCount = 0;
	Student students[STUDENTS_MAX_SIZE];
};

void printDB(const StudentsDB& db) {
	assert(db.studentsCount <= STUDENTS_MAX_SIZE);

	for (size_t i = 0; i < db.studentsCount; i++) {
		printStudent(db.students[i]);
	}
}

enum class Criteria {
	sortByName,
	sortByMajor,
	sortByFn
};

void sortDB(StudentsDB& db, bool(*isLess)(const Student& lhs, const Student& rhs)) {
	for (size_t i = 0; i < db.studentsCount - 1; i++) {
		size_t minInd = i;
		for (size_t j = i + 1; j < db.studentsCount; j++) {
			if (isLess(db.students[j], db.students[minInd])) {
				minInd = j;
			}
		}
		if (minInd != i) {
			std::swap(db.students[i], db.students[minInd]);
		}
	}
}

void sortByCriteria(StudentsDB& db, Criteria cr) {
	switch (cr) {
	case Criteria::sortByName: return sortDB(db, [](const Student& lhs, const Student& rhs) {return strcmp(lhs.name, rhs.name) < 0; });
	case Criteria::sortByMajor: return sortDB(db, [](const Student& lhs, const Student& rhs) {return lhs.major < rhs.major; });
	case Criteria::sortByFn: return sortDB(db, [](const Student& lhs, const Student& rhs) {return lhs.fn < rhs.fn; });

	}
}

int main() {
	StudentsDB db = { 3, {
			{"Petur", 12, Major::Inf},
			{"Ivan", 12345, Major::Cs},
			{"Aleksandur", 56, Major::S}
		} 
	};

	printDB(db);

	sortByCriteria(db, Criteria::sortByName);

	std::cout << std::endl;

	printDB(db);

	sortByCriteria(db, Criteria::sortByMajor);

	std::cout << std::endl;

	printDB(db);

	sortByCriteria(db, Criteria::sortByFn);

	std::cout << std::endl;

	printDB(db);
}