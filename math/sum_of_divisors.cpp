#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;

const ll mod = 1e9 + 7;

inline ll sum(ll a, ll b)
{
	ll res = a + b, n = b - a + 1;

	if(res & 1)
		n >>= 1;
	else
		res >>= 1;

	res %= mod, n %= mod;
	return (res * n) % mod;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, res = 0; cin >> n;

	//  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
	// 16 8 5 4 3 2 2 2 1  1  1  1  1  1  1  1

	for(ll i = 1, j, q; i <= n; i = j + 1)
	{
		q = n / i, j = n / q;

		res += (q * sum(i, j)) % mod;
		res %= mod;
	}

	cout << res << '\n';

	return 0;
}