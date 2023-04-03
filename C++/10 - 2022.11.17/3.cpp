#include <iostream>
using namespace std;
typedef void (*F)(void);
typedef void (*G)(void);
class Class {
    public:
        virtual void F() { cout << "Class::F" << endl; }
        virtual void G() { cout << "Class::G" << endl; }
};
class SubClass : public Class {

};
int main() {
    SubClass t;
    F ptrF = (F)*((int*)*(int*)(&t + 0) + 0);
    ptrF();
    G ptrG = (G)*((int*)*(int*)(&t + 0) + 1);
    ptrG();
    return 0;
}
