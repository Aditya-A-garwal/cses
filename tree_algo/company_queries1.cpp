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

	const int mxN = 200000;
	const int mxLog = 19;

	int n, q; cin >> n >> q;
	vector<array<int, mxLog>> pre(n, array<int, mxLog>());

	for(auto &e : pre)
		fill(e.begin(), e.end(), -2);

	for(int i = 1; i < n; i++)
		cin >> pre[i][0], --pre[i][0];

	for(int j = 1; j < mxLog; j++)
		for(int i = 1; i < n; i++)
			if(pre[i][j-1] >= 0)
				pre[i][j] = pre[pre[i][j-1]][j-1];

	int k, x, i;
	while(q--)
	{
		cin >> x >> k, --x, i = 0;

		while(k >= (1 << i) and x >= 0)
		{
			if(k & (1 << i))
				x = pre[x][i];
			i++;
		}

		cout << ++x << '\n';
	}
	
	return 0;
}
