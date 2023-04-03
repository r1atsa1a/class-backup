#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Point {
    private:
        int x, y;
    public:
        Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
        Point& operator= (Point t) {
            x = t.x;
            y = t.y;
            return *this;
        }
        Point operator+ (Point t) {
            return Point(x + t.x, y + t.y);
        }
        bool operator== (Point t) {
            if (x == t.x && y == t.y) return true;
            return false;
        }
        void operator+= (Point t) {
            x += t.x;
            y += t.y;
        }
        Point& operator++ () {
            x ++;
            y ++;
            return *this;
        }
        Point operator++ (int) {
            Point old = *this;
            ++(*this);
            return old;
        }
        friend ostream& operator<< (ostream& os, Point& t) {
            os << t.x << " " << t.y << '\n';
            return os;
        }
};
int main() {
    Point t1_1(1, 2), t1_2(3, 4);
    cout << t1_1 << t1_2;
    t1_1 = t1_2; cout << t1_1;
    t1_1 = t1_1 + 5; cout << t1_1;
    t1_1 += t1_2; cout << t1_1;
    t1_1 ++; cout << t1_1;

    Point t2_1(11, 2), t2_2(33, 4);
    cout << t2_1 << t2_2;
    t2_1 = t2_2; cout << t2_1;
    t2_1 = t2_1 + 1; cout << t2_1;
    t2_1 += t2_2; cout << t2_1;
    t2_1 ++; cout << t2_1;

    Point t3_1(12, 23), t3_2(34, 45);
    cout << t3_1 << t3_2;
    t3_1 = t3_2; cout << t3_1;
    t3_1 = t3_1 + 10; cout << t3_1;
    t3_1 += t3_2; cout << t3_1;
    t3_1 ++; cout << t3_1;
    
    return 0;
}