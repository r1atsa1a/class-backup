#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
const int M = 35; 
int main() {
    IOS
    LL dpA[M], dpB[M];
    dpA[0] = 1, dpB[0] = 0;
    for (int i = 1; i <= 33; i ++) {
        dpA[i] = 3 * dpA[i - 1] + 2 * dpB[i - 1];
        dpB[i] = dpA[i - 1] + dpB[i - 1];
    }
    int n;
    while (cin >> n) {
        if (n == -1) break;
        cout << dpA[n] << ", " << dpB[n] << '\n';
    }
    return 0;
}