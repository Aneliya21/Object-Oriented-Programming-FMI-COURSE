//Sources: 
//  Yoana Mateva, course 1, IS
//  https://github.com/Angeld55
//  https://github.com/GeorgiTerziev02
//  https://github.com/Radopeev


//test1 - excample from the task

#include <iostream>
#include "UserInterface.h"
#include <fstream>

//save data to files, for the test

//#include <vector>
//#include <string>
//
//void writeIntToFile(std::ofstream& outFile, int value) {
//    outFile.write(reinterpret_cast<char*>(&value), sizeof(int16_t));
//}
//
//void writeStringToFile(std::ofstream& outFile, const std::string& value) {
//    outFile.write(value.c_str(), value.size() + 1);
//}
//
//void writeVectorToFile(std::ofstream& outFile, const std::vector<int>& vec) {
//    size_t length = vec.size();
//    outFile.write(reinterpret_cast<const char*>(vec.data()), length * sizeof(int32_t));
//}
//
//void saveFuncDat() {
//    int16_t int1 = 3;
//    int16_t int2 = 3;
//    std::string str1 = "first.dat";
//    std::string str2 = "second.dat";
//    std::string str3 = "third.dat";
//
//    std::string filename = "func.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//
//    writeStringToFile(outFile, str1);
//    writeStringToFile(outFile, str2);
//    writeStringToFile(outFile, str3);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//
//}
//
//void saveFirstData() {
//    int16_t int1 = 7;
//    int16_t int2 = 0;
//    std::vector<int32_t> vec1 = { 0, 1, 2, 3, 5, 6, 7 };
//    std::vector<int32_t> vec2 = { 0, 3, 3, 3, 4, 4, 0 };
//
//    std::string filename = "first.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//
//    writeVectorToFile(outFile, vec1);
//
//    writeVectorToFile(outFile, vec2);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveSecondData() {
//    int16_t int1 = 2;
//    int16_t int2 = 1;
//    std::vector<int32_t> vec1 = { 3, 5 };
//
//    std::string filename = "second.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveThirdData() {
//    int16_t int1 = 4;
//    int16_t int2 = 2;
//    std::vector<int32_t> vec1 = { 0, 5, 6, 7 };
//
//    std::string filename = "third.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}

int main() {
     /*   saveFuncDat();
        saveFirstData();
        saveSecondData();
        saveThirdData();*/
    UserInterface uI;
}


