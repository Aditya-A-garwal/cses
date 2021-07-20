#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 10;
const ll infll = 1e18 + 10;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// if a node can lie on the path from 1 to n and is part of a positive cycle,
	// then we can get arbitrarily hight score otherwise not

	int n, m; cin >> n >> m;
	vector<vector<int>> adjLst1(n), adjLst2(n);
	vector<pii> vis(n, {0, 0});
	stack<int> st;

	vector<tuple<int, int, ll>> edges; edges.reserve(m);
	vector<ll> dist(n, infll); dist[0] = 0;

	int a, b, h; ll c;

	while(m--)
	{
		cin >> a >> b >> c, --a, --b;
		adjLst1[a].emplace_back(b), adjLst2[b].emplace_back(a);
		edges.emplace_back(a, b, -c);
	}

	vis[0].ff = 1, st.emplace(0);
	while(!st.empty())
	{
		h = st.top(), st.pop();
		for(auto &e : adjLst1[h])
			if(!vis[e].ff)
				vis[e].ff = 1, st.emplace(e);
	}

	vis[n-1].ss = 1, st.emplace(n-1);
	while(!st.empty())
	{
		h = st.top(), st.pop();
		for(auto &e : adjLst2[h])
			if(!vis[e].ss)
				vis[e].ss = 1, st.emplace(e);
	}

	while(n--)
	{
		for(int i = 0; i < edges.size(); i++)
		{
			tie(a, b, c) = edges[i];
			dist[b] = min(dist[a] + c, dist[b]);
		}
	}

	for(int i = 0; i < edges.size(); i++)
	{
		tie(a, b, c) = edges[i];
		if(vis[b].ff and vis[b].ss and dist[b] > dist[a] + c)
		{
			cout << "-1\n"; return 0;
		}
	}

	cout << -dist.back() << '\n';

	return 0;
}