#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 55;
int main() {
    IOS
    int dp[M];
    dp[1] = 1, dp[2] = 2, dp[3] = 3;
    for (int i = 4; i <= 54; i ++)
        dp[i] = dp[i - 1] + dp[i - 3];
    int n;
    while (cin >> n) {
        if (!n) break;
        cout << dp[n] << '\n';
    }
    return 0;
}