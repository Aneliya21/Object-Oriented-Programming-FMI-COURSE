//Student Database - simple example

#include <iostream>
#include <assert.h>

namespace major {

enum class Major {
    Informatics,
    ComuterScience,
    SoftwareEngineering,
    InformaticSystems,
    Undefined
};

const char* getMajorString(Major m) {
    switch(m) {
        case Major::Informatics: return "informatics";
        case Major::ComuterScience: return "computer science";
        case Major::SoftwareEngineering: return "software engineering";
        case Major::InformaticSystems: return "informatic systems";
        case Major::Undefined: return "undefined";
        default: return "";
    }
}
}

namespace student {
    constexpr unsigned STUDENT_NAME_MAX_LEN = 100;
    constexpr unsigned FN_DEF_VAL = 0;

    using namespace major;

    struct Student {
        char name[STUDENT_NAME_MAX_LEN] = "";
        unsigned fn = FN_DEF_VAL;
        Major major = Major::Undefined;
    };

    void printStudent(const Student& student) {
        std::cout << student.name << " "
                << student.fn << " "
                << getMajorString(student.major) << " "
                << std::endl;
    }
}

namespace studentDB {
    constexpr unsigned STUDENTS_MAX_SIZE = 10;

    using namespace student;

    struct StudentDB {
        unsigned studentsCount = 0;
        Student students[STUDENTS_MAX_SIZE];
    };

    void sortStudents(StudentDB& db) {
        
    }
}
