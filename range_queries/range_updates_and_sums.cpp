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

struct node {

	ll v : 60;
	ll lz : 60;
	ll mark : 2;
};

vector<node> st;

int log2Ceil(int x) {

	int res = __builtin_popcount(x) > 1; x >>= 1;
	while(x)
		res += 1, x >>= 1;

	return res;
}

void lazyPush(int l, int r, int x) {

	int mid = (l + r) >> 1, nxt = 1 + (x << 1);

	if(l != r) {
		st[nxt].lz += st[x].lz;
		st[1 + nxt].lz += st[x].lz;
	}

	st[x].v += st[x].lz * (r - l + 1);
	st[x].lz = 0;
}

void samePush(int l, int r, int x) {

	int mid = (l + r) >> 1, nxt = 1 + (x << 1);

	st[x].mark = 0;

	if(l != r) {
		ll v = st[x].v / (r - l + 1);

		st[nxt].v = v * (mid - l + 1);
		st[1 + nxt].v = v * (r - mid);

		st[nxt].lz = 0;
		st[1 + nxt].lz = 0;

		st[nxt].mark = 1;
		st[1 + nxt].mark = 1;
	}
}

void makeST(int l, int r, int x, vi &ar) {

	int mid = (l + r) >> 1, nxt = 1 + (x << 1);

	st[x].lz = st[x].mark = 0;

	if(l == r)
		st[x].v = ar[l];
	else {

		makeST(l, mid, nxt, ar);
		makeST(1 + mid, r, 1 + nxt, ar);

		st[x].v = st[nxt].v + st[1 + nxt].v;
	}
}

void makeST(vi &ar) {

	int n = ar.size();
	int sz = 2 << log2Ceil(n);

	st.resize(sz);
	makeST(0, n-1, 0, ar);
}

ll rangeSum(int ql, int qr, int l, int r, int x) {

	int mid = (l + r) >> 1, nxt = 1 + (x << 1);

	if(st[x].lz)
		lazyPush(l, r, x);

	if(st[x].mark)
		samePush(l, r, x);

	if(l > qr or ql > r)
		return 0;

	if(ql <= l and r <= qr)
		return st[x].v;

	ll res;
	res = rangeSum(ql, qr, l, mid, nxt);
	res += rangeSum(ql, qr, 1 + mid, r, 1 + nxt);

	return res;
}

ll deltaUpdate(int ql, int qr, ll delta, int l, int r, int x) {

	int mid = (l + r) >> 1, nxt = 1 + (x << 1);

	if(st[x].lz)
		lazyPush(l, r, x);

	if(st[x].mark)
		samePush(l, r, x);	

	if(l > qr or ql > r)
		return st[x].v;

	if(ql <= l and r <= qr) {
		st[x].v += delta * (r - l + 1);
		if(l != r) {
			st[nxt].lz += delta;
			st[1 + nxt].lz += delta;
		}

		return st[x].v;
	}

	st[x].v = deltaUpdate(ql, qr, delta, l, mid, nxt);
	st[x].v += deltaUpdate(ql, qr, delta, 1 + mid, r, 1 + nxt);

	return st[x].v;
}

ll sigmaUpdate(int ql, int qr, ll sigma, int l, int r, int x) {

	int mid = (l + r) >> 1, nxt = 1 + (x << 1);

	if(st[x].lz)
		lazyPush(l, r, x);

	if(st[x].mark)
		samePush(l, r, x);

	if(l > qr or ql > r)
		return st[x].v;

	if(ql <= l and r <= qr) {

		st[x].v = sigma * (r - l + 1);
		st[x].lz = 0;
		st[x].mark = 1;

		return st[x].v;
	}

	st[x].v = sigmaUpdate(ql, qr, sigma, l, mid, nxt);
	st[x].v += sigmaUpdate(ql, qr, sigma, 1 + mid, r, 1 + nxt);

	return st[x].v;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	vi ar(n);

	for(int i = 0; i < n; i++)
		cin >> ar[i];

	makeST(ar);

	int t, l, r, x;
	while(q--) {
		cin >> t >> l >> r, --l, --r;

		if(t == 1) {
			cin >> x;
			deltaUpdate(l, r, x, 0, n-1, 0);
		}
		else if(t == 2) {
			cin >> x;
			sigmaUpdate(l, r, x, 0, n-1, 0);
		}
		else {
			cout << rangeSum(l, r, 0, n-1, 0) << '\n';
		}
	}

	return 0;
}