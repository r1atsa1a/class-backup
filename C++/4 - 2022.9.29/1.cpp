#include <iostream>
#include <cmath>
using namespace std;
class Triangle {
    public:
        Triangle();
        Triangle(double _x, double _y, double _z);
        Triangle(const Triangle &t);
        ~Triangle();
        double GetArea();
        double GetLength();
    private:
        double x, y, z;
        double area, len;
};
Triangle::Triangle() {
    x = 1; y = 1; z = 1;
    len = x + y + z;
    double p = len / 2.0;
    area = sqrt(p * (p - x) * (p - y) * (p - z));
}
Triangle::Triangle(double _x, double _y, double _z) {
    x = _x; y = _y; z = _z;
    len = x + y + z;
    double p = len / 2.0;
    area = sqrt(p * (p - x) * (p - y) * (p - z));
}
Triangle::Triangle(const Triangle &t) {
    x = t.x; y = t.y; z = t.z;
    area = t.area; len = t.len;
}
Triangle::~Triangle() {
    
}
double Triangle::GetArea() {
    printf("area = %.2lf len = %.2lf\n\n", area, len);
    return area;
}
double Triangle::GetLength() {
    printf("x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    return len;
}
int main() {
    Triangle t1;
    t1.GetLength(); t1.GetArea();
    Triangle t2(1, 1, 1);
    t2.GetLength(); t2.GetArea();
    Triangle t3(6, 8, 10);
    t3.GetLength(); t3.GetArea();
    return 0;
}