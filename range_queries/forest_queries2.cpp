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

struct fenwick2d
{
	vector<vi> bit;
	int sz;

	fenwick2d(vector<vi> &ar)
	{
		int n = ar.size();
		sz = n + 1;
		bit = vector<vi>(sz, vi(sz, 0));

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int y = i+1; y < sz; y += y&(-y))
					for(int x = j+1; x < sz; x += x&(-x))
						bit[y][x] += ar[i][j];
	}

	int presum(int y, int x)
	{
		int res = 0;
		for(int i = y+1; i > 0; i -= i&(-i))
			for(int j = x+1; j > 0; j -= j&(-j))
				res += bit[i][j];

		return res;
	}

	int sum(int u, int l, int d, int r)
	{
		return presum(d, r) - presum(d, l-1) - presum(u-1, r) + presum(u-1, l-1);
	}

	void update(int y, int x, int diff)
	{
		for(int i = y+1; i < sz; i += i&(-i))
			for(int j = x+1; j < sz; j += j&(-j))
				bit[i][j] += diff;
	}
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	vector<vi> ar(n + 1, vi(n + 1, 0));

	char c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> c, ar[i][j] = c == '*';

	fenwick2d bit(ar);

	int a, y1, x1, y2, x2, res;
	for(int i = 0; i < q; i++)
	{
		cin >> a >> y1 >> x1;
		if(a == 1) // toggle
		{
			res = 1 - (ar[y1][x1] << 1), ar[y1][x1] += res;
			bit.update(y1, x1, res);
		}
		else // update
		{
			cin >> y2 >> x2;
			cout << bit.sum(y1, x1, y2, x2) << '\n';
		}
	}

	return 0;
}
