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

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, a, b, mx = 1, nx; cin >> n >> m, nx = n;

	vector<int> dsu(n), sz(n, 1);
	for(int i = 0; i < n; i++)
		dsu[i] = i;

	function<int(int)> getSet = [&](int node)
	{
		while(node != dsu[node])
			node = dsu[node];

		return node;
	};

	function<int(int, int)> makeSame = [&](int node1, int node2) -> int
	{
		node1 = getSet(node1), node2 = getSet(node2);

		if(node1 > node2)
			swap(node1, node2);

		dsu[node2] = node1;
		return sz[node1] += sz[node2];
	};

	while(m--)
	{
		cin >> a >> b, --a, --b;
		if(getSet(a) != getSet(b))
		{
			nx -= 1;
			mx = max(mx, makeSame(a, b));
		}
		cout << nx << ' ' << mx << '\n';
	}

	return 0;
}