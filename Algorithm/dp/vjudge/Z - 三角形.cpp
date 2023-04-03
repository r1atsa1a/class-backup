#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e4 + 10;
int main() {
    IOS
    int dp[M];
    dp[1] = 2;
    for (int i = 2; i <= 10000; i ++)
        dp[i] = dp[i - 1] + 6 * (i - 1);
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}