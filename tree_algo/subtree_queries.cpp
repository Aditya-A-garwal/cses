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

int n, q;

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

	cin >> n >> q;
	vector<vi> adj(n);
	vi st(n), en(n);
	vll ar(n), flatar; flatar.reserve(1 + (n << 1));

	int timer = 0;
	function<void(int, int)> flatten = [&](int cur, int prv)
	{
		flatar.pb(ar[cur]);
		st[cur] = timer++;

		for(auto &nxt : adj[cur])
			if(nxt != prv)
				flatten(nxt, cur);

		flatar.pb(ar[cur]);
		en[cur] = timer++;
	};

	for(auto &e : ar)
		cin >> e;

	for(int i = 1, x, y; i < n; i++)
	{
		cin >> x >> y, --x, --y;
		adj[x].pb(y), adj[y].pb(x);
	}

	flatten(0, 0);
	createBit(flatar);

	char c; ll a, b;
	while(q--)
	{
		cin >> c;
		if(c == '1') // update
		{
			cin >> a >> b, --a;

			ll i, diff;

			// update the first position
			i = st[a];
			diff = b - flatar[i];
			updateBit(i, diff);
			flatar[i] += diff;

			// update the second position
			i = en[a];
			diff = b - flatar[i];
			updateBit(i, diff);
			flatar[i] += diff;
		}
		else
		{
			cin >> a, --a;
			cout << rangeSum(st[a], en[a])/2 << '\n';
		}
	}

	return 0;
}