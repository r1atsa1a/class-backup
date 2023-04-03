#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 110;
int main() {
	IOS
	int dp[M][M];
	string x, y;
	cin >> x >> y;
	dp[x.size()][0] = 0;
	dp[0][y.size()] = 0;
	for (int i = 1; i <= x.size(); i ++)
		for (int j = 1; j <= y.size(); j ++)
			if (x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j -  1]);
	cout << dp[x.size()][y.size()] << '\n';
	return 0;
}