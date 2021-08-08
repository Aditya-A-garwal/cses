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

inline int log2(int x)
{
	int res = 0; x >>= 1;
	while(x)
		res++, x >>= 1;

	return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int mxLog = 19;
	int n, q, a, b; cin >> n >> q;

	vector<vector<int>> pre(n, vector<int>(mxLog));

	for(int i = 0; i < n; i++)
		cin >> pre[i][0];

	for(int j = 1; j < mxLog; j++)
		for(int i = 0; i+(1<<(j-1)) < n; i++)
			pre[i][j] = pre[i][j-1] ^ pre[i+(1<<(j-1))][j-1];

	function<int(int, int)> rangeMin = [&](int i, int j)
	{
		int log = log2(j - i + 1);
		if(__builtin_popcount(j - i + 1) == 1) // perfect power of 2
			return pre[i][log];

		return pre[i][log] ^ rangeMin(i+(1<<log), j);
	};

	while(q--)
	{
		cin >> a >> b;
		cout << rangeMin(--a, --b) << '\n';
	}

	return 0;
}