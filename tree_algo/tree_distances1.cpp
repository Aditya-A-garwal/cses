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

	int n; cin >> n;
	vector<vi> adjlst(n);
	vi dist(n), ans(n, -1);
	stack<pii> st;

	for(int i = 1, a, b; i < n; i++)
	{
		cin >> a >> b, --a, --b;
		adjlst[a].emplace_back(b), adjlst[b].emplace_back(a);
	}

	auto findFarthest = [&adjlst, &dist, &st](int start) -> int
	{
		int cur, prv, res = start;

		dist[start] = 0, st.emplace(start, -1);

		while(!st.empty())
		{
			tie(cur, prv) = st.top(), st.pop();
			for(auto &nxt : adjlst[cur])
			{
				if(nxt == prv)
					continue;
				dist[nxt] = 1 + dist[cur], st.emplace(nxt, cur);
				if(dist[nxt] > dist[res])
					res = nxt;
			}
		}

		return res;
	};

	auto DFS = [&adjlst, &dist, &st, &ans](int start)
	{
		int cur, prv;
		dist[start] = 0, st.emplace(start, -1);

		while(!st.empty())
		{
			tie(cur, prv) = st.top(), st.pop();
			ans[cur] = max(ans[cur], dist[cur]);
			for(auto &nxt : adjlst[cur])
			{
				if(nxt == prv)
					continue;
				dist[nxt] = 1 + dist[cur], st.emplace(nxt, cur);
			}
		}
	};

	// find the diameter nodes
	int a = findFarthest(0), b = findFarthest(a);
	DFS(a), DFS(b);

	for(auto &e : ans)
		cout << e << ' ';
	cout << '\n';

	return 0;
}