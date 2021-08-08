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

vector<int> st, ar;

void createST(int l, int r, int node)
{
	if(l == r)
		st[node] = ar[l];
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		createST(l, mid, nxt);
		createST(1+mid, r, 1+nxt);

		st[node] = min(st[nxt], st[1+nxt]);
	}
}

void createST(int n)
{
	int N = n;

	if(__builtin_popcount(N) > 1)
	{
		int x = 1; N >>= 1;
		while(N)
			x++, N >>= 1;
		N = 1 << x;
	}

	st.resize(N << 1), fill(st.begin(), st.end(), inf);
	createST(0, n-1, 0);
}

void update(int x, int i, int l, int r, int node)
{
	if(l == r)
		st[node] = x;
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		if(i <= mid)
			update(x, i, l, mid, nxt);
		else
			update(x, i, 1+mid, r, 1+nxt);
		st[node] = min(st[nxt], st[1+nxt]);
	}
}

int rangeMin(int qs, int qe, int l, int r, int node)
{
	if(l > qe or r < qs)
		return inf;
	else if(l >= qs and r <= qe)
		return st[node];

	int nxt = 1 + (node << 1), mid = (l + r) >> 1;
	return min(rangeMin(qs, qe, l, mid, nxt), rangeMin(qs, qe, 1+mid, r, 1+nxt));
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;

	ar.resize(n);
	for(int i = 0; i < n; i++)
		 cin >> ar[i];

	createST(n);

	int a, b, c;
	while(q--)
	{
		cin >> a >> b >> c;
		if(a == 1) // update operation
			update(c, --b, 0, n-1, 0);
		else
			cout << rangeMin(--b, --c, 0, n-1, 0) << '\n';
	}

	return 0;
}
