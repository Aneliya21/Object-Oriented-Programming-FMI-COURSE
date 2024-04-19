//#include <iostream>
//#include <fstream>
//
////SOURCES: https://github.com/Justsvetoslavov/Object-oriented_programming_FMI/blob/master/Seminars/Utils/Exam/Task02/ModifiableNaturalNumbersFunction.hpp
//
//const int16_t MIN = INT16_MIN;
//const int16_t MAX = INT16_MAX;
//
//const unsigned ARRAY_SIZE = MAX + (-MIN) + 1;
//
//const int PLANE_SIZE = 20;
//
//
////ostava da napravq:
////  operator ^(-1)
////  operator^=(-1)
////  draw funkciqta
////  da resha dali da ostavq move semantikite
////  da napravq namespace za konstantite
////  da go napravq s razdelna kompilaciq
////  da preizpolzvam veche definirani operatori
////  kompoziciqta na funkcii
////  testove na vsichko
////  da mahna nenujnite funkcii
//
//class ModifiableIntegersFunction {
//
//private:
//    struct Function {
//        int16_t point = MIN;
//        int16_t value = MIN;
//
//        bool isDef = true;
//    };
//
//    Function* modifiable_IntFunctions = nullptr;
//    int16_t(*func)(int16_t);
//
//public:
//    ModifiableIntegersFunction(int16_t(*pred)(int16_t));
//
//    ModifiableIntegersFunction(const ModifiableIntegersFunction& other);
//    ModifiableIntegersFunction& operator=(const ModifiableIntegersFunction& other);
//
//    ModifiableIntegersFunction(ModifiableIntegersFunction&& other) noexcept; //?
//    ModifiableIntegersFunction& operator=(ModifiableIntegersFunction&& other) noexcept; //?
//
//    ~ModifiableIntegersFunction();
//
//    void setOutputForInput(int16_t point, int16_t value);
//
//    void excludePoint(int16_t point);
//
//    ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction& other);
//    ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction& other);
//
//    ModifiableIntegersFunction& operator()(const ModifiableIntegersFunction& other, int16_t point);
//    int16_t operator()(int16_t n) const;
//
//    ModifiableIntegersFunction operator^=(unsigned k);
//    ModifiableIntegersFunction operator^=(int k);
//
//    bool isInection() const;
//    bool isSurection() const;
//    bool isBiection() const;
//
//    void saveToBinaryFile(const char* fileName) const;
//    void readFromBinaryFile(const char* fileName);
//
//    void drawFunc() const;
//     
//    friend bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//    //friend bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//    
//    friend bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//    //friend bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//     
//    friend bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//    //friend bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//     
//    friend bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//     
//    //friend ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, unsigned k);
//    //friend ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, int k); //for -1
//
//private:
//    void copyFrom(const ModifiableIntegersFunction& other);
//    void moveFrom(ModifiableIntegersFunction&& other); //?
//    void free();
//
//    int findPointIndex(int16_t point) const; //?
//
//    int16_t evaluate(int16_t value) const; //?
//
//    int countOfExcludedPoints() const;
//
//    bool isDef(int index) const;
//};
//
//ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//
//bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//
//bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//
//bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
//
//ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, unsigned k);
//
////in .cpp
//
//void ModifiableIntegersFunction::copyFrom(const ModifiableIntegersFunction& other) {
//    /*size = other.size;
//    capacity = other.capacity;*/
//
//    modifiable_IntFunctions = new Function[ARRAY_SIZE];
//
//    for (int i = MIN; i <= MAX; i++) {
//
//        int arrInd = i - MIN;
//
//        modifiable_IntFunctions[arrInd] = other.modifiable_IntFunctions[arrInd];
//    }
//}
//void ModifiableIntegersFunction::moveFrom(ModifiableIntegersFunction&& other) {
//    modifiable_IntFunctions = other.modifiable_IntFunctions;
//    other.modifiable_IntFunctions = nullptr;
//
//    /*size = other.size;
//    capacity = other.capacity;
//
//    other.size = other.capacity = 0;*/
//}
//void ModifiableIntegersFunction::free() {
//    delete[] modifiable_IntFunctions;
//    modifiable_IntFunctions = nullptr;
//
//    /*size = capacity = 0;*/
//}
//
//int ModifiableIntegersFunction::findPointIndex(int16_t point) const {
//    for (int i = MIN; i <= MAX; i++) {
//
//        int indexInArray = i - MIN;
//
//        if (point == modifiable_IntFunctions[indexInArray].point) {
//            return indexInArray;
//        }
//    }
//    return -1;
//}
//
//int16_t ModifiableIntegersFunction::evaluate(int16_t value) const {
//    int index = findPointIndex(value);
//
//    if (index > -1) {
//        if (modifiable_IntFunctions[index].isDef == false) {
//            throw std::exception("Value not defined");
//        }
//        else {
//            return modifiable_IntFunctions[index].value;
//        }
//    }
//    else {
//        ////invalid 
//        return 0;
//    }
//}
//
//int ModifiableIntegersFunction::countOfExcludedPoints() const {
//    int count = 0;
//    for (int i = MIN; i <= MAX; i++) {
//        int indexInArray = i - MIN;
//        if (modifiable_IntFunctions[indexInArray].isDef == false) {
//            count++;
//        }
//    }
//    return count;
//}
//
//bool ModifiableIntegersFunction::isDef(int index) const {
//    if (modifiable_IntFunctions[index].isDef == false) {
//        throw std::exception("Function not defined at index: ");
//    }
//    else {
//        return true;
//    }
//}
//
//ModifiableIntegersFunction::ModifiableIntegersFunction(int16_t(*pred)(int16_t)) : func(pred) {
//    modifiable_IntFunctions = new Function[ARRAY_SIZE];
//
//    for (int i = MIN; i <= MAX; i++) {
//
//        int indexInArray = i - MIN;
//
//        int16_t res = pred(i);
//
//        modifiable_IntFunctions[indexInArray].value = res;
//        modifiable_IntFunctions[indexInArray].point = i;
//    }
//
//}
//
//ModifiableIntegersFunction::ModifiableIntegersFunction(const ModifiableIntegersFunction& other) {
//    copyFrom(other);
//}
//ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(const ModifiableIntegersFunction& other) {
//    if (this != &other) {
//        free();
//        copyFrom(other);
//    }
//    return *this;
//}
//
//ModifiableIntegersFunction::ModifiableIntegersFunction(ModifiableIntegersFunction&& other) noexcept {
//    moveFrom(std::move(other));
//}
//ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(ModifiableIntegersFunction&& other) noexcept {
//    if (this != &other) {
//        free();
//        moveFrom(std::move(other));
//    }
//    return *this;
//}
//
//ModifiableIntegersFunction::~ModifiableIntegersFunction() {
//    free();
//}
//
//void ModifiableIntegersFunction::setOutputForInput(int16_t point, int16_t value) {
//    int index = findPointIndex(point);
//
//    if (index == -1) {
//        return;
//    }
//    modifiable_IntFunctions[index].point = point;
//    modifiable_IntFunctions[index].value = value;
//
//    modifiable_IntFunctions[index].isDef = true;
//}
//
//void ModifiableIntegersFunction::excludePoint(int16_t point) {
//    int index = findPointIndex(point);
//    if (index > -1) {
//        modifiable_IntFunctions[index].isDef = false;
//    }
//}
//
//ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other) {
//    for (int i = MIN; i <= MAX; i++) {
//
//        int indInArray = i - MIN;
//
//        if (isDef(indInArray) == false || other.isDef(indInArray) == false) {
//            modifiable_IntFunctions[indInArray].isDef = false;
//        }
//
//        else if (isDef(indInArray) == true && other.isDef(indInArray) == true) {
//            setOutputForInput(i, (*this)(i) + other(i));
//        }
//    }
//
//    return *this;
//}
//ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other) {
//    for (int i = MIN; i <= MAX; i++) {
//
//        int indInArray = i - MIN;
//
//        if (isDef(indInArray) == false || other.isDef(indInArray) == false) {
//            modifiable_IntFunctions[indInArray].isDef = false;
//        }
//
//        else if (isDef(indInArray) == true && other.isDef(indInArray) == true) {
//            setOutputForInput(i, (*this)(i) - other(i));
//        }
//    }
//
//    return *this;
//}
//
//ModifiableIntegersFunction& ModifiableIntegersFunction::operator()(const ModifiableIntegersFunction& other, int16_t point) {
//    int16_t resOfOther = other.evaluate(point);
//    ////////to finish
//    return *this;
//}
//int16_t ModifiableIntegersFunction::operator()(int16_t n) const {
//    int index = n - MIN;
//    return modifiable_IntFunctions[index].value;
//}
//
//ModifiableIntegersFunction ModifiableIntegersFunction::operator^=(unsigned k) {
//    bool isCurrentDefined = true;
//
//    for (int i = MIN; i <= MAX; i++) {
//
//        int index = i - MIN;
//
//        try {
//            isCurrentDefined = isDef(index);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << index << std::endl;
//
//        }
//
//        if (isCurrentDefined == true) {
//            int16_t currentValue = (*this)(i);
//
//            for (unsigned times = 1; times < k; times++) {
//                currentValue = func(currentValue);
//            }
//
//            setOutputForInput(i, currentValue);
//        }
//    }
//    return *this;
//}
//ModifiableIntegersFunction ModifiableIntegersFunction::operator^=(int k) {
//    if (k != -1) {
//        throw std::invalid_argument("Argument should be -1 for generating inverse function!");
//    }
//    /*for (int i = MIN; i <= MAX; i++) {
//
//        int indInArr = i - MIN;
//
//        try {
//            bool isCurrentDef = isDef(indInArr);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << indInArr << std::endl;
//            return *this; //?
//        }
//    }
//    for (int i = MIN; i < MAX; i++) {
//
//        int indInArr = i - MIN;
//    }*/
//
//    //if (isBiection() == false) {
//    //    return *this;
//    //}
//    ModifiableIntegersFunction inverseFunc(*this);
//
//    for (int i = MIN; i <= MAX; i++) {
//        int index = i - MIN;
//
//        int y = (*this)(i);
//
//        inverseFunc.setOutputForInput(y, index + MIN);
//
//    }
//    /**this = inverseFunc;
//    return *this;*/
//    return inverseFunc;
//}
////tuka tr si opravq vlojeniq cikul
//bool ModifiableIntegersFunction::isInection() const {
//    for (int i = MIN; i <= MAX; i++) {
//        int i_indInArr = i - MIN;
//        for (int j = MIN; j <= MAX; j++) {
//            int j_indInArr = j - MIN;
//            if ((*this)(i) == (*this)(j)) {
//                /*if (modifiable_IntFunctions[i_indInArr].point != modifiable_IntFunctions[j_indInArr].point) {
//                    return false;
//                }*/
//                if (i != j) {
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
//}
//bool ModifiableIntegersFunction::isSurection() const {
//    for (int i = MIN; i <= MAX; i++) {
//
//        int indexInArr = i - MIN;
//
//        if (modifiable_IntFunctions[indexInArr].isDef == false) {
//            return false;
//        }
//    }
//    return true;
//}
//bool ModifiableIntegersFunction::isBiection() const {
//    return isInection() && isSurection();
//}
//
//void ModifiableIntegersFunction::saveToBinaryFile(const char* fileName) const {
//    if (!fileName) {
//        throw std::exception("Invalid file name!");
//    }
//    std::ofstream ofs(fileName, std::ios::binary);
//    
//    if (!ofs.is_open()) {
//        throw std::exception("File could NOT open successfully");
//    }
//
//    ofs.write((const char*)modifiable_IntFunctions, sizeof(Function) * ARRAY_SIZE);
//
//    ofs.close();
//}
//void ModifiableIntegersFunction::readFromBinaryFile(const char* fileName) {
//    if (!fileName) {
//        throw std::exception("Invalid file name!");
//    }
//    std::ifstream ifs(fileName, std::ios::binary);
//
//    if (!ifs.is_open()) {
//        throw std::exception("File could NOT open successfully");
//    }
//    modifiable_IntFunctions = new Function[ARRAY_SIZE];
//    ifs.read((char*)modifiable_IntFunctions, sizeof(Function) * ARRAY_SIZE);
//
//    ifs.close();
//}
//
////not working
//void ModifiableIntegersFunction::drawFunc() const {
//    for (int y = PLANE_SIZE; y >= -PLANE_SIZE; --y) {
//        for (int x = -PLANE_SIZE; x <= PLANE_SIZE; ++x) {
//            try {
//                // Evaluate the function at each point
//                int16_t result = evaluate(x);
//                // Print 'o' if the function is defined at this point, otherwise print a space
//                std::cout << (result != MIN ? 'o' : ' ');
//            }
//            catch (const std::exception&) {
//                // If evaluating the function throws an exception, print a space
//                std::cout << ' ';
//            }
//        }
//        std::cout << std::endl;
//    }
//}
//
//
//ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//
//    //ModifiableIntegersFunction result([](int16_t n) {return n; }, 0);
//    //for (int16_t i = MIN; i < MAX; i++) {
//    //    /*if (lhs.modifiedPoints[i].isDef == false || rhs.modifiedPoints[i].isDef == false) {
//    //        result.modifiedPoints[i].isDef = false;
//    //        continue;
//    //    }
//    //    result.setOutputForInput(i, lhs.evaluate(i) + rhs.evaluate(i));*/
//    //    int16_t lhsValue = 0;
//    //    int16_t rhsValue = 0;
//    //    try {
//    //        lhsValue = lhs.evaluate(i);
//    //    }
//    //    catch (const std::exception& ex) {
//    //        std::cout << ex.what() << std::endl;
//    //        result.modifiedPoints[i].isDef = false;
//    //    }
//    //    try {
//    //        rhsValue = rhs.evaluate(i);
//    //    }
//    //    catch (const std::exception& ex) {
//    //        std::cout << ex.what() << std::endl;
//    //        result.modifiedPoints[i].isDef = false;
//    //    }
//    //    if (result.modifiedPoints[i].isDef) {
//    //        result.setOutputForInput(i, lhsValue + rhsValue);
//    //    }
//    //}
//    ModifiableIntegersFunction result(lhs);
//    result += rhs;
//
//    return result;
//}
//ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//    //ModifiableIntegersFunction result([](int16_t n) {return n; }, 0);
//    //for (int16_t i = MIN; i < MAX; i++) {
//    //    /*if (lhs.modifiedPoints[i].isDef == false || rhs.modifiedPoints[i].isDef == false) {
//    //        result.modifiedPoints[i].isDef = false;
//    //        continue;
//    //    }
//    //    result.setOutputForInput(i, lhs.evaluate(i) - rhs.evaluate(i));*/
//    //    int16_t lhsValue = 0;
//    //    int16_t rhsValue = 0;
//    //    try {
//    //        lhsValue = lhs.evaluate(i);
//    //    }
//    //    catch (const std::exception& ex) {
//    //        std::cout << ex.what() << std::endl;
//    //        result.modifiedPoints[i].isDef = false;
//    //    }
//    //    try {
//    //        rhsValue = rhs.evaluate(i);
//    //    }
//    //    catch (const std::exception& ex) {
//    //        std::cout << ex.what() << std::endl;
//    //        result.modifiedPoints[i].isDef = false;
//    //    }
//    //    if (result.modifiedPoints[i].isDef) {
//    //        result.setOutputForInput(i, lhsValue - rhsValue);
//    //    }
//    //}
//    ModifiableIntegersFunction result(lhs);
//    result += rhs;
//
//    return result;
//}
//
//bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//
//    int countOfExcludedInLhs = lhs.countOfExcludedPoints();
//    int countOfExcludedInRhs = rhs.countOfExcludedPoints();
//
//    if (countOfExcludedInLhs != countOfExcludedInRhs) {
//        return countOfExcludedInLhs > countOfExcludedInRhs;
//    }
//
//    bool isLhsDef = true;
//    bool isRhsDef = true;
//
//    for (int i = MIN; i <= MAX; i++) {
//        int indInArr = i - MIN;
//
//        try {
//            isLhsDef = lhs.isDef(indInArr);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << indInArr << std::endl;
//        }
//
//        try {
//            isRhsDef = rhs.isDef(indInArr);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << indInArr << std::endl;
//        }
//
//        if (isLhsDef == true && isRhsDef == true) {
//            if (lhs(i) >= rhs(i)) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//    return rhs < lhs;
//}
//
//bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//    return rhs <= lhs;
//}
//bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//    int countOfExcludedInLhs = lhs.countOfExcludedPoints();
//    int countOfExcludedInRhs = rhs.countOfExcludedPoints();
//
//    if (countOfExcludedInLhs != countOfExcludedInRhs) {
//        return countOfExcludedInLhs > countOfExcludedInRhs;
//    }
//
//    bool isLhsDef = true;
//    bool isRhsDef = true;
//
//    for (int i = MIN; i <= MAX; i++) {
//        int indInArr = i - MIN;
//
//        try {
//            isLhsDef = lhs.isDef(indInArr);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << indInArr << std::endl;
//        }
//        try {
//            isRhsDef = rhs.isDef(indInArr);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << indInArr << std::endl;
//        }
//
//        if (isLhsDef == true && isRhsDef == true) {
//            if (lhs(i) > rhs(i)) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//    int16_t lhsRes = 0;
//    int16_t rhsRes = 0;
//
//    bool lhsDef = true;
//    bool rhsDef = true;
//
//    for (int i = MIN; i <= MAX; i++) {
//        int indInArr = i - MIN;
//
//        try {
//            lhsDef = lhs.isDef(indInArr);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << indInArr << std::endl;
//        }
//        try {
//            rhsDef = rhs.isDef(indInArr);
//        }
//        catch (const std::exception& ex) {
//            std::cout << ex.what() << indInArr << std::endl;
//        }
//
//        if(lhsDef == true && rhsDef == true) {
//            if (lhs(i) != rhs(i)) {
//                return false;
//            }
//            continue;
//        }
//    }
//    return true;
//}
//bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//    return !(lhs == rhs);
//}
//
//bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
//    return false;
//    //razlika na purvite def tochki i posle na ostanalite trqbva da e sushtata
//}
//
//ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, unsigned k) {
//    ModifiableIntegersFunction res(func);
//    return res ^= k;
//}
//
//
//int16_t func(int16_t n) {
//    return 0;
//}
//int16_t func2(int16_t n) {
//    return 1;
//}
//
//int16_t f1(int16_t x) {
//    return x;
//}
//int16_t f2(int16_t x) {
//    return -x;
//}
//int16_t f3(int16_t x) {
//    return x + 3;
//}
//int16_t f4(int16_t x) {
//    return 2 * x * x;
//}
//int16_t f5(int16_t x) {
//    return -x;
//}
//
//int16_t doubleFunc(int16_t x) {
//    return x * 2;
//}
//
//int16_t squareFunc(int16_t x) {
//    return x * x;
//}
//
//int16_t f(int16_t x) {
//    return 2 * x + 3;
//}
//
//int main()
//{
//    
//
//    //ModifiableIntegersFunction linearFunc(doubleFunc);
//    //ModifiableIntegersFunction nonLinearFunc(squareFunc);
//
//    //// Test linear function with k = 3
//    //linearFunc ^= 3;
//    //std::cout << "After applying operator^= with k = 3 to linearFunc:" << std::endl;
//    //for (int i = 0; i <= 12; ++i) {
//    //    std::cout << "f(" << i << ") = " << linearFunc(i) << std::endl;
//    //}
//
//    //// Test non-linear function with k = 2
//    //nonLinearFunc ^= 2;
//    //std::cout << "\nAfter applying operator^= with k = 2 to nonLinearFunc:" << std::endl;
//    //for (int i = 0; i <= 12; ++i) {
//    //    std::cout << "f(" << i << ") = " << nonLinearFunc(i) << std::endl;
//    //}
//
//    //ModifiableIntegersFunction m(func);
//    ////std::cout<<m.evaluate(-2);
//    //ModifiableIntegersFunction m2(func2);
//
//    //m.excludePoint(3);
//    //m2.excludePoint(2);
//
//
//    //std::cout << (m < m2) << std::endl;
//
//    /*ModifiableIntegersFunction def(f1);
//    std::cout << def(123) << std::endl;
//
//    ModifiableIntegersFunction func1(f1);
//    ModifiableIntegersFunction func2(f2);
//    ModifiableIntegersFunction func3(f3);
//    ModifiableIntegersFunction func4(f4);
//
//    std::cout << func1(4) << std::endl;
//    std::cout << func1.countOfExcludedPoints() << std::endl;
//    func1.excludePoint(4);
//    std::cout << func1.countOfExcludedPoints() << std::endl;
//
//
//    func1.excludePoint(4);
//    std::cout << func1.countOfExcludedPoints() << std::endl;
//    std::cout << func1(4) << std::endl;
//
//    func3.excludePoint(7);
//    func3.excludePoint(-11);
//    func4.excludePoint(7);
//    func4.excludePoint(666);
//    func4.excludePoint(123);
//
//    std::cout << func3.countOfExcludedPoints() << std::endl;
//    std::cout << func4.countOfExcludedPoints() << std::endl;
//
//    ModifiableIntegersFunction func5 = func3 + func4;
//    std::cout << func5.countOfExcludedPoints() << std::endl;
//    std::cout << func3(666) << std::endl;
//    std::cout << func4(-11) << std::endl;
//    std::cout << func5(76) << std::endl;
//
//
//    ModifiableIntegersFunction func7(f5);
//    std::cout << func7.isInection() << std::endl;
//    std::cout << func7.isSurection() << std::endl;
//    std::cout << func7.isBiection() << std::endl << std::endl;
//
//    func7.excludePoint(2);
//
//    std::cout << func7.isInection() << std::endl;
//    std::cout << func7.isSurection() << std::endl;
//    std::cout << func7.isBiection() << std::endl << std::endl;
//
//    func7.excludePoint(2);
//    func7.setOutputForInput(0, 6);
//
//    std::cout << func7.isInection() << std::endl;
//    std::cout << func7.isSurection() << std::endl;
//    std::cout << func7.isBiection() << std::endl << std::endl;*/
//}


