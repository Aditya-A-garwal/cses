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

	int n, q; cin >> n >> q;

	vector<vector<int>> pre(n + 1, vector<int>(n + 1));

	for(int i = 0; i <= n; i++)
		pre[i][0] = pre[0][i] = 0;

	char c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> c, pre[i][j] = (int)(c == '*') + pre[i][j-1];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			pre[i][j] += pre[i-1][j];

	int y1, x1, y2, x2;
	while(q--)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		cout << pre[y2][x2] - pre[y2][x1-1] - pre[y1-1][x2] + pre[y1-1][x1-1] << '\n';
	}

	return 0;
}