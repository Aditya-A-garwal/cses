#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

	const int mxLog = 19;

	int n, q, a, b; cin >> n >> q;

	vector<vector<int>> adjlst(n);
	vector<int> depth(n);
	vector<vector<int>> pre(n, vector<int>(mxLog, 0));
	stack<pii> st;

	for(int i = 1, x; i < n; i++)
		cin >> x, adjlst[--x].emplace_back(i);

	int cur, prv, k;

	depth[0] = 0;
	pre[0][0] = 0;
	st.emplace(0, -1);

	while(!st.empty())
	{
		tie(cur, prv) = st.top(), st.pop();

		for(int j = 1; j < mxLog; j++)
			pre[cur][j] = pre[pre[cur][j-1]][j-1];

		for(auto &nxt : adjlst[cur])
		{
			depth[nxt] = 1 + depth[cur];
			pre[nxt][0] = cur;
			st.emplace(nxt, cur);
		}
	}

	while(q--)
	{
		cin >> a >> b, --a, --b;
		if(depth[a] > depth[b])
			swap(a, b);
		k = depth[b] - depth[a];
		int i = 0;
		while(k >= (1 << i))
		{
			if(k & (1 << i))
				b = pre[b][i];
			i++;
		}

		if(a == b)
		{
			cout << ++a << '\n';
			continue;
		}

		for(i = mxLog - 1; i >= 0; i--)
			if(pre[a][i] != pre[b][i])
				a = pre[a][i], b = pre[b][i];

		cout << 1 + pre[a][0] << '\n';
	}

	return 0;
}