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

vector<ll> st;

void createST(int n)
{
	int log = 1; n >>= 1;
	while(n)
		log++, n >>= 1;

	n = 1 << log;
	st.resize(n << 1);
	fill(st.begin(), st.end(), 0);
}

void rangeUpdate(int x, int qs, int qe, int l, int r, int node)
{
	if(qs > r or qe < l)
		return;
	if(l >= qs and r <= qe)
		st[node] += x;
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		rangeUpdate(x, qs, qe, l, mid, nxt);
		rangeUpdate(x, qs, qe, 1+mid, r, 1+nxt);
	}
}

ll changeAt(int i, int l, int r, int node)
{
	if(l == r)
		return st[node];

	int nxt = 1 + (node << 1), mid = (l + r) >> 1;

	st[nxt] += st[node];
	st[1+nxt] += st[node];

	st[node] = 0;

	if(i <= mid)
		return changeAt(i, l, mid, nxt);
	else
		return changeAt(i, 1+mid, r, 1+nxt);
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;

	vector<ll> ar(n);
	createST(n);

	for(auto &e : ar)
		cin >> e;

	ll a, b, c;
	while(q--)
	{
		cin >> a;
		if(a == 1) // update
		{
			cin >> a >> b >> c, --a, --b;
			rangeUpdate(c, a, b, 0, n-1, 0);
		}
		else
		{
			cin >> c, --c;
			cout << (ar[c] + changeAt(c, 0, n-1, 0)) << '\n';
		}
	}

	return 0;
}