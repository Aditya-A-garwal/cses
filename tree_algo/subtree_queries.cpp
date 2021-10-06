#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

#define pb emplace_back

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

vll bit;

void updateBit(int i, ll diff)
{
	for(int j = i+1; j < bit.size(); j += j&(-j))
		bit[j] += diff;
}

void createBit(vll &ar)
{
	int N = ar.size();
	bit.resize(N + 1);

	for(int i = 0; i < N; i++)
		updateBit(i, ar[i]);
}

ll preSum(int i)
{
	ll res = 0;
	for(int j = i+1; j > 0; j -= j&(-j))
		res += bit[j];
	return res;
}

ll rangeSum(int i, int j)
{
	return preSum(j) - preSum(i - 1);
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	vector<vi> adj(n);
	vi st(n), en(n);
	vll ar(n), flat(n << 1);

	int timer = 0;
	function<void(int, int)> flatten = [&](int cur, int prv)
	{
		st[cur] = timer++;
		for(auto &nxt : adj[cur])
			if(nxt != prv)
				flatten(nxt, cur);
		en[cur] = timer++;
		flat[st[cur]] = flat[en[cur]] = ar[cur];
	};

	for(auto &e : ar)
		cin >> e;

	for(int i = 1, x, y; i < n; i++)
	{
		cin >> x >> y, --x, --y;
		adj[x].pb(y), adj[y].pb(x);
	}

	flatten(0, -1);
	createBit(flat);

	char c; ll a, b, diff;
	while(q--)
	{
		cin >> c >> a, --a;
		if(c == '1') // update
		{
			cin >> b;

			// update the first position
			diff = b - flat[st[a]];
			updateBit(st[a], diff);
			flat[st[a]] += diff;

			// update the second position
			diff = b - flat[en[a]];
			updateBit(en[a], diff);
			flat[en[a]] += diff;
		}
		else
			cout << rangeSum(st[a], en[a])/2 << '\n';
	}

	return 0;
}