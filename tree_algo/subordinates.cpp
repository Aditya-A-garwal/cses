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

struct event
{
	int a, b;
	ll c;

	bool operator<(const event &other) const
	{
		if(this->b == other.b)
			return this->a < other.a;
		return this->b < other.b;
	}

	bool operator>(const event &other) const
	{
		if(this->b == other.b)
			return this->a > other.a;
		return this->b > other.b;
	}
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> adjlst(n);
	vector<int> res(n);

	for(int i = 1, x; i < n; i++)
		cin >> x, adjlst[--x].emplace_back(i);

	function<int(int)> DFS = [&](int cur) -> int
	{
		for(auto &nxt : adjlst[cur])
			res[cur] += DFS(nxt) + 1;

		return res[cur];
	};

	DFS(0);

	for(auto &e : res)
		cout << e << ' ';
	cout << '\n';

	return 0;
}