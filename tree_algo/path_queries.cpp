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
 
void createBit(int n)
{
	bit.resize(n + 1);
	fill(bit.begin(), bit.end(), 0);
}
 
ll preSum(int i)
{
	ll res = 0;
 
	for(int j = i+1; j > 0; j -= j&(-j))
		res += bit[j];
 
	return res;
}
 
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n, q; cin >> n >> q;
 
	// input value at each node
	vll ar(n), prear(n);
	for(auto &e : ar)
		cin >> e;
 
	// input edges
	vector<vi> adj(n);
	for(int i = 1, x, y; i < n; i++)
	{
		cin >> x >> y, --x, --y;
		adj[x].pb(y), adj[y].pb(x);
	}
 
	// flatten tree using euler tour, making sure that each node stores the sum from root to it
	vi init(n), final(n);
	int timer = 0;
	function<void(int, int)> flatten = [&](int cur, int prv)
	{
		prear[cur] = ar[cur];
		if(prv != -1)
			prear[cur] += prear[prv];
 
		init[cur] = timer++;
 
		for(auto &nxt : adj[cur])
			if(nxt != prv)
				flatten(nxt, cur);
 
		final[cur] = timer-1;
		// final[cur] = timer++;
	};
 
	flatten(0, -1);
	createBit(n);
	// createBit(n << 1);
 
	char c; ll a, b, diff;
	while(q--)
	{
		cin >> c >> a, --a;
		if(c == '1')
		{
			cin >> b;
			updateBit(init[a], b - ar[a]);
			updateBit(final[a] + 1, -(b - ar[a]));
			ar[a] = b;
		}
		else
		{
			cout << prear[a] + preSum(init[a]) << '\n';
		}
	}
 
	return 0;
}