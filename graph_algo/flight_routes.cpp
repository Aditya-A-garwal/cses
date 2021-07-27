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

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<ll, int>>> adjlst(n);
	vector<priority_queue<ll, vector<ll>, greater<ll>>> dist(n);

	while(m--)
	{
		ll a, b, c; cin >> a >> b >> c;
		adjlst[--a].emplace_back(c, --b);
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	ll d; int h;

	pq.emplace(0, 0);

	while(!pq.empty())
	{
		tie(d, h) = pq.top(), pq.pop();

		if(dist[h].size() >= k)
		{
			if(dist[h].top() <= d)
				continue;
			dist[h].pop();
		}
		dist[h].emplace(d);

		for(auto &nxt : adjlst[h])
		{
			ll nextDist = nxt.ff + d;
			if(dist[nxt.ss].size() >= k)
			{
				if(dist[nxt.ss].top() <= nextDist)
					continue;
				dist[nxt.ss].pop();
			}
			pq.emplace(nextDist, nxt.ss);
		}
	}

	vector<ll> ans; ans.reserve(k + 1);
	while(!dist[n-1].empty())
		ans.emplace_back(dist[n-1].top()), dist[n-1].pop();

	for(auto &e : ans)
		cout << e << ' ';
	cout << '\n';

	return 0;
}