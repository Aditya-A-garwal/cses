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

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	string a, b; cin >> a >> b, n = a.size(), m = b.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	// dp[i][j] is the number of edits required to make a[1:i] = b[1:j]
	// dp[n][m] is the answer
	// dp[i][j] = min{
	// 1 + dp[i-1][j], => we add a character to the first string (making the prefix equal first)
	// 1 + dp[j][i-1], => we add a character the second string (making the prefix equal first)
	// dp[i-1][j-1] + (a[i] == a[j]) => make the prefix equal and the change the final character if needed
	// }


	for(int i = 0; i <= n; i++)
		dp[i][0] = i;
	for(int j = 0; j <= m; j++)
		dp[0][j] = j;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = min({
				dp[i-1][j] + 1,
				dp[i][j-1] + 1,
				dp[i-1][j-1] + (int)(a[i-1] != b[j-1])
			});
		}
	}

	cout << dp[n][m] << '\n';

	return 0;
}