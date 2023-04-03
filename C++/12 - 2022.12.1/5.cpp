#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, pair<string, int>> imp1;
    imp1["202105010001"] = {"Mike1", 80};
    imp1["202105010042"] = {"Mike2", 65};
    imp1["202105010056"] = {"Mike3", 32};
    imp1["202105010015"] = {"Mike4", 92};
    imp1["202105010080"] = {"Mike5", 65};
    for (map<string, pair<string, int>>::iterator it = imp1.begin(); it != imp1.end(); ++ it) cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second << '\n';
    map<string, pair<string, int>> imp2;
    imp2["74986532"] = {"fytghb", 80};
    imp2["798489465132"] = {"e5yrhdfb", 65};
    imp2["4896513"] = {"wefsdc", 32};
    imp2["798465132"] = {"wefsdf", 92};
    imp2["798465145689"] = {"Miqefke5", 65};
    for (map<string, pair<string, int>>::iterator it = imp2.begin(); it != imp2.end(); ++ it) cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second << '\n';
    map<string, pair<string, int>> imp3;
    imp3["7465132"] = {"wges", 80};
    imp3["76835421"] = {"qefa", 65};
    imp3["7834587354"] = {"qrefadc", 32};
    imp3["734578345"] = {"y4wgrsd", 92};
    imp3["783549635487654"] = {"46jhegrwefq", 65};
    for (map<string, pair<string, int>>::iterator it = imp3.begin(); it != imp3.end(); ++ it) cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second << '\n';
    return 0;
}