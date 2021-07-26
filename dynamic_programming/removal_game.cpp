#pragma GCC optimize("Ofast")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define ff first
#define ss second
 
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;
 
vector<vector<pair<ll, bool>>> dp;
vector<ll> pre;
 
ll solve(int i, int j)
{
	if(!dp[i][j].ss)
	{
		ll s1 = solve(i+1, j), s2 = solve(i, j-1);
		dp[i][j].ff = pre[j] - pre[i-1] - min(s1, s2), dp[i][j].ss = 1;
	}
 
	return dp[i][j].ff;
}
 
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n; cin >> n;
 
	pre = vector<ll>(n + 1); pre[0] = 0;
	dp = vector<vector<pair<ll, bool>>>(n + 1, vector<pair<ll, bool>>(n + 1));
 
	// dp[i][j] is the maximum score attainable by the player if they start and the
	// game is played over the interval (i, j)
 
	for(int i = 1; i <= n; i++)
		cin >> pre[i], dp[i][i] = {pre[i], 1}, pre[i] += pre[i-1];
 
	cout << solve(1, n) << '\n';
 
	return 0;
}