#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 110, N = 1010;
int n, c;
int w[M], v[M], dp[M][N] = {0};
int main() {
	IOS
	cin >> n >> c;
	for (int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= c; j ++)
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
	cout << dp[n][c] << '\n';
	return 0;
}