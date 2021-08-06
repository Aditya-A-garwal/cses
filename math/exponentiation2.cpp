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

const ll mod = 1e9 + 7;

ll binpow(ll a, ll b, ll m)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			(res *= a) %= m;
		(a *= a) %= m, b >>= 1;
	}

	return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a, b, c, t; cin >> t;
	while(t--)
	{
		cin >> a >> b >> c;
		cout << binpow(a, binpow(b, c, mod - 1), mod) << '\n';
	}

	return 0;
}