#include <iostream>
#include <list>
using namespace std;
int main() {
    int sum;
    list<int> ilist;
    for (int i = 1; i <= 100; i ++) {
        ilist.push_back(i);
        sum += i;
    }
    list<int>::iterator it = ilist.begin();
    while (it != ilist.end()) {
        cout << *it << " ";
        ++ it;
    }
    cout << '\n' << "SUM: " << sum << '\n';
    return 0;
}