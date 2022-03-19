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

struct SegTree {

	struct node {

		ll v{0};
		ll lz{0};
		ll t{0};
	};

	vector<node> st;

	SegTree(int n, vll &ar) {
		st = vector<node>(n << 2);
		build(0, n-1, 0, ar);
	}

	void build(int l, int r, int x, const vll &ar) {

		int mid = (l + r)/2, nxt = 1 + 2*x;

		st[x].lz = st[x].t = 0;

		if(l == r)
			st[x].v = ar[l];
		else {

			build(l, mid, nxt, ar), build(1 + mid, r, 1 + nxt, ar);

			st[x].v = st[nxt].v + st[1 + nxt].v;
		}
	}

	void pushdown(int l, int mid, int r, int x, int nxt) {

		if(st[x].lz == 0 or st[x].t == 0)
			return;

		ll &lz = st[x].lz;
		ll &t = st[x].t;

		ll n = r - l + 1;
		ll inc = t * ((n*(n-1))/2) + (n * lz);

		st[x].v += inc;
		if(l != r) {

			st[nxt].lz += lz;
			st[nxt].t += t;

			st[1 + nxt].lz += lz + t*(mid - l + 1);
			st[1 + nxt].t += t;
		}
		lz = t = 0;
	}

	void update(int ql, int qr, int l, int r, int x) {

		int mid = (l + r)/2, nxt = 1 + 2*x;

		pushdown(l, mid, r, x, nxt);

		if(ql > r or l > qr)
			return;

		if(ql <= l and r <= qr) {

			st[x].lz += l - ql + 1;
			st[x].t += 1;
			pushdown(l, mid, r, x, nxt);
		}

		else {

			update(ql, qr, l, mid, nxt), update(ql, qr, 1 + mid, r, 1 + nxt);
			st[x].v = st[nxt].v + st[1 + nxt].v;
		}
	}

	ll query(int ql, int qr, int l, int r, int x) {

		int mid = (l + r)/2, nxt = 1 + 2*x;

		pushdown(l, mid, r, x, nxt);

		if(ql > r or l > qr)
			return 0;

		if(ql <= l and r <= qr)
			return st[x].v;

		return query(ql, qr, l, mid, nxt) + query(ql, qr, 1 + mid, r, 1 + nxt);
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

	vll ar(n);

	for(auto &e : ar)
		cin >> e;

	SegTree st(n, ar);

	int t, a, b;
	while(q--) {

		cin >> t >> a >> b, --a, --b;

		// update
		if(t == 1)
			st.update(a, b, 0, n-1, 0);

		// query
		else
			cout << st.query(a, b, 0, n-1, 0) << '\n';
	}

	return 0;
}