#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e3 + 10;
int main() {
    IOS
    int dpA[M], dpB[M];
    dpA[1] = 2, dpB[1] = 2;
    for (int i = 2; i <= 1000; i ++)
        dpA[i] = dpA[i - 1] + i;
    for (int i = 2; i <= 1000; i ++)
        dpB[i] = dpB[i - 1] + dpA[i - 1];
    int n;
    while (cin >> n) cout << dpB[n] << '\n';
    return 0;
}