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

	vector<vector<int>> pre(n, vector<int>(mxLog, inf));
	// pre[i][j] is the min element in the range a[i , i + 2^j)

	function<int(int, int)> rangeMin = [&](int i, int j) -> int
	{
		int log = 0, num = j - i + 1, x = num >> 1;

		while(x)
			log++, x >>= 1;

		if(__builtin_popcount(num) == 1) // a perfect power of 2
			return pre[i][log];

		return min(pre[i][log], rangeMin(i + (1 << log), j));
	};

	for(int i = 0; i < n; i++)
		cin >> pre[i][0];

	for(int j = 1; j < mxLog; j++)
		for(int i = 0; i+(1 << (j-1)) < n; i++)
			pre[i][j] = min(pre[i][j-1], pre[i+(1 << (j-1))][j-1]);

	while(q--)
	{
		cin >> a >> b;
		cout << rangeMin(--a, --b) << '\n';
	}

	return 0;
}