#include <iostream>
#include "ModifiableIntegersFunction.h"

int16_t func1_(int16_t x) {
    return x + 1;
}
int16_t func2_(int16_t x) {
    return x + 2;
}

int16_t doubleFun___ction(int16_t x) {
    return x;
}
int16_t doubleFunc2_(int16_t x) {
    return 3*x-1;
}

int16_t addOneFunc_(int16_t x) {
    //return x+1;
    return x * x * x;
}
int16_t squareFunc_(int16_t x) {
    return x;
}

int16_t fff(int16_t x) {
    return 2 * x;
}

int16_t f1_(int16_t x) {
    return 0;
}
int16_t f2_(int16_t x) {
    return 1;
}

int main() {

    ModifiableIntegersFunction test1(f1_); //0
    ModifiableIntegersFunction test2(f2_); //1

    ModifiableIntegersFunction test3(f1_); //0
    ModifiableIntegersFunction test4(f2_); //1

    std::cout << (test1 < test2) << std::endl; //1
    std::cout << (test1 > test2) << std::endl; //0
    std::cout << (test1 == test3) << std::endl; //1
    std::cout << (test1 == test2) << std::endl; //0
    std::cout << (test2 == test4) << std::endl; //1
    std::cout << (test1 >= test3) << std::endl; //1
    std::cout << (test1 <= test3) << std::endl; //1
    std::cout << (test2 <= test1) << std::endl; //0
    std::cout << (test2 >= test3) << std::endl; //1

    //test3.excludePoint(0);
    //test3.excludePoint(1);
    //test1.excludePoint(0);
    //std::cout << (test3 < test1) << std::endl; //1

    std::cout << std::endl;

    for (int i = -5; i <= 5; i++) {
        std::cout << "test1(" << i << ") = " << test1(i) << std::endl;
        std::cout << "test2(" << i << ") = " << test2(i) << std::endl;
        std::cout << "(test1 + test 2)(" << i << ") = " <<  test1(i) + test2(i) << std::endl;
    }

    std::cout << std::endl;

    ModifiableIntegersFunction drawTest(addOneFunc_);
    drawTest.drawFunc();

    std::cout << std::endl;

    test1.excludePoint(0);
    test1 += test2;

    ModifiableIntegersFunction plusTest(test1);

    for (int i = -5; i <= 5; i++) {
        std::cout << plusTest(i) << std::endl;
    }

    std::cout << std::endl;

    ModifiableIntegersFunction plusTest2 = test1 + test2;

    for (int i = -5; i <= 5; i++) {
        std::cout << plusTest2(i) << std::endl;
    }

     //Test the ModifiableIntegersFunction class with some example functions

     //Create a ModifiableIntegersFunction object using the doubleFunc
    //ModifiableIntegersFunction doubleFunction(doubleFunc_);
    //std::cout << "Function f(x) = 2x:" << std::endl;
    //for (int i = -5; i <= 5; ++i) {
    //    std::cout << "f(" << i << ") = " << doubleFunction(i) << std::endl;
    //}
    //std::cout << "Count of excluded points: " << doubleFunction.countOfExcludedPoints() << std::endl;
    //std::cout << std::endl;

    //// Create a ModifiableIntegersFunction object using the addOneFunc
    //ModifiableIntegersFunction addOneFunction(addOneFunc_);
    //std::cout << "Function f(x) = x + 1:" << std::endl;
    //for (int i = -5; i <= 5; ++i) {
    //    std::cout << "f(" << i << ") = " << addOneFunction(i) << std::endl;
    //}
    //std::cout << "Count of excluded points: " << addOneFunction.countOfExcludedPoints() << std::endl;
    //std::cout << std::endl;

    //// Test the += operator
    //std::cout << "Testing operator+=" << std::endl;
    ///*ModifiableIntegersFunction combinedFunction = */doubleFunction += addOneFunction;
    //for (int i = -5; i <= 5; ++i) {
    //    std::cout << "f(" << i << ") + g(" << i << ") = " << doubleFunction(i) << std::endl;
    //}
    //std::cout << "Count of excluded points: " << doubleFunction.countOfExcludedPoints() << std::endl;
    //std::cout << std::endl;

    // Test the -= operator
    //std::cout << "Testing operator-=" << std::endl;
    ///*ModifiableIntegersFunction subtractedFunction = */doubleFunction -= addOneFunction;
    //for (int i = -5; i <= 5; ++i) {
    //    std::cout << "f(" << i << ") - g(" << i << ") = " << doubleFunction(i) << std::endl;
    //}
    //std::cout << "Count of excluded points: " << doubleFunction.countOfExcludedPoints() << std::endl;
    //std::cout << std::endl;

    // //Test the ^= operator
    //std::cout << "Testing operator^=" << std::endl;
    //ModifiableIntegersFunction doubleSquared = doubleFunction ^= 2;
    //for (int i = -5; i <= 5; ++i) {
    //    std::cout << "f(f(" << i << ")) = " << doubleSquared(i) << std::endl;
    //}
    //std::cout << "Count of excluded points: " << doubleSquared.countOfExcludedPoints() << std::endl;
    //std::cout << std::endl;

    //// Test the ^= operator for generating inverse function
    //std::cout << "Testing operator^= for generating inverse function" << std::endl;
    //ModifiableIntegersFunction inverseFunction = doubleFunction ^= -1;
    //for (int i = -5; i <= 10; ++i) {
    //    std::cout << "Inverse of f(" << i << ") = " << inverseFunction(i) << std::endl;
    //}
    //std::cout << "Count of excluded points: " << inverseFunction.countOfExcludedPoints() << std::endl;
    //std::cout << std::endl;

    //ModifiableIntegersFunction func1(doubleFunc_);
    //ModifiableIntegersFunction func2(addOneFunc_);

    //// Test the comparison operators
    //std::cout << "Testing comparison operators:" << std::endl;
    //std::cout << "(func1 < func2) is " << (func1 < func2) << std::endl;
    //std::cout << "(func1 > func2) is " << (func1 > func2) << std::endl;
    //std::cout << "(func1 <= func2) is " << (func1 <= func2) << std::endl;
    //std::cout << "(func1 >= func2) is " << (func1 >= func2) << std::endl;
    //std::cout << "(func1 == func2) is " << (func1 == func2) << std::endl;
    //std::cout << "(func1 != func2) is " << (func1 != func2) << std::endl;

  //  ModifiableIntegersFunction doubleFunction(doubleFunc_);

    // Create a ModifiableIntegersFunction object using a function that adds 1 to the input
    //ModifiableIntegersFunction addOneFunction(addOneFunc_);

    // Create a ModifiableIntegersFunction object using a function that squares the input
    //ModifiableIntegersFunction doubleFunction(squareFunc_);

    //// Test the properties of each function
    //std::cout << "Testing function properties:" << std::endl;
    //std::cout << "Is doubleFunction an injection? " << doubleFunction.isInection() << std::endl;
    //std::cout << "Is addOneFunction a surjection? " << doubleFunction.isSurection() << std::endl;
    //std::cout << "Is squareFunction a bijection? " << doubleFunction.isBiection() << std::endl;
    //

    /*ModifiableIntegersFunction m(doubleFunc_);
    ModifiableIntegersFunction m2(doubleFunc2_);

    std::cout << (m || m2);*/

    //ModifiableIntegersFunction squareFunction(squareFunc_);

    //squareFunction.drawFunc();

    // Display the function before any modifications
    //std::cout << "Function f(x) = x^2:" << std::endl;
    //for (int i = -5; i <= 5; ++i) {
    //    std::cout << "f(" << i << ") = " << squareFunction(i) << std::endl;
    //}
    //std::cout << std::endl;

    //// Exclude point x = 2

    //squareFunction.excludePoint(-3);
    //squareFunction.excludePoint(5);
    //// Set output for input x = 3 as 9
    //squareFunction.setOutputForInput(-2, 15);

    //// Display the function after modifications
    //std::cout << "Function after excluding point x = 2 and setting f(3) = 9:" << std::endl;
    //for (int i = -5; i <= 5; ++i) {

    //    try {
    //        if (squareFunction.isDef(i))

    //            std::cout << "f(" << i << ") = " << squareFunction(i) << std::endl;
    //    }
    //    catch (const std::exception& ex) {
    //        std::cout << ex.what() << i << std::endl;
    //    }
    //}
    //std::cout << std::endl;

    //std::cout << squareFunction.countOfExcludedPoints();
    //return 0;

    //ModifiableIntegersFunction f1(doubleFunc_); //2*2 = 4
    //ModifiableIntegersFunction f2(doubleFunc2_); //11

    //std::cout << f2(f1(2));

//ModifiableIntegersFunction linearFunc(doubleFunc_);
//////ModifiableIntegerFunction nonLinearFunc(squareFunc);
////////ModifiableIntegerFunction emptyFunc(nullptr);
//
////// Test linear function with k = 3
//linearFunc ^= 3;
//std::cout << "After applying operator^= with k = 3 to linearFunc:" << std::endl;
//for (int i = 0; i <= 12; ++i) {
//    std::cout << "f(" << i << ") = " << linearFunc(i) << std::endl;
//}

//ModifiableIntegersFunction mf(func1_); //x+1
//ModifiableIntegersFunction mf2(func2_); //x+2
//
//std::cout << mf(mf2(1)); //mf2(1) = 1+2 = 3, mf(3) = 3+1 = 4
//std::cout << mf(1);

//mf2.excludePoint(2);
//
//for (int i = -5; i <= 5; i++) {
//    std::cout << "mf(" << i << ") = " << mf(i) << std::endl;
//}
//std::cout << std::endl;
//for (int i = -5; i <= 5; i++) {
//    std::cout << "mf2(" << i << ") = " << mf2(i) << std::endl;
//}
//std::cout << std::endl;
//ModifiableIntegersFunction mf3(mf + mf2);
//for (int i = -5; i <= 5; i++) {
//    try {
//        if (mf.isDef(i)) {
//            std::cout << "mf3(" << i << ") = " << mf3(i) << std::endl;
//        }
//    }
//    catch (...) {
//        std::cout << "Not def" << std::endl;
//    }
//}

}
