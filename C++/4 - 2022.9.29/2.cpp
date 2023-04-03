#include <iostream>
using namespace std;
const double PI = 3.14;
class Circle {
    public:
        Circle();
        Circle(double _radius);
        Circle(const Circle &t);
        ~Circle();
        void GetArea();
    private:
        double radius;
};
Circle::Circle() {
    radius = 1.0;
}
Circle::Circle(double _radius) {
    radius = _radius;
}
Circle::Circle(const Circle &t) {
    radius = t.radius;
}
Circle::~Circle() {
    
}
void Circle::GetArea() {
    printf("radius = %.2lf area = %.2lf\n\n", radius, PI * radius * radius);
}
int main() {
    Circle t1;
    t1.GetArea();
    Circle t2(2);
    t2.GetArea();
    Circle t(5);
    Circle t3(t);
    t3.GetArea();
    return 0;
}