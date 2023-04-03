#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> iv;
    for (int i = 100; i <= 200; i ++)
        iv.push_back(i);
    vector<int>::iterator it = iv.begin();
    while (it != iv.end()) {
        if (!(*it % 7)) cout << *it << " ";
        ++ it;
    }
    return 0;
}