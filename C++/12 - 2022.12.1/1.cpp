#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n1 = 5;
    double averVal1 = 0;
    deque<double> idq1;
    for (int i = 1; i <= n1; i ++) {
        double x = i * 1.1;
        idq1.push_back(x);
        averVal1 += x;
    }
    averVal1 /= n1;
    for (deque<double>::iterator it = idq1.begin(); it != idq1.end(); ++ it) cout << *it << " ";
    cout << "Average = " << averVal1 << '\n';
    int n2 = 10;
    double averVal2 = 0;
    deque<double> idq2;
    for (int i = 1; i <= n2; i ++) {
        double x = i * 1.5;
        idq2.push_back(x);
        averVal2 += x;
    }
    averVal2 /= n2;
    for (deque<double>::iterator it = idq2.begin(); it != idq2.end(); ++ it) cout << *it << " ";
    cout << "Average = " << averVal2 << '\n';
    return 0;
}