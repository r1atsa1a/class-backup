#include <iostream>
using namespace std;
class Point {
    public:
        Point();
        Point(int _x, int _y);
        Point(const Point &t);
        ~Point();
        int GetX();
        int GetY();
        void InX(int _x);
        void InY(int _y);
    private:
        int x, y;
};
Point::Point() {
    x = 0; y = 0;
}
Point::Point(int _x, int _y) {
    x = _x; y = _y;
}
Point::Point(const Point &t) {
    x = t.x; y = t.y;
}
Point::~Point() {
    
}
int Point::GetX() {
    return x;
}
int Point::GetY() {
    return y;
}
void Point::InX(int _x) {
    x = _x;
}
void Point::InY(int _y) {
    y = _y;
}
class Rectangle {
    public:
        Rectangle();
        Rectangle(Point _l_d, Point _r_u);
        Rectangle(const Rectangle &t);
        ~Rectangle();
        void Show();
    private:
        Point l_d, r_u;
        int area;
};
Rectangle::Rectangle() {
    Point t1, t2;
    l_d.InX(t1.GetX()); l_d.InY(t1.GetY());
    r_u.InX(t2.GetX()); r_u.InY(t2.GetY());
    area = (r_u.GetX() - l_d.GetX()) * (r_u.GetY() - l_d.GetY());
}
Rectangle::Rectangle(Point _l_d, Point _r_u) {
    l_d.InX(_l_d.GetX()); l_d.InY(_l_d.GetY());
    r_u.InX(_r_u.GetX()); r_u.InY(_r_u.GetY());
    area = (r_u.GetX() - l_d.GetX()) * (r_u.GetY() - l_d.GetY());
}
Rectangle::Rectangle(const Rectangle &t) {
    l_d = t.l_d; r_u = t.r_u;
    area = t.area;
}
Rectangle::~Rectangle() {
    
}
void Rectangle::Show() {
    printf("(%d, %d)&(%d, %d)'s area: %d\n", l_d.GetX(), l_d.GetY(), r_u.GetX(), r_u.GetY(), area);
}
int main() {
    Rectangle t1;
    t1.Show();
    Point p1(1, 2); Point p2(3, 4);
    Rectangle t2(p1, p2);
    t2.Show();
    Point p3(5, 7), p4(9, 11);
    Point p5(p3), p6(p4);
    Rectangle t(p5, p6);
    Rectangle t3(t);
    t3.Show();
    return 0;
}