#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Stu {
    public:
        string name;
        int price;
        Stu(string _name, int _price) : name(_name), price(_price) {}
};
int main() {
    Stu t1_1("Book1_1", 10), t1_2("Book1_2", 20), t1_3("Book1_3", 30);
    queue<Stu> t1;
    t1.push(t1_1);
    t1.push(t1_2);
    t1.push(t1_3);
    while (t1.size()) {
        cout << t1.front().name << " " << t1.front().price << '\n';
        t1.pop();
    }
    Stu t2_1("Book2_1", 10), t2_2("Book2_2", 20), t2_3("Book2_3", 30);
    queue<Stu> t2;
    t2.push(t2_1);
    t2.push(t2_2);
    t2.push(t2_3);
    while (t2.size()) {
        cout << t2.front().name << " " << t2.front().price << '\n';
        t2.pop();
    }
    Stu t3_1("Book3_1", 10), t3_2("Book3_2", 20), t3_3("Book3_3", 30);
    queue<Stu> t3;
    t3.push(t3_1);
    t3.push(t3_2);
    t3.push(t3_3);
    while (t3.size()) {
        cout << t3.front().name << " " << t3.front().price << '\n';
        t3.pop();
    }
    return 0;
}