#include <iostream>
using namespace std;
const int FenceCost = 35, WayCost = 20, WayWide = 3;
const double PI = 3.14;
class Ring {
    public:
        Ring();
        Ring(double _radius);
        Ring(const Ring &t);
        ~Ring();
        void GetPrice();
    private:
        double radius;
        double fence, way;
};
Ring::Ring() {
    radius = 1;
    fence = 2 * PI * (2 * radius + WayWide) * FenceCost;
    way = PI * ((radius + WayWide) * (radius + WayWide) - radius * radius);
}
Ring::Ring(double _radius) {
    radius = _radius;
    fence = 2 * PI * (2 * radius + WayWide) * FenceCost;
    way = PI * ((radius + WayWide) * (radius + WayWide) - radius * radius);
}
Ring::Ring(const Ring &t) {
    radius = t.radius;
    fence = t.fence;
    way = t.way;
}
Ring::~Ring() {
    
}
void Ring::GetPrice() {
    printf("r = %.2lf FenceCost = %.2lf WayCost = %2lf\n\n", radius, fence, way);
}
int main() {
    Ring t1;
    t1.GetPrice();
    Ring t2(2);
    t2.GetPrice();
    Ring t(5);
    Ring t3(t);
    t3.GetPrice();
    return 0;
}