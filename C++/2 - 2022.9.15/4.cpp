#include <iostream>
using namespace std;
void whiletype() {
    cout << "while version" << endl;
    int i = 10;
    while (i <= 999) {
        i ++;
        if (i < 100 && !(i % 11)) cout << i << " ";
        if (i > 100 && i % 10 == i / 100) cout << i << " ";
    }
    puts("");
}
void dowhiletype() {
    cout << "do-while version" << endl;
    int i = 10;
    do {
        i ++;
        if (i < 100 && !(i % 11)) cout << i << " ";
        if (i > 100 && i % 10 == i / 100) cout << i << " ";
    }while (i <= 999);
    puts("");
}
void fortype() {
    cout << "for version" << endl;
    for (int i = 11; i <= 999; i ++) {
        if (i < 100 && !(i % 11)) cout << i << " ";
        if (i > 100 && i % 10 == i / 100) cout << i << " ";
    }
    puts("");
}
int main() {
    whiletype();
    dowhiletype();
    fortype();
    return 0;
}