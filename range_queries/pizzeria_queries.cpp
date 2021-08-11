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

vi st1, st2, ar;
int n, q;

inline int log2(int x)
{
	int res = 0; x >>= 1;
	while(x)
		res++, x >>= 1;

	return res;
}

void createST(int l, int r, int node)
{
	if(l == r)
		st1[node] = ar[l] + l, st2[node] = ar[l] + (n - 1 - l);
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		createST(l, mid, nxt);
		createST(1+mid, r, 1+nxt);

		st2[node] = min(st2[nxt], st2[1+nxt]);
		st1[node] = min(st1[nxt], st1[1+nxt]);
	}
}

void createST(int n)
{
	int log = log2(n) + (int)(__builtin_popcount(n) != 1);

	st1.resize(1 << (log+1));
	fill(st1.begin(), st1.end(), inf);
	st2.resize(1 << (log+1));
	fill(st2.begin(), st2.end(), inf);

	createST(0, n-1, 0);
}

int rangeMin(int qs, int qe, int l, int r, int node, vi &st)
{
	if(l > qe or r < qs)
		return inf;
	if(l >= qs and r <= qe)
		return st[node];

	int nxt = 1 + (node << 1), mid = (l + r) >> 1;
	return min(rangeMin(qs, qe, l, mid, nxt, st),
		rangeMin(qs, qe, 1+mid, r, 1+nxt, st));
}

void update(int i, int l, int r, int node, int diff, vi &st)
{
	if(l == r)
		st[node] += diff;
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		if(i <= mid)
			update(i, l, mid, nxt, diff, st);
		else
			update(i, 1+mid, r, 1+nxt, diff, st);

		st[node] = min(st[nxt], st[1+nxt]);
	}
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	ar.resize(n);

	for(auto &e : ar)
		cin >> e;	

	createST(n);

	int a, b, c, diff;
	while(q--)
	{
		cin >> a >> b, --b;
		if(a == 1) // update pos b to c
		{
			cin >> c, diff = c - ar[b];
			update(b, 0, n-1, 0, diff, st1), update(b, 0, n-1, 0, diff, st2);
			ar[b] += diff;
		}
		else // get min at pos b
		{
			cout << min(rangeMin(b, n-1, 0, n-1, 0, st1) - b,
				rangeMin(0, b, 0, n-1, 0, st2) - (n - 1 - b)) << '\n';
		}
	}

	return 0;
}