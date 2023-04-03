#include <iostream>
using namespace std;
class Point {
    public:
        int x, y;
        Point():x(0), y(0){}
        void Set(int _x, int _y) {
            x = _x;
            y = _y;
        }
};
class ArrayOfPoint {
    public:
        ArrayOfPoint() {
            size = 0;
            ptr = NULL;
        }
        ArrayOfPoint(ArrayOfPoint &_AOP) {
            size = _AOP.size;
            ptr = new Point[_AOP.size];
            for (int i = 0; i < _AOP.size; i ++)
                ptr[i] = _AOP.ptr[i];
            cout << "Copy Success!" << '\n';
        }
        void SetData(Point *x, int n) {
            size = n;
            ptr = new Point[n];
            for (int i = 0; i < n; i ++) {
                ptr[i].x = x[i].x;
                ptr[i].y = x[i].y;
            }
        }
        void Disp() {
            for (int i = 0; i < size; i ++)
                cout << "{" << ptr[i].x << ", " << ptr[i].y << "} ";
            cout << '\n';
        }
    private:
        Point *ptr;
        int size;
};
int main() {
    int n1 = 5;
    Point t1[5];
    for (int i = 0; i < n1; i ++)
        t1[i].x = i, t1[i].y = i * n1;
    ArrayOfPoint tA1;
    tA1.SetData(t1, n1);
    ArrayOfPoint A1(tA1);
    A1.Disp();
    int n2 = 10;
    Point t2[10];
    for (int i = 0; i < n2; i ++)
        t2[i].x = i, t2[i].y = i * n2;
    ArrayOfPoint tA2;
    tA2.SetData(t2, n2);
    ArrayOfPoint A2(tA2);
    A2.Disp();
    int n3 = 8;
    Point t3[8];
    for (int i = 0; i < n3; i ++)
        t3[i].x = i, t3[i].y = i * n3;
    ArrayOfPoint tA3;
    tA3.SetData(t3, n3);
    ArrayOfPoint A3(tA3);
    A3.Disp();
    return 0;
}