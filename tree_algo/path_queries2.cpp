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

const int mxLog = 20;

int n, q;

vi ar;
vi depth;
vi heavy;
vi head;
vi id;

vi a;

vector<vi> adj;
vector<array<int, mxLog>> pre;

vi st;

int log2(int x) {

	int res = 0; x >>= 1;
	while(x)
		res++, x >>= 1;
	return res;
}

void makeST(int l, int r, int node) {

	if(l == r)
		st[node] = a[l];
	else {

		int mid = (l + r) >> 1, nxt = 1 + (node << 1);
		makeST(l, mid, nxt);
		makeST(1 + mid, r, 1 + nxt);

		st[node] = max(st[nxt], st[1 + nxt]);
	}
}

void makeST() {

	int log = log2(n) + (__builtin_popcount(n) != 1);
	st.resize(1 << (log + 1));

	makeST(0, n-1, 0);
}

int rangeMax(int ql, int qr, int l, int r, int node) {

	if(ql <= l and r <= qr)
		return st[node];
	else if(ql > r or qr < l)
		return -inf;

	int mid = (l + r) >> 1, nxt = 1 + (node << 1);
	return max(rangeMax(ql, qr, l, mid, nxt), rangeMax(ql, qr, 1 + mid, r, 1 + nxt));
}

void update(int q, int l, int r, int node, int val) {

	if(l == r) {
		assert(l == q);
		st[node] = val;
	}
	else {
		int mid = (l + r) >> 1, nxt = 1 + (node << 1);

		if(q <= mid)
			update(q, l, mid, nxt, val);
		else
			update(q, 1 + mid, r, 1 + nxt, val);

		st[node] = max(st[nxt], st[1 + nxt]);
	}
}

int pathMax(int lo, int hi) {

	int res = -inf;

	if(depth[lo] < depth[hi])
		swap(lo, hi);

	while(head[lo] != head[hi]) {
		res = max(res, rangeMax(id[head[lo]], id[lo], 0, n-1, 0));
		lo = pre[head[lo]][0];
	}

	res = max(res, rangeMax(id[hi], id[lo], 0, n-1, 0));

	return res;
}

int dfs(int cur, int prv) {

	pre[cur][0] = prv;
	for(int i = 1; i < mxLog; i++)
		pre[cur][i] = pre[pre[cur][i-1]][i-1];

	heavy[cur] = -1;

	int sz = 1, mxSz = 0;

	for(int &nxt : adj[cur]) {
		if(nxt != prv) {

			depth[nxt] = 1 + depth[cur];

			int nxtSz = dfs(nxt, cur);
			sz += nxtSz;

			if(nxtSz > mxSz)
				mxSz = nxtSz, heavy[cur] = nxt;
		}
	}

	return sz;
}

void decomp(int cur, int prv, int H, int &ID) {

	head[cur] = H;
	id[cur] = ID++;

	if(heavy[cur] != -1) {
		decomp(heavy[cur], cur, H, ID);
	}

	for(int &nxt : adj[cur]) {
		if(nxt != prv and nxt != heavy[cur]) {
			decomp(nxt, cur, nxt, ID);
		}
	}
}

int ances(int node, int k) {

	for(int i = 0; i < mxLog; i++)
		if(k & (1 << i))
			node = pre[node][i];

	return node;
}

int LCA(int a, int b) {

	if(depth[a] > depth[b])
		swap(a, b);

	b = ances(b, depth[b] - depth[a]);

	if(a == b)
		return a;

	for(int i = mxLog - 1; i >= 0; i--)
		if(pre[a][i] != pre[b][i])
			a = pre[a][i], b = pre[b][i];

	return pre[a][0];
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	ar = vi(n);
	a = vi(n);
	depth = vi(n);
	heavy = vi(n);
	head = vi(n);
	id = vi(n);

	adj = vector<vi>(n);
	pre = vector<array<int, mxLog>>(n);

	for(int i = 0; i < n; i++)
		cin >> ar[i];

	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		adj[u].emplace_back(v),
		adj[v].emplace_back(u);
	}

	depth[0] = 0;
	int ID = 0;
	dfs(0, 0);
	decomp(0, 0, 0, ID);

	for(int i = 0; i < n; i++)
		a[id[i]] = ar[i];

	makeST();

	int u, v, lca;
	char x;
	while(q--) {
		cin >> x >> u >> v;

		if(x == '1') {
			--u;
			update(id[u], 0, n-1, 0, v);
		}
		else {
			--u, --v;
			lca = LCA(u, v);
			cout << max(pathMax(u, lca), pathMax(v, lca)) << ' ';
		}
	}

	cout << '\n';

	return 0;
}
