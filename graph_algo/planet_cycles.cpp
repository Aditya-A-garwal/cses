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

const int mxN = 200002;

int n, steps;
int dest[mxN], res[mxN] = {}, vis[mxN] = {};
queue<int> path;

void dfs(int node)
{
	path.emplace(node);
	if(vis[node])
		steps += res[node];
	else
	{
		vis[node] = 1;
		steps++;
		dfs(dest[node]);
	}
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> dest[i], --dest[i];

	for(int i = 0; i < n; i++)
	{
		if(vis[i])
			continue;

		steps = 0;
		dfs(i);

		while(!path.empty() and path.front() != path.back())
			res[path.front()] = steps--, path.pop();
		while(!path.empty())
			res[path.front()] = steps, path.pop();
	}

	for(int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << '\n';

	return 0;
}
