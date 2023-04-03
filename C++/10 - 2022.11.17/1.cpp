#include <iostream>
using namespace std;
class Employee {
    public:
        int sum, days;
        Employee(int _sum, int _days) : sum(_sum), days(_days) {}
        virtual void Disp() = 0;
};
class Sales : public Employee {
    public:
        Sales(int _sum, int _days) : Employee(_sum, _days) {}
        void Disp() {
            cout << "销售额为：";
            cout << sum * days << '\n';
        }
};
class Engineer : public Employee {
    public:
        Engineer(int _sum, int _days) : Employee(_sum, _days) {}
        void Disp() {
            cout << "销售额为：";
            cout << sum * days << '\n';
        }
};
int main() {
    Sales t1(500, 25);
    t1.Disp();
    Engineer t2(300, 30);
    t2.Disp();
    return 0;
}