#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q, n, cntr = 0;

	auto inv = [&n](int x)
	{
		return (n << 1) - (x + 1);
	};

	cin >> q >> n;
	vector<vi> adjlst1(n << 1),
				adjlst2(n << 1);

	vi vis(n << 1, 0), comp(n << 1, 0), pres(n, 0);
	stack<int> st;

	char x, y; int a, b;
	while(q--)
	{
		cin >> x >> a >> y >> b, --a, --b;
		if(x == '-')
			a = inv(a);
		if(y == '-')
			b = inv(b);

		adjlst1[inv(a)].pb(b), adjlst1[inv(b)].pb(a);
		adjlst2[b].pb(inv(a)), adjlst2[a].pb(inv(b));
	}

	function<void(int)> dfs1 = [&](int node)
	{
		vis[node] = 1;
		for(auto &e : adjlst1[node])
			if(!vis[e])
				dfs1(e);

		st.emplace(node);
	};

	function<void(int, int)> dfs2 = [&](int node, int component)
	{
		comp[node] = component;
		vis[node] = 1;

		for(auto &e : adjlst2[node])
			if(!vis[e])
				dfs2(e, component);
	};

	for(int i = 0; i < 2*n; i++)
		if(!vis[i])
			dfs1(i);

	fill(vis.begin(), vis.end(), 0);

	while(!st.empty())
	{
		int h = st.top(); st.pop();
		if(!vis[h])
			dfs2(h, ++cntr);
	}

	for(int i = 0; i < n; i++)
	{
		if(comp[i] == comp[inv(i)])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		pres[i] = comp[i] > comp[inv(i)];
	}

	for(int i = 0; i < n; i++)
		cout << ((pres[i])?'+':'-') << ' ';

	cout << '\n';

	return 0;
}
