#include <iostream>
using namespace std;
const double PI = 3.1415926;
class Figure {
    public:
        int x, y;
        Figure(int _x, int _y) : x(_x), y(_y) {}
        virtual void Area() = 0;
};
class Sphere : public Figure {
    public:
        Sphere(int _radius) : Figure(_radius, _radius) {}
        void Area() {
            cout << "圆形的面积：";
            cout << PI * x * x << '\n';
        }
};
class Rectangle : public Figure {
    public:
        Rectangle(int _x, int _y) : Figure(_x, _y) {}
        void Area() {
            cout << "长方形的面积：";
            cout << x * y << '\n';
        }
};
int main() {
    Sphere t1(5);
    t1.Area();
    Rectangle t2(2, 3);
    t2.Area();
    return 0;
}