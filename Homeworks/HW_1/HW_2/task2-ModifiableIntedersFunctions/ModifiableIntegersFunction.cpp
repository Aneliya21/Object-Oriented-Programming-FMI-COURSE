#include "ModifiableIntegersFunction.h"
#include <iomanip> //this one is used in drawFunc()

void ModifiableIntegersFunction::copyFrom(const ModifiableIntegersFunction& other) {
    modifiable_IntFunctions = new Function[ModifIntFuncsConstants::ARRAY_SIZE];
    //copy data
    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        int arrInd = getIndexInArray(i);
        modifiable_IntFunctions[arrInd] = other.modifiable_IntFunctions[arrInd];
    }
}
void ModifiableIntegersFunction::moveFrom(ModifiableIntegersFunction&& other) {
    modifiable_IntFunctions = other.modifiable_IntFunctions; //"steal data"
    other.modifiable_IntFunctions = nullptr;
}
void ModifiableIntegersFunction::free() {
    delete[] modifiable_IntFunctions;
    modifiable_IntFunctions = nullptr; //giving it def value
}

int ModifiableIntegersFunction::countOfExcludedPoints() const {
    int count = 0;
    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        int indexInArray = i - ModifIntFuncsConstants::MIN;
        if (modifiable_IntFunctions[indexInArray].isDefined == false) {
            count++;
        }
    }
    return count;
}

bool ModifiableIntegersFunction::isDef(int point) const {
    int index = getIndexInArray(point);
    if (modifiable_IntFunctions[index].isDefined == false) {
        throw std::exception("Function not defined at index: ");
    }
    else {
        return true;
    }
}
void ModifiableIntegersFunction::setIsDef(int index, bool def) {
    modifiable_IntFunctions[index].isDefined = def;
}

void ModifiableIntegersFunction::setVal(int index, int16_t value) {
    modifiable_IntFunctions[index].value = value;
}
int16_t ModifiableIntegersFunction::getVal(int index) const {
    return modifiable_IntFunctions[index].value;
}

void ModifiableIntegersFunction::setPoint(int index, int16_t point) {
    modifiable_IntFunctions[index].point = point;
}

int ModifiableIntegersFunction::getIndexInArray(int point) const {
    return point - ModifIntFuncsConstants::MIN;
}

bool ModifiableIntegersFunction::checkForInectionAtIndex(int index) const {
    int currentValue = (*this)(index);
    for (int j = ModifIntFuncsConstants::MIN; j <= ModifIntFuncsConstants::MAX; j++) {
        if ((currentValue == (*this)(j)) && (index != j)) {
            return false;
        }
    }
    return true;
}

int16_t ModifiableIntegersFunction::findDerivativeAtPoint(int16_t point) const {
    double h = 0.0001;  // Step size for numerical differentiation

    int16_t val = getVal(point - ModifIntFuncsConstants::MIN + h);
    int16_t val2 = getVal(point - ModifIntFuncsConstants::MIN);

    return (int16_t)((val - val2) / h);

    //return (int16_t)((func(point + h) - func(point)) / h);
}


//tiq sa qsni
ModifiableIntegersFunction::ModifiableIntegersFunction(int16_t(*pred)(int16_t)) {
    modifiable_IntFunctions = new Function[ModifIntFuncsConstants::ARRAY_SIZE];

    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {

        int indexInArray = getIndexInArray(i);
        int16_t res = pred(i);

        setVal(indexInArray, res);
        setPoint(indexInArray, i);
    }
}

