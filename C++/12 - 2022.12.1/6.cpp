#include <iostream>
#include <map>
using namespace std;
class Stu {
    public:
        int price;
        string name, pub;
        Stu(string _name, string _pub, int _price) {
            name = _name;
            pub = _pub;
            price = price;
        }
};
int main() {
    Stu t1_1("Book1_1", "Pub1_1", 50);
    Stu t1_2("Book1_2", "Pub1_2", 80);
    Stu t1_3("Book1_3", "Pub1_3", 70);
    Stu t1_4("Book1_4", "Pub1_4", 60);
    Stu t1_5("Book1_5", "Pub1_5", 90);
    multimap<string, Stu> imp1;
    imp1.insert(make_pair("73457345774", t1_1));
    imp1.insert(make_pair("78968358475", t1_2));
    imp1.insert(make_pair("78634578645", t1_3));
    imp1.insert(make_pair("78354738845", t1_4));
    imp1.insert(make_pair("78345737745", t1_5));
    for (multimap<string, Stu>::iterator it = imp1.begin(); it != imp1.end(); ++ it) cout << (*it).first << " " << (*it).second.name << " " << (*it).second.pub << " " << (*it).second.price << '\n';
    return 0;
}