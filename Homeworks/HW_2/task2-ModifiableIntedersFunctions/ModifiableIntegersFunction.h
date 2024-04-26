#include <fstream>

#include "Constants.h"

class ModifiableIntegersFunction {

private:
    struct Function {
        int16_t point = ModifIntFuncsConstants::MIN;
        int16_t value = ModifIntFuncsConstants::MIN;

        bool isDefined = true;
    };
    //The array is dynamic because if it is static I have warning for stack overflow.
    Function* modifiable_IntFunctions = nullptr;

public:
    //constructor
    ModifiableIntegersFunction(int16_t(*pred)(int16_t));

    //BIG 6
    ModifiableIntegersFunction(const ModifiableIntegersFunction&);
    ModifiableIntegersFunction& operator=(const ModifiableIntegersFunction&);

    ModifiableIntegersFunction(ModifiableIntegersFunction&&) noexcept; 
    ModifiableIntegersFunction& operator=(ModifiableIntegersFunction&&) noexcept;

    ~ModifiableIntegersFunction();

    //set output for given input
    void setOutputForInput(int16_t point, int16_t value);

    //exclude point (make it undefined)
    void excludePoint(int16_t point);

    //arithmetic operators
    ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction& other);
    ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction& other);

    //function composition - predefined operator (), and predefined operator () for returning the value at given point
    ModifiableIntegersFunction& operator()(const ModifiableIntegersFunction& other); 
    int16_t operator()(int16_t n) const;
    
    //operator ^= for returning the function at power k
    ModifiableIntegersFunction& operator^=(unsigned k); 

    //generating the inverse function
    ModifiableIntegersFunction& inverse(); 


    //injection, surjection and bijection functions
    bool isInection() const; 
    bool isSurection() const;
    bool isBiection() const;

    //serialize/deserialize in/from binary file
    void saveToBinaryFile(const char* fileName) const; 
    void readFromBinaryFile(const char* fileName);

    //drawing function graph
    void drawFunc() const;

    //comparing operators (they use private member - functions from the class, that is why they are friend - functions)
    friend bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

    //operator> uses operator< and there is no need to be a friend function for the class, but i made it friend because of the style of the code (to be next to the other cmp operators)
    friend bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

    friend bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

    //operator>= uses operator<= and there is no need to be a friend function for the class, but i made it friend because of the style of the code (to be next to the other cmp operators)
    friend bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

    friend bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

    //operator!= uses operator== and there is no need to be a friend function for the class, but i made it friend because of the style of the code (to be next to the other cmp operators)
    friend bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

    //predefined operator|| for checking if two function are parallel (it also uses private member - funcitons)
    friend bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs); 


private:
    //for the BIG 6
    void copyFrom(const ModifiableIntegersFunction& other);
    void moveFrom(ModifiableIntegersFunction&& other);
    void free();

    //this function is used in the compare - operators
    int countOfExcludedPoints() const; 

    //these make the program more readable
    void setVal(int index, int16_t value);
    int16_t getVal(int index) const;

    void setPoint(int index, int16_t point);

    //isDef calculates the index at which is the current point (this function throws exception that is handeled in the functions where it has been called)
    bool isDef(int point) const;
    //setIsDet does NOT calc the index at which is the current point, it expects the given index to be valid, because this is a private function I do not validate that
    void setIsDef(int index, bool def);

    //because in the for - loops I start from negative number, so I need to calculate to which index in the array the current point refers to
    int getIndexInArray(int point) const;

    //this one is used in the public member - function isInection()
    bool checkForInectionAtIndex(int index) const;

    //int16_t findDerivativeAtPoint(int16_t point) const;
};

//these use the already predefined operators += and -= (no need to be friend functions for the class)
ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

//uses operator ^=, but is a non member - funciton (also no need to be friend funciton to the class)
ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, unsigned k);