//test2 - throws ex, but cout is ok

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include "UserInterface.h"
//
//
//void writeIntToFile(std::ofstream& outFile, int value) {
//    outFile.write(reinterpret_cast<char*>(&value), sizeof(int16_t));
//}
//
//void writeStringToFile(std::ofstream& outFile, const std::string& value) {
//    outFile.write(value.c_str(), value.size() + 1);
//}
//
//void writeVectorToFile(std::ofstream& outFile, const std::vector<int>& vec) {
//    size_t length = vec.size();
//    outFile.write(reinterpret_cast<const char*>(vec.data()), length * sizeof(int32_t));
//}
//
//void saveFuncDat() {
//    int16_t int1 = 3;
//    int16_t int2 = 3;
//    std::string str1 = "first.dat";
//    std::string str2 = "second.dat";
//    std::string str3 = "third.dat";
//
//    std::string filename = "func.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//
//    writeStringToFile(outFile, str1);
//    writeStringToFile(outFile, str2);
//    writeStringToFile(outFile, str3);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//
//}
//
//void saveFirstData() {
//    int16_t int1 = 7;
//    int16_t int2 = 0;
//    std::vector<int32_t> vec1 = { 0, 1, 2, 3, 5, 6, 7 };
//    std::vector<int32_t> vec2 = { 0, 3, 3, 3, 4, 4, 0 };
//
//    std::string filename = "first.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//
//    writeVectorToFile(outFile, vec1);
//
//    writeVectorToFile(outFile, vec2);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveSecondData() {
//    int16_t int1 = 2;
//    int16_t int2 = 1;
//    std::vector<int32_t> vec1 = { 3, 5 };
//
//    std::string filename = "second.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveThirdData() {
//    int16_t int1 = 4;
//    int16_t int2 = 2;
//    std::vector<int32_t> vec1 = { 0, 5, 6, 7 };
//
//    std::string filename = "third.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//void saveFourthData() {
//    int16_t int1 = 5;
//    int16_t int2 = 3;
//    std::vector<int32_t> vec1 = { 2, 4, 8, 10, 12 };
//    std::vector<int32_t> vec2 = { 20, 15, 10, 5, 0 };
//
//    std::string filename = "fourth.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//    writeVectorToFile(outFile, vec2);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveFifthData() {
//    int16_t int1 = 3;
//    int16_t int2 = 1;
//    std::vector<int32_t> vec1 = { 1, 3, 5 };
//
//    std::string filename = "fifth.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveSixthData() {
//    int16_t int1 = 6;
//    int16_t int2 = 2;
//    std::vector<int32_t> vec1 = { 7, 14, 21 };
//
//    std::string filename = "sixth.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void testMaxPartialFunction(PartialFunctionOperation& collection) {
//    MaximumOfPartialFunctions maxFunc(collection);
//
//    std::cout << "Test MaxPartialFunction:" << std::endl;
//
//    // Test isDefined
//    std::cout << "isDefined(4): " << (!maxFunc.isDefinedAtPoint(4) ? "Passed" : "Failed") << std::endl;
//    std::cout << "isDefined(6): " << (maxFunc.isDefinedAtPoint(6) ? "Passed" : "Failed") << std::endl;
//
//    // Test execute
//    Pair<bool, int32_t> result = maxFunc.evaluate(6);
//
//    std::cout << "executeFunc(6): " << (result.getLhs() && result.getRhs() == 6 ? "Passed" : "Failed") << std::endl;
//}
//
//void testMinPartialFunction(PartialFunctionOperation& collection) {
//    MinimumOfPartialFunctions minFunc(collection);
//
//    std::cout << "Test MinPartialFunction:" << std::endl;
//
//    // Test isDefined
//    std::cout << "isDefined(4): " << (!minFunc.isDefinedAtPoint(4) ? "Passed" : "Failed") << std::endl;
//    std::cout << "isDefined(6): " << (minFunc.isDefinedAtPoint(6) ? "Passed" : "Failed") << std::endl;
//
//    // Test execute
//    Pair<bool, int32_t> result = minFunc.evaluate(6);
//
//    std::cout << "executeFunc(6): " << (result.getLhs() && result.getRhs() == 6 ? "Passed" : "Failed") << std::endl;
//}
//
//void testPartialFunctionCollection() {
//    Vector<int32_t> undefinedPoints;
//    undefinedPoints.pushBack(1);
//    undefinedPoints.pushBack(2);
//    undefinedPoints.pushBack(3);
//
//    Vector<int32_t> definedPoints;
//    definedPoints.pushBack(4);
//    definedPoints.pushBack(5);
//    definedPoints.pushBack(6);
//
//    BaseCriteria* criterion1 = new NotDefinedAtPoints_PartialFunctionCriteria(undefinedPoints, 3);
//    BaseCriteria* criterion2 = new DefinedForAll_PartialFunctionCriteria(definedPoints, 3);
//
//    PartialFunctionByCriteria* func1 = new PartialFunctionByCriteria(criterion1);
//    PartialFunctionByCriteria* func2 = new PartialFunctionByCriteria(criterion2);
//
//    PartialFunctionOperation collection;
//
//    // Add functions to the collection
//    collection.addFunc(func1);
//    collection.addFunc(func2);
//
//    std::cout << "Test PartialFunctionCollection:" << std::endl;
//
//    // Now test max and min functions using the collection
//    testMaxPartialFunction(collection);
//    testMinPartialFunction(collection);
//
//    // Clean up
//    delete criterion1;
//    delete criterion2;
//    delete func1;
//    delete func2;
//}
//
//int main() {
//    saveFuncDat();
//    saveFirstData();
//    saveSecondData();
//    saveThirdData();
//    saveFourthData();
//    saveFifthData();
//    saveSixthData();
//
//    testPartialFunctionCollection();
//
//    UserInterface UI;
//    return 0;
//}


