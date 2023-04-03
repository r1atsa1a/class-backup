#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<char> is;
    for (char i = 'a'; i <= 'z'; i ++) is.push(i);
    while (is.size()) {
        cout << is.top() << " ";
        is.pop();
    }
    return 0;
}