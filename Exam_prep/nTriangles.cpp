//Triangles simple example

#include <iostream>

namespace Point {
    struct point {
        int x = 0;
        int y = 0;
    };

    double getDist(const point& lhs, const point& rhs) {
        int dx = lhs.x - rhs.x;
        int dy = lhs.y - rhs.y;

        return sqrt((dx * dx) + (dy * dy));
    }

    void printPoint(const point& obj) {
        std::cout << '(' << obj.x << ',' << obj.y <<')' << std::endl;
    }

    void readPoint(point& obj) {
        std::cin >> obj.x >> obj.y;
    }
}


namespace Figure {

    struct Triangle {
        Point::point point1;
        Point::point point2;
        Point::point point3;
    };

    void printTriangle(const Triangle& tr) {
        Point::printPoint(tr.point1);
        Point::printPoint(tr.point2);
        Point::printPoint(tr.point3);
    }

    void readTriangle(Triangle& tr) {
        Point::readPoint(tr.point1);
        Point::readPoint(tr.point2);
        Point::readPoint(tr.point3);
    }

    double getArea(const Triangle& tr) {
        double sideA = Point::getDist(tr.point1, tr.point2);
        double sideB = Point::getDist(tr.point2, tr.point3);
        double sideC = Point::getDist(tr.point1, tr.point3);

        double halfPer = (sideA + sideB + sideC) / 2;

        return sqrt(halfPer * (halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC));
    }

    void sortTriangles(Triangle* triangles, size_t count) {
        double* areas = new double[count];

        //fill areas
        for(size_t i = 0; i < count; i++) {
            areas[i] = getArea(triangles[i]);
        }

        for(size_t i = 0; i < count - 1; i++) {
            size_t minIndex = i;

            for(size_t j = i + 1; j < count; j++) {
                if(areas[j] < areas[minIndex]) {
                    minIndex = j;
                }
            }

            if(minIndex != i) {
                std::swap(areas[minIndex], areas[i]);
                std::swap(triangles[minIndex], triangles[i]);
            }
        }
        delete[] areas;
    }
}

int main() {
    Figure::Triangle* arr = new Figure::Triangle[5];
    Figure::readTriangle(arr[0]);
    Figure::readTriangle(arr[1]);
    Figure::readTriangle(arr[2]);
    Figure::readTriangle(arr[3]);
    Figure::readTriangle(arr[4]);

    Figure::sortTriangles(arr, 5);

    Figure::printTriangle(arr[0]);
    Figure::printTriangle(arr[1]);
    Figure::printTriangle(arr[2]);
    Figure::printTriangle(arr[3]);
    Figure::printTriangle(arr[4]);

}