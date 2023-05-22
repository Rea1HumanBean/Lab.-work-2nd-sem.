#include <iostream>
#include <cmath>
#define M_PI 3.14159

struct Point {
    int x;
    int y;
};

class Shape {
public:
    int** arr;
    double area;
    const int len;

    Shape(int _array) : area(0),len(_array) {
        arr = new int* [_array];
        for (int i = 0; i < _array; i++)
        {
            arr[i] = new int[2];
        }
    }

    void Define_coordinate() {
        for (int i = 0; i < len; i++) {
            for (int k = 0; k < 2; k++) {
                if (k == 0)
                    std::cout << "Enter the X coordinate - ";
                else
                    std::cout << "Enter the Y coordinate - ";

                std::cin >> arr[i][k];
            }
        }
    }

    ~Shape() {
        for (int i = 0; i < len; i++)
            delete arr[i];
    }
};

class Triangle : public Shape {
    Point Vect[3];
    double lenght_vect[3];
public:
    Triangle(int len) :Shape(len) {
        try {
            if (len != 3) {
                throw std::out_of_range("Error:There are only three points in a triangle ");
            }
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: There are only three points in a triangle" << '\n';
            exit(-1);
        }
    }

    double Area() {
        double semi_p = 0;
        for (int k = 0; k < len; k++) {
            int j = (k + 1) % 3;
            Vect[k].x = arr[j][0] - arr[k][0];
            Vect[k].y = arr[j][1] - arr[k][1];
            lenght_vect[k] = sqrt((pow(Vect[k].x, 2) + pow(Vect[k].y, 2)));
            semi_p += lenght_vect[k];
        }
        semi_p = semi_p / 2;
        area = sqrt(semi_p * (semi_p - lenght_vect[0]) * (semi_p - lenght_vect[1]) * (semi_p - lenght_vect[2]));
        return area;
    }
};

class Circle: public Shape {
    Point Vect[2];
    double radius;
public:
    Circle(int len) :Shape(len) {
        try {
            if (len != 2) {
                throw std::out_of_range("Error:There are only two points in a circle ");
            }
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: There are only two points in a cicrle" << '\n';
            exit(-1);
        }
    }

    double Area() {
        Vect->x = arr[1][0] - arr[0][0];
        Vect->y = arr[1][1] - arr[0][1];
        radius = sqrt((pow(Vect->x, 2) + pow(Vect->y, 2)));
        area = M_PI * pow(radius,2);
        return area;
    }
};

class Rectangle : public Shape {
    Point Vect[1];
    double lenght_vec[2];
public:
    Rectangle(int len) :Shape(len) {
        try {
            if (len != 2) {
                throw std::out_of_range("Error:There are two three points in a rectangle ");
            }
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: You only need the coordinates of two opposite points" << '\n';
            exit(-1);
        }
    }

    double Area() {
        Vect->x = arr[1][0] - arr[0][0];
        Vect->y = arr[1][1] - arr[0][1];
        lenght_vec[0] = sqrt(pow(Vect->x, 2));
        lenght_vec[1] = sqrt(pow(Vect->y, 2));
        area = lenght_vec[0] * lenght_vec[1];
        return area;
    }
};

int main() {
      Triangle A(3);
      A.Define_coordinate();
      std::cout << A.Area() << std::endl;

      Circle B(2);
      B.Define_coordinate();
      std::cout << B.Area() << std::endl;

      Rectangle C(2);
      C.Define_coordinate();
      std::cout << C.Area() << std::endl;

}
