#include <iostream>

struct empty { //1
};

struct test1 {
	int number; //4
};

struct test2 {
	char symbol; //1
	int number; //4
}; //1+3+4=8

struct test3 {
	char symbol; //1
	short sh; //2
	int number; //4
}; //1+2+1+4 = 8

struct test4 {
	char symbol1; //1
	int number; //4
	char symbol2; //1
}; //1+3pad+4+1+3pad = 12

struct student {
	char* name; //4
	int* grades; //4
}; //8

struct test5 {
	char a[5]; //5
	int b; //4
	double c; //8
}; //5+3+4+4+8 = 24

struct test6 {
	char a[3]; //3
	short b; //2
	double c[4]; //8 * 4 = 32
	char d; //1
}; //3+1+2+2+32+1+7 = 48
struct A
{
	double c; //8
	char b; //1
}; //8 + 1 + 7 = 16;

struct B
{
	char c; //1
};

struct C
{
	A obj; //16, alignof(A) = 8
	B obj2; //1, alignof(B) = 1
}; //alignof(C) = 8, 16 + 1 + 7 = 24;
struct A_
{
	double c; //8
	char b; //1
	int k; //4
	char s; //1
}; //alignof(A_) = 8, 8 + 1 + 3 + 4 + 1 + 7 = 24

struct B_
{
	int a; //4
	char c; //1
	char d; //1
	float f; //4
}; //alignof(B_) = 4, 4 + 1 + 1 + 2 + 4 = 12

struct C_
{
	char arr[3]; //3
	float f; //4
}; //alignof(C_) = 4, 3+1+4 = 8;

struct D_
{
	C_ obj1; //8, alignof(C_) = 4
	A_ obj2; //24, alignof(A_) = 8
	int i; //4
	char c; //1
	B_ obj3; //12, alignof(B_) = 4
	bool b; //1
	double d; //8
}; //alignof(D_) = 8, 8 + 24 + 4 + 1 + 3 + 12 + 1 + 3 + 8 = 64

int main() {
	std::cout << sizeof(empty) << std::endl; //1
	std::cout << alignof(empty) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(test1) << std::endl; //4
	std::cout << alignof(test1) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(test2) << std::endl; //8
	std::cout << alignof(test2) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(test3) << std::endl; //8
	std::cout << alignof(test3) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(test4) << std::endl; //12
	std::cout << alignof(test4) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(student) << std::endl; //8
	std::cout << alignof(student) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(test5) << std::endl; //24
	std::cout << alignof(test5) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(test6) << std::endl; //48
	std::cout << alignof(test6) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(A) << std::endl; //16
	std::cout << alignof(A) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(B) << std::endl; //1
	std::cout << alignof(B) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(C) << std::endl; //24
	std::cout << alignof(C) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(A_) << std::endl; //24
	std::cout << alignof(A_) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(B_) << std::endl; //12
	std::cout << alignof(B_) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(C_) << std::endl; //8
	std::cout << alignof(C_) << std::endl;
	std::cout << std::endl;
	std::cout << sizeof(D_) << std::endl; //64
	std::cout << alignof(D_) << std::endl;
	std::cout << std::endl;
}