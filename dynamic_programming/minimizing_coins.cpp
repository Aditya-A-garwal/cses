#include<bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	vector<int> ar(n), dp(x + 1, INF);

	for(auto &e : ar) cin >> e;

	dp[0] = 0;
	for(int i = 1; i <= x; i++)
	{
		int ans = INF;
		for(int j = 0; j < n; j++)
		{
			if(i - ar[j] < 0) continue;
			ans = min(ans, dp[i - ar[j]]);
		}
		dp[i] = 1 + ans;
	}

	cout << ((dp[x] >= INF)?-1:dp[x]) << '\n';

	return 0;
}