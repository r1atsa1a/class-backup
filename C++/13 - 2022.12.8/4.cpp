#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
class Player {
    public:
        char *name, *team;
        int age, no;
        Player(char *na, char *t, int a, int n) {
            name = new char[strlen(na) + 2];
            team = new char[strlen(t) + 2];
            strcpy(name, na); strcpy(team, t);
            age = a; no = n;
        }
        Player() {
            name = new char[10];
            team = new char[10];
            age = 0; no = 0;
        }
        ~Player() {}
};
int main() {
    char s1[10] = "zhangsan";
    Player p1("zhangsan", "ZAFU", 20, 1), p2("lisi", "ZJU", 19, 2), p3("wangwu", "HUD", 22, 3), c;
    ofstream ofs("4.txt", ios::out);
    ofs << p1.name << " " << p1.team << " " << p1.age << " " << p1.no << '\n';
    ofs << p2.name << " " << p2.team << " " << p2.age << " " << p2.no << '\n';
    ofs << p3.name << " " << p3.team << " " << p3.age << " " << p3.no << '\n';
    ifstream ifs("4.txt", ios::in);
    for (int i = 0; i < 3; i++) {
        ifs >> c.name >> c.team >> c.age >> c.no;
        cout << "name:" << c.name << "   team:" << c.team << "   age:" << c.age << "   no:" << c.no << '\n';
    }
    return 0;
}