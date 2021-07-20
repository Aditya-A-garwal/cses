#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

const ll infll = 1e17;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, q; cin >> n >> m >> q;
	vector<vector<ll>> adjMat(n, vector<ll>(n, infll));
	int a, b; ll c;

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c, --a, --b;
		adjMat[a][b] = adjMat[b][a] = min(adjMat[a][b], c);
	}

	for(int i = 0; i < n; i++)
		adjMat[i][i] = 0;

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);

	while(q--)
	{
		cin >> a >> b, --a, --b;
		if(adjMat[a][b] < infll)
			cout << adjMat[a][b];
		else
			cout << -1;
		cout << '\n';
	}

	return 0;
}