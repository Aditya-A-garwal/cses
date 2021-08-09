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

vector<int> st;

inline int log2(int n)
{
	int res = 0; n >>= 1;
	while(n)
		res++, n >>= 1;
	return res;
}

void createST(int l, int r, int node)
{
	if(l == r)
		st[node] = 1;
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		createST(l, mid, nxt), createST(1+mid, r, 1+nxt);

		st[node] = st[nxt] + st[1+nxt];
	}
}

void createST(int n)
{
	int log = log2(n) + (int)(__builtin_popcount(n) > 1);
	st.resize(1 << (1+log));

	createST(0, n-1, 0);
}

void remove(int i, int l, int r, int node)
{
	if(l == r and l == i)
		st[node] = 0;
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		if(i <= mid)
			remove(i, l, mid, nxt);
		else
			remove(i, 1+mid, r, 1+nxt);
		st[node] = st[nxt] + st[1+nxt];
	}
}

int posAt(int i, int l, int r, int node)
{
	if(l == r)
		return l;

	int nxt = 1 + (node << 1), mid = (l + r) >> 1;

	if(i <= st[nxt])
		return posAt(i, l, mid, nxt);
	else
		return posAt(i - st[nxt], 1+mid, r, 1+nxt);
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, p, x; cin >> n;

	vector<int> ar(n);
	for(auto &e : ar)
		cin >> e;

	createST(n);

	for(int i = 0; i < n; i++)
	{
		cin >> p, x = posAt(p, 0, n-1, 0);
		remove(x, 0, n-1, 0);
		cout << ar[x] << ' ';
	}

	return 0;
}