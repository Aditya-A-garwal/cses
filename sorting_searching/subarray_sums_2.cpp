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
 
	ll n, x, res = 0; cin >> n >> x;
	map<ll, ll> check; check[0] = 1;
 
	ll cur, prv = 0;
 
	for(int i = 1; i <= n; i++)
	{
		cin >> cur, cur += prv, prv = cur;
 
		res += check[cur - x];
		check[cur]++;
	}
 
	cout << res << '\n';
 
	return 0;
}