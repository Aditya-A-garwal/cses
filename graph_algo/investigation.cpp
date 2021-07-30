#pragma GCC optimize("Ofast")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define ff first
#define ss second
 
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
 
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n, m; cin >> n >> m;
 
	vector<vector<pair<ll, int>>> adjlst(n);
 
	vector<ll> dist(n, llinf), minw(n, 0), maxw(n, 0), ways(n, 0), vis(n, 0);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
 
	int a, b; ll c, d;
	while(m--)
		cin >> a >> b >> c, adjlst[--a].emplace_back(c, --b);
 
	dist[0] = 0, pq.emplace(dist[0], 0);
	ways[0] = 1;
 
	while(!pq.empty())
	{
		tie(d, a) = pq.top(), pq.pop();
 
		if(vis[a])
			continue;
		vis[a] = 1;
 
		for(auto &[c, b] : adjlst[a])
		{
			if(dist[b] == c + dist[a])
			{
				(ways[b] += ways[a]) %= mod;
				minw[b] = min(minw[b], 1 + minw[a]);
				maxw[b] = max(maxw[b], 1 + maxw[a]);
				pq.emplace(dist[b], b);
			}
			else if(dist[b] > c + dist[a])
			{
				dist[b] = c + dist[a];
 
				ways[b] = ways[a];
				minw[b] = 1 + minw[a];
				maxw[b] = 1 + maxw[a];
				pq.emplace(dist[b], b);
			}
		}
	}
 
	cout << dist.back() << ' ' << ways.back() << ' ' << minw.back() << ' ' << maxw.back() << '\n';
 
	return 0;
}