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

int16_t f_p(int16_t x) {
    return 2 * x;
}
int16_t f_p2(int16_t x) {
    return x * x;
}
int16_t f_p3(int16_t x) {
    return (x * (sqrt(x)));
}

int16_t function(int16_t x) {
    return x + 1;
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

    std::cout << std::endl;

    ModifiableIntegersFunction teest(f_p);
    ModifiableIntegersFunction teest2(f_p2);

    std::cout << (teest || teest2) << std::endl;

    ModifiableIntegersFunction teest3(f_p3);

    std::cout << (teest2 || teest3) << std::endl;

    ModifiableIntegersFunction funccc(function);

    std::cout << ((funccc ^ 3)(2)) << std::endl ;

    funccc.inverse();

    std::cout << (funccc(3)) << std::endl;

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
