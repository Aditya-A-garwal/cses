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

	int n, q, a, b;
	ll x;
	cin >> n >> q;

	vector<ll> pre(n + 1); pre[0] = 0;

	for(int i = 1; i <= n; i++)
		cin >> x, pre[i] = x + pre[i-1];

	while(q--)
	{
		cin >> a >> b;
		cout << pre[b] - pre[a-1] << '\n';
	}

	return 0;
}