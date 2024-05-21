#include <iostream>

namespace Point_ {

    struct Point {
        int x = 0;
        int y = 0;
    };

    void readPoint(Point& point) {
        std::cin >> point.x;
        std::cin >> point.y;
    }

    double getDist(const Point& p1, const Point& p2) {
        int dx = p1.x - p2.x;
        int dy = p1.y - p2.y;

        return sqrt(dx * dx + dy * dy);
    }

    void printPoint(const Point& point) {
        std::cout << "( " << point.x << ", " << point.y << ") " << std::endl;
    }
}

namespace Figure_ {

    using namespace Point_;
    struct Triangle {
        Point p1;
        Point p2;
        Point p3;
    };

    void readTriangle(Triangle& tr) {
        readPoint(tr.p1);
        readPoint(tr.p2);
        readPoint(tr.p3);
    }

    double getArea(const Triangle& tr) {
        double sideA = getDist(tr.p1, tr.p2);
        double sideB = getDist(tr.p2, tr.p3);
        double sideC = getDist(tr.p1, tr.p3);

        double halfPer = (sideA + sideB + sideC) / 2;

        return sqrt(halfPer * (halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC));
    }

    void printTriangle(const Triangle& tr) {
        printPoint(tr.p1);
        printPoint(tr.p2);
        printPoint(tr.p3);

        std::cout<<std::endl;
    }

    void sortTriangles(Triangle* trs, size_t count) {
        double* areas = new double[count];
        for (size_t i = 0; i < count; i++) {
            areas[i] = getArea(trs[i]);
        }

        for (size_t i = 0; i < count - 1; i++) {
            size_t minAreaIndex = i;

            for (size_t j = i + 1; j < count; j++) {
                if (areas[j] < areas[minAreaIndex]) {
                    minAreaIndex = j;
                }
            }

            if (minAreaIndex != i) {
                std::swap(trs[i], trs[minAreaIndex]);
                std::swap(areas[i], areas[minAreaIndex]);
            }
        }
        delete[] areas;
    }
}

int main()
{
    size_t size;
    std::cin >> size;

    Figure_::Triangle* trArr = new Figure_::Triangle[size];

    for (size_t i = 0; i < size; i++) {
        Figure_::readTriangle(trArr[i]);
    }

    Figure_::sortTriangles(trArr, size);

    for (size_t i = 0; i < size; i++) {
        Figure_::printTriangle(trArr[i]);
    }

    delete[] trArr;
}
