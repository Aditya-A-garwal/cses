#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define ff first
#define ss second
 
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll llinf = 1e18 + 10;
 
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n, m; cin >> n >> m;
	vector<vector<pair<ll, int>>> adjLst(n);
	vector<array<ll, 2>> dist(n, {llinf, llinf}); dist[0][0] = dist[0][1] = 0;
 
	priority_queue<tuple<ll, int, int>> pq;
 
	int a, b, h; ll c;
 
	while(m--)
		cin >> a >> b >> c, adjLst[--a].emplace_back(c, --b);
 
	pq.emplace(-dist[0][1], 1, 0);
	while(!pq.empty())
	{
		tie(c, a, h) = pq.top(), pq.pop();
 
		if(dist[h][a] < -c) continue;

		for(auto &e : adjLst[h])
		{
			if(dist[e.ss][a] > (dist[h][a] + e.ff))
				dist[e.ss][a] = dist[h][a] + e.ff, pq.emplace(-dist[e.ss][a], a, e.ss);

			if(a == 0) continue;

			if(dist[e.ss][0] > (dist[h][1] + e.ff/2))
				dist[e.ss][0] = dist[h][1] + e.ff/2, pq.emplace(-dist[e.ss][0], 0, e.ss);
		}
	}
 
	cout << dist[n-1][0] << '\n';
 
	return 0;
}