#pragma GCC optimize("Ofast")

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

const ll llinf = 1e18;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<pair<ll, int>>> adjList(n);
	vector<ll> dist(n, llinf); dist[0] = 0;
	priority_queue<pair<ll, int>> pq;

	int a, b, h; ll c;
	for(int i = 0; i < m; i++)
		cin >> a >> b >> c, adjList[--a].emplace_back(c, --b);

	pq.emplace(-dist[0], 0);
	while(!pq.empty())
	{
		c = -pq.top().ff, h = pq.top().ss, pq.pop();

		if(dist[h] < c) // do not do anything if the current distance is less than the last updated distance
			continue;

		for(auto &e : adjList[h])
			if(dist[e.ss] > (dist[h] + e.ff))
				dist[e.ss] = dist[h] + e.ff, pq.emplace(-dist[e.ss], e.ss);
	}

	for(auto &e : dist)
		cout << e << ' ';
	cout << '\n';

	return 0;
}