#pragma GCC optimize("Ofast")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define ff first
#define ss second
 
#define pb emplace_back
 
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
using vi = vector<int>;
using vii = vector<pii>;
using vll = vector<ll>;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;
 
struct node {
 
	ll s{0};
	ll v{0};
	ll lz{0};
};
 
vector<node> st;
 
int log2ceil(int x) {
 
	int res = __builtin_popcount(x) > 1; x >>= 1;
	while(x)
		res += 1, x >>= 1;
	return res;
}
 
void pushdown(int l, int r, int x, int mid, int nxt) {
 
	st[x].v = st[x].lz * (r - l + 1);
 
	if(l != r) {
		st[nxt].lz = st[x].lz;
		st[1 + nxt].lz = st[x].lz;
	}
 
	st[x].lz = 0;
}
 
void makeST(int l, int r, int x, vll &ar) {
 
	int mid = (l + r) >> 1, nxt = 1 + (x << 1);
 
	if(l == r) {
		st[x].s = ar[l];
		st[x].v = ar[l];
	}
	else {
		makeST(l, mid, nxt, ar);
		makeST(1 + mid, r, 1 + nxt, ar);
 
		st[x].s = st[nxt].s + st[1 + nxt].s;
		st[x].v = st[nxt].v + st[1 + nxt].v;
	}
}
 
void makeST(vll &ar) {
 
	int n = ar.size();
	int sz = 2 << log2ceil(n);
 
	st.resize(sz);
	makeST(0, n-1, 0, ar);
}
 
void assign(int ql, int qr, ll v, int l, int r, int x) {
 
	int mid = (l + r) >> 1, nxt = 1 + (x << 1);
 
	if(st[x].lz)
		pushdown(l, r, x, mid, nxt);
 
	if(ql > r or l > qr)
		return;
 
	if(ql <= l and r <= qr) {
		st[x].lz = v;
		pushdown(l, r, x, mid, nxt);
	}
 
	else {
		assign(ql, qr, v, l, mid, nxt);
		assign(ql, qr, v, 1 + mid, r, 1 + nxt);
 
		st[x].v = st[nxt].v + st[1 + nxt].v;
	}
}
 
ll rangeCost(int ql, int qr, int l, int r, int x) {
 
	int mid = (l + r) >> 1, nxt = 1 + (x << 1);
 
	if(st[x].lz)
		pushdown(l, r, x, mid, nxt);
 
	if(ql > r or l > qr)
		return 0;
 
	if(ql <= l and r <= qr)
		return st[x].v - st[x].s;
 
	return rangeCost(ql, qr, l, mid, nxt) + rangeCost(ql, qr, 1 + mid, r, 1 + nxt);
}
 
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n, m; cin >> n >> m;
	vll ar(n);
	vll res(m);
	vector<vii> q(n);
 
	for(int i = 0; i < n; i++)
		cin >> ar[i];
 
	makeST(ar);
 
	for(int i = 0, l, r; i < m; i++) {
		cin >> l >> r, --l, --r;
		q[l].pb(r, i);
	}
 
	vi peaks;
 
	for(int l = n - 1, pos; l >= 0; l--) {
 
		while(peaks.size() and ar[peaks.back()] <= ar[l])
			peaks.pop_back();
 
		if(peaks.size())
			pos = peaks.back() - 1;
		else
			pos = n - 1;
 
		peaks.pb(l);
 
		assign(l, pos, ar[l], 0, n-1, 0);
 
		for(auto &[r, i] : q[l])
			res[i] = rangeCost(0, r, 0, n-1, 0);
	}
 
	for(int i = 0; i < m; i++)
		cout << res[i] << '\n';
 
	return 0;
}