ModifiableIntegersFunction::ModifiableIntegersFunction(const ModifiableIntegersFunction& other) {
    copyFrom(other);
}
ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(const ModifiableIntegersFunction& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

ModifiableIntegersFunction::ModifiableIntegersFunction(ModifiableIntegersFunction&& other) noexcept {
    moveFrom(std::move(other));
}
ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(ModifiableIntegersFunction&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ModifiableIntegersFunction::~ModifiableIntegersFunction() {
    free();
}

void ModifiableIntegersFunction::setOutputForInput(int16_t point, int16_t value) {
    int index = getIndexInArray(point);
    //setPoint(index, point);
    setVal(index, value);
    setIsDef(index, true);
}

void ModifiableIntegersFunction::excludePoint(int16_t point) {
    int index = getIndexInArray(point);
    setIsDef(index, false);
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other) {
    bool isThisDef = true;
    bool isOtherDef = true;

    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        /*try {
            if (isDef(i) == false || other.isDef(i) == false) {
                setIsDef(i-ModifIntFuncsConstants::MIN, false);
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }

        try {
            if ((isDef(i) == true) && (other.isDef(i) == true)) {
                setOutputForInput(i, (*this)(i) + other(i));
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }*/
        try {
            isThisDef = isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
            setIsDef(i - ModifIntFuncsConstants::MIN, false);
            continue;
        }

        try {
            isOtherDef = isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
            setIsDef(i - ModifIntFuncsConstants::MIN, false);
            continue;
        }

        if ((isThisDef == true) && (isOtherDef == true)) {
            setOutputForInput(i, (*this)(i) + other(i));
        }
    }

    return *this;
}
ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other) {
    bool isThisDef = true;
    bool isOtherDef = true;

    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {

        try {
            isThisDef = isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
            setIsDef(i - ModifIntFuncsConstants::MIN, false);
            continue;
        }

        try {
            isOtherDef = isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
            setIsDef(i - ModifIntFuncsConstants::MIN, false);
            continue;
        }

        if ((isThisDef == true) && (isOtherDef == true)) {
            setOutputForInput(i, (*this)(i) - other(i));
        }
    }
    return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator()(const ModifiableIntegersFunction& other) {
    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; ++i) {

        if (isDef(i) && other.isDef((*this)(i))) {

            int16_t result = (*this)(other(i));
            setOutputForInput(i, result);
        }
        else {
            setIsDef(i - ModifIntFuncsConstants::MIN, false);
        }
    }
    return *this;
}
int16_t ModifiableIntegersFunction::operator()(int16_t x) const {
    int index = getIndexInArray(x);
    return getVal(index);
}

//tva pak da se testva
ModifiableIntegersFunction& ModifiableIntegersFunction::operator^=(unsigned k) {
    /*bool isCurrentDefined = true;

    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        try {
            isCurrentDefined = isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }

        if (isCurrentDefined == true) {
            int16_t currentValue = (*this)(i);

            for (unsigned times = 1; times < k; times++) {
                currentValue = func(currentValue);
            }
            setOutputForInput(i, currentValue);
        }
    }
    return *this;*/
    if (k <= 1) {
        return *this;
    }
    bool isCurrentDef = true;

    for (int i = ModifIntFuncsConstants::MIN; i < ModifIntFuncsConstants::MAX; i++) {
        try {
            isCurrentDef = isDef(i);
        }
        catch (const std::exception& ex) {
            
        }
        if (isCurrentDef == true) {
            int16_t currVal = getVal(i - ModifIntFuncsConstants::MIN);

            for (int times = 1; times < k; times++) {
                currVal = getVal(currVal - ModifIntFuncsConstants::MIN);
            }

            setVal(i - ModifIntFuncsConstants::MIN, currVal);
        }
    }
    return *this;
}

//i tva da se testva
ModifiableIntegersFunction& ModifiableIntegersFunction::inverse() {

   /*if (isBiection() == false) {
            return *this;
   }*/
   ModifiableIntegersFunction inverseFunc(*this);
   
   for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
       int y = (*this)(i);
       inverseFunc.setOutputForInput(y, i);
   }
   *this = inverseFunc;
   return *this;
}

bool ModifiableIntegersFunction::isInection() const {
    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        if (checkForInectionAtIndex(i) == false) {
            return false;
        }
    }
    return true;
}
bool ModifiableIntegersFunction::isSurection() const {
    bool isCurrentDef = true;
    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        try {
            isCurrentDef = isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
            return false;
        }
    }
    return true;
}
bool ModifiableIntegersFunction::isBiection() const {
    return isInection() && isSurection();
}

void ModifiableIntegersFunction::saveToBinaryFile(const char* fileName) const {
    if (!fileName) {
        throw std::exception("Invalid file name!");
    }
    std::ofstream ofs(fileName, std::ios::binary);

    if (!ofs.is_open()) {
        throw std::exception("File could NOT open successfully");
    }

    ofs.write((const char*)modifiable_IntFunctions, sizeof(Function) * ModifIntFuncsConstants::ARRAY_SIZE);

    ofs.close();
}
void ModifiableIntegersFunction::readFromBinaryFile(const char* fileName) {
    if (!fileName) {
        throw std::exception("Invalid file name!");
    }
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs.is_open()) {
        throw std::exception("File could NOT open successfully");
    }
    //I don't get the file size first, because it the array I want to keep all of the posible values that can appear in type int16_t,
    //and because of that I allocate the max memory these values can take.
    modifiable_IntFunctions = new Function[ModifIntFuncsConstants::ARRAY_SIZE];

    ifs.read((char*)modifiable_IntFunctions, sizeof(Function) * ModifIntFuncsConstants::ARRAY_SIZE);

    ifs.close();
}

