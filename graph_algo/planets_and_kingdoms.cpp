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

	int n, m, cntr = 0; cin >> n >> m;
	vector<vi> adjlst1(n), adjlst2(n);
	vi vis(n, 0), comp(n, 0);
	stack<int> st;

	function<void(int)> DFS1 = [&](int node)
	{
		for(auto &nxt : adjlst1[node])
			if(!vis[nxt])
				vis[nxt] = 1, DFS1(nxt);

		st.emplace(node);
	};

	function<void(int, const int &)> DFS2 = [&](int node, const int &component)
	{
		comp[node] = component;
		for(auto &nxt : adjlst2[node])
			if(vis[nxt])
				vis[nxt] = 0, DFS2(nxt, component);
	};

	int a, b, h;

	while(m--)
	{
		cin >> a >> b, --a, --b;
		adjlst1[a].emplace_back(b);
		adjlst2[b].emplace_back(a);
	}

	for(int i = 0; i < n; i++)
		if(!vis[i])
			vis[i] = 1, vis[i], DFS1(i);

	while(!st.empty())
	{
		h = st.top(), st.pop();
		if(vis[h])
			vis[h] = 0, DFS2(h, ++cntr);
	}

	cout << cntr << '\n';
	for(auto &e : comp)
		cout << e << ' ';

	return 0;
}
