#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e3 + 10;
string Add(string A, string B) {
    int t = 0;
    string C;
	for (int i = 0; i < A.size(); i ++) {
		t += A[i] - '0';
		if (i < B.size()) t += B[i] - '0';
		C.push_back(t % 10 + '0');
		t /= 10;
	}
	if (t) C.push_back(1 + '0');
	return C;
}
int main() {
    IOS
    string dp[M];
    dp[0] = "1"; dp[1] = "1";
    dp[2] = "2"; dp[3] = "4";
    for (int i = 4; i <= 1000; i ++)
        dp[i] = Add(Add(dp[i - 1], dp[i - 2]), dp[i - 4]);
    int n;
    while (cin >> n) {
        for (int i = dp[n].size() - 1; i >= 0; i --)
            cout << dp[n][i];
        cout << '\n';
    }
    return 0;
}