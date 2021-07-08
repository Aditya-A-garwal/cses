#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	vector<int> w(n + 1), v(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(x + 1));

	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) cin >> v[i];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= x; j++)
		{
			if(i == 0 or j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i-1][j];
			if(j - w[i] >= 0)
				dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
		}
	}

	cout << dp[n][x] << '\n';

	// we can either include the current one or not
	// if we include the current one, dp[i][j] = v[i] + dp[]
	// if we dont include the current one, dp[i][j] = dp[i-1][j]
	// we take the max of both ans set it to that


	return 0;
}