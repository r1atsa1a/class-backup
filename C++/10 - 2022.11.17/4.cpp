#include <iostream>
using namespace std;
typedef void (*F)(void);
typedef void (*G)(void);
class Base1 {
  virtual void F() { cout << "Base1::F" << endl; }
  virtual void G() { cout << "Base1::G" << endl; }
};
class Base2 {
  virtual void F() { cout << "Base2::F" << endl; }
  virtual void G() { cout << "Base2::G" << endl; }
};
class Base3 {
  virtual void F() { cout << "Base3::F" << endl; }
  virtual void G() { cout << "Base3::G" << endl; }
};
class Drive : public Base1, public Base2, public Base3 {
  //
};
int main() {
    Drive t;
    F ptrF_Base1 = (F)*((int*)*((int*)(&t + 0) + 0) + 0);
    ptrF_Base1();
    G ptrG_Base1 = (G)*((int*)*((int*)(&t + 0) + 0) + 1);
    ptrG_Base1();
    F ptrF_Base2 = (F)*((int*)*((int*)(&t + 0) + 1) + 0);
    ptrF_Base2();
    G ptrG_Base2 = (G)*((int*)*((int*)(&t + 0) + 1) + 1);
    ptrG_Base2();
    F ptrF_Base3 = (F)*((int*)*((int*)(&t + 0) + 2) + 0);
    ptrF_Base3();
    G ptrG_Base3 = (G)*((int*)*((int*)(&t + 0) + 2) + 1);
    ptrG_Base3();
    return 0;
}