//test3 - throws ex, but cout is ok

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include "UserInterface.h"
//
//void writeIntToFile(std::ofstream& outFile, int value) {
//    outFile.write(reinterpret_cast<char*>(&value), sizeof(int16_t));
//}
//
//void writeStringToFile(std::ofstream& outFile, const std::string& value) {
//    outFile.write(value.c_str(), value.size() + 1);
//}
//
//void writeVectorToFile(std::ofstream& outFile, const std::vector<int>& vec) {
//    size_t length = vec.size();
//    outFile.write(reinterpret_cast<const char*>(vec.data()), length * sizeof(int32_t));
//}
//
//void saveFuncDat() {
//    int16_t int1 = 3;
//    int16_t int2 = 3;
//    std::string str1 = "first.dat";
//    std::string str2 = "second.dat";
//    std::string str3 = "third.dat";
//
//    std::string filename = "func.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//
//    writeStringToFile(outFile, str1);
//    writeStringToFile(outFile, str2);
//    writeStringToFile(outFile, str3);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//
//}
//
//void saveFirstData() {
//    int16_t int1 = 7;
//    int16_t int2 = 0;
//    std::vector<int32_t> vec1 = { 0, 1, 2, 3, 5, 6, 7 };
//    std::vector<int32_t> vec2 = { 0, 3, 3, 3, 4, 4, 0 };
//
//    std::string filename = "first.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//
//    writeVectorToFile(outFile, vec1);
//
//    writeVectorToFile(outFile, vec2);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveSecondData() {
//    int16_t int1 = 2;
//    int16_t int2 = 1;
//    std::vector<int32_t> vec1 = { 3, 5 };
//
//    std::string filename = "second.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveThirdData() {
//    int16_t int1 = 4;
//    int16_t int2 = 2;
//    std::vector<int32_t> vec1 = { 0, 5, 6, 7 };
//
//    std::string filename = "third.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//void saveFourthData() {
//    int16_t int1 = 5;
//    int16_t int2 = 3;
//    std::vector<int32_t> vec1 = { 2, 4, 8, 10, 12 };
//    std::vector<int32_t> vec2 = { 20, 15, 10, 5, 0 };
//
//    std::string filename = "fourth.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//    writeVectorToFile(outFile, vec2);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveFifthData() {
//    int16_t int1 = 3;
//    int16_t int2 = 1;
//    std::vector<int32_t> vec1 = { 1, 3, 5 };
//
//    std::string filename = "fifth.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void saveSixthData() {
//    int16_t int1 = 6;
//    int16_t int2 = 2;
//    std::vector<int32_t> vec1 = { 7, 14, 21 };
//
//    std::string filename = "sixth.dat";
//
//    std::ofstream outFile(filename, std::ios::binary);
//
//    if (!outFile) {
//        std::cerr << "Error opening file for writing!" << std::endl;
//        return;
//    }
//
//    writeIntToFile(outFile, int1);
//    writeIntToFile(outFile, int2);
//    writeVectorToFile(outFile, vec1);
//
//    outFile.close();
//
//    std::cout << "Binary file created successfully!" << std::endl;
//}
//
//void testMaxPartialFunction(PartialFunctionOperation& collection) {
//    MaximumOfPartialFunctions maxFunc(collection);
//
//    std::cout << "Test MaxPartialFunction:" << std::endl;
//
//
//    for (int i = -2; i < 10; i++)
//    {
//        Pair<bool, int32_t> result = maxFunc.evaluate(i);
//        std::cout << "executeFunc(: " << i << "):" << "Is defined: " << result.getLhs() << " " << "res: " << result.getRhs() << std::endl;
//    }
//
//    //  std::cout << "isDefined(INT32_T MAX ): " << std::boolalpha << maxFunc.executeFunc(FunctionConstants::MAX_VALUE+1).isDef << maxFunc.executeFunc(FunctionConstants::MAX_VALUE+1).res << std::endl;
//}
//
//void testMinPartialFunction(PartialFunctionOperation& collection) {
//    MinimumOfPartialFunctions minFunc(collection);
//
//    std::cout << "Test MinPartialFunction:" << std::endl;
//
//    for (int i = -2; i < 10; i++)
//    {
//        Pair<bool, int32_t> result = minFunc.evaluate(i);
//        std::cout << "executeFunc(: " << i << "):" << "Is defined: " << result.getLhs() << " " << "res: " << result.getRhs() << std::endl;
//    }
//
//    //std::cout << "isDefined(INT32_T MAX ): " << std::boolalpha << maxFunc.executeFunc(FunctionConstants::MAX_VALUE + 1).isDef << maxFunc.executeFunc(FunctionConstants::MAX_VALUE + 1).res << std::endl;
//}
//void testPartialFunctionCollection() {
//    Vector<int32_t> undefinedPoints;
//    undefinedPoints.pushBack(1);
//    undefinedPoints.pushBack(2);
//    undefinedPoints.pushBack(3);
//
//    Vector<int32_t> definedPoints;
//    definedPoints.pushBack(4);
//    definedPoints.pushBack(5);
//    definedPoints.pushBack(6);
//
//    BaseCriteria* criterion1 = new NotDefinedAtPoints_PartialFunctionCriteria(undefinedPoints, 3);
//    BaseCriteria* criterion2 = new DefinedForAll_PartialFunctionCriteria(definedPoints, 3);
//
//    PartialFunctionByCriteria* func1 = new PartialFunctionByCriteria(criterion1);
//    PartialFunctionByCriteria* func2 = new PartialFunctionByCriteria(criterion2);
//
//    PartialFunctionOperation collection;
//
//    // Add functions to the collection
//    collection.addFunc(func1);
//    collection.addFunc(func2);
//
//    std::cout << "Test PartialFunctionCollection:" << std::endl;
//
//    // Now test max and min functions using the collection
//   // testMaxPartialFunction(collection);
//     testMinPartialFunction(collection);
//
//     // Clean up
//    delete criterion1;
//    delete criterion2;
//    delete func1;
//    delete func2;
//}
//
//int main() {
//    saveFuncDat();
//    saveFirstData();
//    saveSecondData();
//    saveThirdData();
//    saveFourthData();
//    saveFifthData();
//    saveSixthData();
//
//    testPartialFunctionCollection();
//
//    UserInterface UI;
//    return 0;
//}
