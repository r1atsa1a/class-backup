#include <iostream>
using namespace std;
class Complex {
    public:
        Complex();
        Complex(int _f, int _s);
        Complex(const Complex &t);
        ~Complex();
        void Add(Complex t);
        void Show();
    private:
        int f, s;
};
Complex::Complex() {
    f = 0;
    s = 0;
}
Complex::Complex(int _f, int _s) {
    f = _f;
    s = _s;
}
Complex::Complex(const Complex &t) {
    f = t.f;
    s = t.s;
}
Complex::~Complex() {
    
}
void Complex::Add(Complex t) {
    printf("(%d+%di)+(%d+%di)=", f, s, t.f, t.s);
    f += t.f;
    s += t.s;
    printf("(%d+%di)\n", f, s);
}
void Complex::Show() {
    if (s >= 0) printf("%d+%di\n", f, s);
    else printf("%d%di\n", f, s);
}
int main() {
    Complex t1;
    t1.Show();
    Complex t2(1, -2);
    t2.Show();
    Complex t(3, 4);
    Complex t3(t);
    t3.Show();
    t3.Add(t1);
    t3.Show();
    return 0;
}