void ModifiableIntegersFunction::drawFunc() const {
    for (int y = ModifIntFuncsConstants::PLANE_SIZE; y >= -ModifIntFuncsConstants::PLANE_SIZE; --y) {
        for (int x = -ModifIntFuncsConstants::PLANE_SIZE; x <= ModifIntFuncsConstants::PLANE_SIZE; ++x) {
            char toPrint = ModifIntFuncsConstants::EMPTY_CHAR;
            int16_t result = (*this)((int16_t)(x));

            if (x == 0 && y == 0) {
                if (result == y) {
                    toPrint = ModifIntFuncsConstants::POINT_CHAR;
                }
                else
                    toPrint = '-';
            }
            else if (x == 0) {

                toPrint = '|';
            }
            else if (y == 0)
            {
                // X-axis
                toPrint = '-';
            }
            if (y == 0 && result == y)
                toPrint = '-';
            if (x == 0 && result == x)
                toPrint = '|';
            else {
                // Check if the current position matches the function output
                try {

                    if (result == y) {
                        toPrint = ModifIntFuncsConstants::POINT_CHAR; // Mark the function's point
                    }
                }
                catch (...) {
                    // If an exception occurs, assume the function is not defined at this x
                    // and leave the character as the empty space.
                }
            }
            std::cout << toPrint;
        }
        std::cout << std::endl;
    }
}

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    ModifiableIntegersFunction result(lhs);
    result += rhs;

    return result;
}
ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    ModifiableIntegersFunction result(lhs);
    result += rhs;

    return result;
}

bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {

    int countOfExcludedInLhs = lhs.countOfExcludedPoints();
    int countOfExcludedInRhs = rhs.countOfExcludedPoints();

    if (countOfExcludedInLhs != countOfExcludedInRhs) {
        return countOfExcludedInLhs > countOfExcludedInRhs;
    }
    bool isLhsDef = true;
    bool isRhsDef = true;

    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        try {
            isLhsDef = lhs.isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }

        try {
            isRhsDef = rhs.isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }

        if (isLhsDef == true && isRhsDef == true) {
            if (lhs(i) >= rhs(i)) {
                return false;
            }
        }
    }
    return true;
}
bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    return rhs < lhs;
}

bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    int countOfExcludedInLhs = lhs.countOfExcludedPoints();
    int countOfExcludedInRhs = rhs.countOfExcludedPoints();

    if (countOfExcludedInLhs != countOfExcludedInRhs) {
        return (countOfExcludedInLhs > countOfExcludedInRhs);
    }
    bool isLhsDef = true;
    bool isRhsDef = true;

    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {     
        try {
            isLhsDef = lhs.isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }
        try {
            isRhsDef = rhs.isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }

        if (isLhsDef == true && isRhsDef == true) {
            if (lhs(i) > rhs(i)) {
                return false;
            }
        }
    }
    return true;
}
bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    return rhs <= lhs;
}

bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    int16_t lhsRes = 0;
    int16_t rhsRes = 0;

    bool lhsDef = true;
    bool rhsDef = true;

    for (int i = ModifIntFuncsConstants::MIN; i <= ModifIntFuncsConstants::MAX; i++) {
        try {
            lhsDef = lhs.isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }
        try {
            rhsDef = rhs.isDef(i);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << i << std::endl;
        }

        if ((lhsDef == true) && (rhsDef == true)) {
            if (lhs(i) != rhs(i)) {
                return false;
            }
            continue;
        }
        else if ((lhsDef == false) && (rhsDef == true)) {
            return false;
        }
        else if ((lhsDef == true) && (rhsDef == false)) {
            return false;
        }
    }
    return true;
}
bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    return !(lhs == rhs);
}

//tva tr se testva
bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    double tolerance = 0.0001;  // Tolerance for comparing slopes

    // Check for parallelism over the specified range
    for (int point = ModifIntFuncsConstants::MIN; point <= ModifIntFuncsConstants::MAX; point++) {
        int16_t slope1 = lhs.findDerivativeAtPoint(point);
        int16_t slope2 = rhs.findDerivativeAtPoint(point);

        // Compare the slopes with a tolerance
        if (std::abs(slope1 - slope2) > tolerance) {
            return false;
        }
    }
    return true;
}

ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, unsigned k) {
    ModifiableIntegersFunction res(func);
    return res ^= k;
}
