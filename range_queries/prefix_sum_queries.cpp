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

vector<ll> st, lz, pre, ar;

int log2(int n)
{
	int res = 0; n >>= 1;
	while(n)
		res++, n >>= 1;

	return res;
}

void createST(int l, int r, int node)
{
	lz[node] = 0;
	if(l == r)
		st[node] = pre[l];
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		createST(l, mid, nxt);
		createST(1+mid, r, 1+nxt);

		st[node] = max(st[nxt], st[1+nxt]);
	}
}

void createST(int n)
{
	int log = log2(n) + (int)(__builtin_popcount(n) != 1);

	st.resize(1 << (log + 1)), lz.resize(1 << (log + 1));

	createST(0, n-1, 0);
}

ll rangeMax(int qs, int qe, int l, int r, int node)
{
	int nxt = 1 + (node << 1), mid = (l + r) >> 1;
	if(lz[node])
	{
		st[node] += lz[node];
		if(l != r)
			lz[nxt] += lz[node], lz[1+nxt] += lz[node];
		lz[node] = 0;
	}

	if(l > qe or r < qs)
		return -llinf;
	if(l >= qs and r <= qe)
		return st[node];
	else
		return max(rangeMax(qs, qe, l, mid, nxt),
					rangeMax(qs, qe, 1+mid, r, 1+nxt));
}

ll valAt(int i, int l, int r, int node)
{
	int nxt = 1 + (node << 1), mid = (l + r) >> 1;
	if(lz[node])
	{
		st[node] += lz[node];
		if(l != r)
			lz[nxt] += lz[node], lz[1+nxt] += lz[node];
		lz[node] = 0;
	}

	if(l == r)
		return st[node];

	if(i <= mid)
		return valAt(i, l, mid, nxt);
	else
		return valAt(i, 1+mid, r, 1+nxt);
}

void updateRange(int x, int qs, int qe, int l, int r, int node)
{
	int nxt = 1 + (node << 1), mid = (l + r) >> 1;
	if(lz[node])
	{
		st[node] += lz[node];
		if(l != r)
			lz[nxt] += lz[node], lz[1+nxt] += lz[node];
		lz[node] = 0;
	}

	if(l > qe or r < qs)
		return;
	if(l >= qs and r <= qe)
	{
		st[node] += x;
		if(l != r)
			lz[nxt] += x, lz[1+nxt] += x;
	}
	else
	{
		updateRange(x, qs, qe, l, mid, nxt);
		updateRange(x, qs, qe, 1+mid, r, 1+nxt);
		st[node] = max(st[nxt], st[1+nxt]);
	}
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q, a, b, c; cin >> n >> q;

	ar.resize(n), pre.resize(n);

	cin >> ar[0], pre[0] = ar[0];
	for(int i = 1; i < n; i++)
		cin >> ar[i], pre[i] = ar[i] + pre[i-1];

	createST(n);

	while(q--)
	{
		cin >> a >> b >> c;
		if(a == 1) // update range
		{
			--b;
			ll diff = c - ar[b];
			updateRange(diff, b, n-1, 0, n-1, 0);
			ar[b] += diff;
		}
		else // max in range
		{
			--b, --c;
			ll pr = (b-1 >= 0)?(valAt(b-1, 0, n-1, 0)):(0);
			cout << max(0LL, rangeMax(b, c, 0, n-1, 0) - pr) << '\n';
		}
	}


	return 0;
}