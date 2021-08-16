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

	const int mxLog = 19;

	int n, q, a, b; cin >> n >> q;

	vector<array<int, mxLog>> pre(n, array<int, mxLog>());
	vector<vi> adjlst(n);
	vi D(n);

	for(int i = 1; i < n; i++)
	{
		cin >> a >> b, --a, --b;
		adjlst[a].emplace_back(b);
		adjlst[b].emplace_back(a);
	}

	stack<pii> st;
	D[0] = 0, st.emplace(0, -1);
	pre[0][0] = 0;

	int cur, prv;
	while(!st.empty())
	{
		tie(cur, prv) = st.top(), st.pop();
		for(auto &nxt : adjlst[cur])
		{
			if(nxt == prv)
				continue;
			D[nxt] = 1 + D[cur], st.emplace(nxt, cur);
			pre[nxt][0] = cur;
		}
	}

	fill(pre[0].begin(), pre[0].end(), 0);
	for(int j = 1; j < mxLog; j++)
		for(int i = 0; i < n; i++)
			pre[i][j] = pre[pre[i][j-1]][j-1];

	auto lca = [&](int x, int y)
	{
		if(D[x] > D[y])
			swap(x, y);

		// make the depths equal
		int diff = D[y] - D[x];

		for(int i = mxLog - 1; i >= 0; i--)
			if(diff & (1 << i))
				y = pre[y][i];

		if(x == y)
			return x;

		for(int i = mxLog - 1; i >= 0; i--)
			if(pre[x][i] != pre[y][i])
				x = pre[x][i], y = pre[y][i];

		return pre[x][0];
	};

	while(q--)
	{
		cin >> a >> b, --a, --b;
		cout << D[a] + D[b] - (D[lca(a, b)] << 1) << '\n';
	}

	return 0;
}