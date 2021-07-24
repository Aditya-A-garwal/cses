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
 
	int n, x; cin >> n;
	vector<int> dp(n + 1, inf); dp[0] *= -1;

	for(int i = 0; i < n; i++)
	{
		cin >> x;
		int j = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
		if(x > dp[j-1])
			dp[j] = x;
	}

	for(int i = n; i >= 0; i--)
	{
		if(dp[i] != inf)
		{
			cout << i << '\n';
			break;
		}
	}
 
	return 0;
}