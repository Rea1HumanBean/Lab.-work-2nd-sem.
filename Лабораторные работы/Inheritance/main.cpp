#define Pi 3.1415

#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    int x = 0;
    int y = 0;
};

enum class Color {
    White,
    Red,
    Black
};

std::ostream& operator<<(std::ostream& os, const Color& color) {
    switch (color) {
    case Color::White:
        os << "White";
        break;
    case Color::Red:
        os << "Red";
        break;
    case Color::Black:
        os << "Black";
        break;
    }
    return os;
}

class Object {
protected:
    std::vector<Point> coord;
    Color paint;
public:
    Object(std::vector<Point> _coord ,Color _paint): coord(_coord), paint(_paint) {
        this->coord = _coord;
        this->paint = _paint;
    }

    virtual double area() = 0;
};

class Triangle : public Object {
    int quantity = 3;
    std::vector<Point> vectors;
public:
    Triangle(std::vector<Point> coord, Color color): Object(coord, paint) {
        Point pos;
        for (int i = 0; i < quantity; i++) {
            int j = (i + 1) % 3;
            pos.x = coord[j].x - coord[i].x;
            pos.y = coord[j].y - coord[i].y;
            vectors.push_back(pos);
        }
    }

    virtual double area() override {
        double sum = 0;
        for (int i = 0; i < quantity; i++) {
            sum += sqrt(pow(vectors[i].x,2) + pow(vectors[i].y,2));
        }
        sum = sum / 2;
        double area = sum;
        for (int i = 0; i < quantity; i++) {
            area *= sum - sqrt(pow(vectors[i].x, 2) + pow(vectors[i].y, 2));
        }
        area = sqrt(area);
        std::cout << "Triangle area is - " << area << std::endl;
        return area;
    }

    virtual ~Triangle() {};
};

class  Rectangle :public Object {
    int quantity = 2;
    std::vector<Point> vectors;
public:
    Rectangle(std::vector<Point> coord, Color color): Object(coord, color) {
        Point pos;
        pos.x = coord[1].x - coord[0].x;
        pos.y = 0;
        vectors.push_back(pos);
        pos.x = 0;
        pos.y = coord[1].y - coord[0].y;
        vectors.push_back(pos);
    }

    virtual double area() override {
        double area = sqrt(pow(vectors[0].x, 2) + pow(vectors[0].y, 2)) * sqrt(pow(vectors[1].x, 2) + pow(vectors[1].y, 2));
        std::cout << "Rectangle area is - " << area << std::endl;
        return area;
    }

    virtual ~Rectangle() {};
};

class  Circle : public Object {
    Point vector;
public:
    Circle(std::vector<Point> coord, Color color) : Object(coord, color) {
        vector.x = coord[1].x - coord[0].x;
        vector.y = coord[1].y - coord[0].y;
    }

    double area() override {
        double area = Pi * sqrt(pow(vector.x, 2) + pow(vector.y, 2));
        std::cout << "Circle area is - " << area << std::endl;
        return area;
    }

    virtual ~Circle() {};
};

int main() {
    std::vector<Object*> figures;

    std::vector<Point> Tr;
    Tr.push_back({ 0,0 });
    Tr.push_back({ 5,3 });
    Tr.push_back({ 5,5 });

    std::vector<Point> R;
    R.push_back({ 1,1 });
    R.push_back({ 4,3 });

    std::vector<Point> C;
    C.push_back({ 0,0 });
    C.push_back({ 3,0 });

    Object* Trgl = new Triangle(Tr, Color::White);
    Object* Rec = new Rectangle(R, Color::Red);
    Object* Cr = new Circle(C, Color::Black);

    figures.push_back(Trgl);
    figures.push_back(Rec);
    figures.push_back(Cr);

    for (int i = 0; i < figures.size(); i++)
    {
        figures[i]->area();
    }
}
