#include <iostream>
#include "Interval.h"

namespace {
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }

        double temp = sqrt(n);

        for (int i = 2; i <= temp; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int reverse(int n) {
        int result = 0;
        while (n != 0) {
            result = (result * 10 + n % 10);
            n /= 10;
        }
        return result;
    }

    bool isPalindrome(int n) {
        return n == reverse(n);
    }
}

Interval::Interval() : Interval(0,0) {}
Interval::Interval(int a, int b) {
    setA(a);
    setB(b);
}

void Interval::setA(int a) {
    if (a > this->b) {
        this->a = 0;
    }
    else {
        this->a = a;
    }
}
void Interval::setB(int b) {
    if (b < this->a) {
        this->b = 0;
    }
    else {
        this->b = b;
    }
}

int Interval::getA() const {
    return a;
}
int Interval::getB() const {
    return b;
}

unsigned Interval::getIntervalLength() const {
    return abs(b - a);
}
bool Interval::isInInterval(int n) const {
    return n >= a && n <= b;
}
unsigned Interval::getCountBasedOnCondition(bool(*pred)(int)) const {
    unsigned count = 0;
    for (int i = a; i <= b; i++) {
        if (pred(i)) {
            count++;
        }
    }
    return count;
}

unsigned Interval::getPrimesCount() const {
    return getCountBasedOnCondition(isPrime);
}
unsigned Interval::getPalindomesCount() const {
    return getCountBasedOnCondition(isPalindrome);
}

bool Interval::isSubInterval(const Interval& other) const {
    return a >= other.a && b <= other.b;
}

Interval intersectIntervals(const Interval& lhs, const Interval& rhs) {
    int newA = std::max(lhs.getA(), rhs.getA());
    int newB = std::min(lhs.getB(), rhs.getB());

    if (newA > newB)
        throw "Error";

    return Interval(newA, newB);
}

int main()
{
    std::cout << "Hello World!\n";
}
