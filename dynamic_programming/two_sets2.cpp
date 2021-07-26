#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;

const int mod = 1000000007;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, tot; cin >> n, tot = (n * (n + 1)) >> 1;
	if(!(tot & 1))
	{
		tot >>= 1;
		vector<vector<int>> dp(n + 1, vector<int>(tot + 1, 0));

		dp[0][0] = 1;

		// dp[i][j] is the number of ways to get sum = j using the first i numbers
		// if we dont include i, dp[i][j] = dp[i-1][j]
		// if we do include i, dp[i][j] = dp[i-1][j-i] (j >= i)

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= tot; j++)
			{
				dp[i][j] = dp[i-1][j];
				if(j >= i)
					dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % mod;
			}
		}

		cout << dp[n][tot] << '\n';
	}
	else
		cout << "0\n";

	return 0;
}