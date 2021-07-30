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
 
	const int mxN = 1e9 + 1;
	const int mxP = 30;

	int n, q, x, k; cin >> n >> q;
	vector<array<int, mxP>> pre(n);

	for(int i = 0; i < n; i++)
		cin >> pre[i][0], --pre[i][0];

	for(int j = 1; j < mxP; j++)
		for(int i = 0; i < n; i++)
			pre[i][j] = pre[pre[i][j-1]][j-1];

	int i;
	while(q--)
	{
		cin >> x >> k, --x, i = 0;

		while(k)
		{
			if(k & 1)
				x = pre[x][i];
			k >>= 1, i++;
		}

		cout << ++x << '\n';
	}
 
	return 0;
}