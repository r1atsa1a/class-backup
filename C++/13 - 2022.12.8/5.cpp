#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
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
    Player p1("zhangsan", "ZAFU", 20, 1), p2("lisi", "ZJU", 19, 2), p3("wangwu", "HUD", 22, 3), c[10];
    ofstream ofs("5.txt", ios::out);
    multimap<int, Player> mp;
    mp.insert(make_pair(p1.no, p1));
    mp.insert(make_pair(p2.no, p2));
    mp.insert(make_pair(p3.no, p3));
    multimap<int, Player>::iterator ita = mp.begin();
    for (;ita != mp.end(); ++ ita) {
        ofs << ita->second.name << " " << ita->second.team << " " << ita->second.age << " " << ita->second.no << '\n';
    }
    ifstream ifs("5.txt", ios::in);
    vector<Player> ve;
    int i = 0;
    while(ifs >> c[i].name >> c[i].team >> c[i].age >> c[i].no) {
        ve.push_back(c[i]);
        i++;
    }
    vector<Player>::iterator it = ve.begin();
    for (; it != ve.end(); ++it) {
        cout << "name:" << it->name << "   team:" << it->team << "   age:" << it->age << "   no:" << it->no << '\n';
    }
    return 0;
}