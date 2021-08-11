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

vector<array<ll, 4>> st;
vector<ll> ar;
// 0 is the sum
// 1 is the max subarray sum
// 2 is the max pref sum
// 3 is the max suff sum

inline int log2(int n)
{
	int res = 0; n >>= 1;
	while(n)
		res++, n >>= 1;
	return res;
}

inline void combine(array<ll, 4> &left, array<ll, 4> &root, array<ll, 4> &right)
{
	// my sum is the total sum of my right and left nodes
	// my max subarray sum is the sum of the max suff sum of my left and max pref sum of my right

	// my max pref sum = max(pref sum of left node, sum of left node + pref sum of right node)
	// my max suff sum = max(suff sum of right node, sum of right node + suff sum of left node)

	root[0] = left[0] + right[0];
	root[1] = max({left[1], right[1], left[3] + right[2]});

	root[2] = max(left[2], left[0] + right[2]);
	root[3] = max(right[3], right[0] + left[3]);
}

void createST(int l, int r, int node)
{
	if(l == r)
	{
		fill(st[node].begin(), st[node].end(), max(ar[l], 0LL));
		st[node][0] = ar[l];
	}
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		createST(l, mid, nxt), createST(1+mid, r, 1+nxt);

		combine(st[nxt], st[node], st[1+nxt]);
	}
}

inline void createST(int n)
{
	int log = log2(n) + (int)(__builtin_popcount(n) != 1);
	st.resize(1 << (log+1));
	createST(0, n-1, 0);
}

void update(int i, int l, int r, int node, ll x)
{
	if(l == r)
	{
		fill(st[node].begin(), st[node].end(), max(x, 0LL));
		st[node][0] = x;
	}
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		if(i <= mid)
			update(i, l, mid, nxt, x);
		else
			update(i, 1+mid, r, 1+nxt, x);

		combine(st[nxt], st[node], st[1+nxt]);
	}
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, q, k, x; cin >> n >> q;
	ar.resize(n);

	for(auto &e : ar)
		 cin >> e;

	createST(n);

	while(q--)
	{
		cin >> k >> x, update(--k, 0, n-1, 0, x);
		cout << st[0][1] << '\n';
	}

	return 0;
}
