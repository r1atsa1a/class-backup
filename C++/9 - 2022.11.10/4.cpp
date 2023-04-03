#include <iostream>
#include <cmath>
using namespace std;
class Triangle {
    private:
        double x, y, z;
        double area;
    public:
        Triangle(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {
            double p = (x + y + z) / 2.0;
            area = sqrt(p * (p - x) * (p - y) * (p - z));
        }
        double operator+ (Triangle t) {
            double square = area + t.area;
            return square;
        }
        friend double operator+ (double now, Triangle t) {
            return now + t.area;
        }
};
int main() {
    Triangle t1_1(3, 4, 5);
    cout << t1_1 + t1_1 << '\n';
    
    Triangle t2_1(3, 4, 5), t2_2(2, 2, 2);
    cout << t2_1 + t2_2 << '\n';
    
    Triangle t3_1(3, 4, 5);
    cout << t3_1 + t3_1 + t3_1 << '\n';
    
    return 0;
}