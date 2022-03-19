#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back

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

struct Node {

	ll v;
	Node *lptr;
	Node *rptr;

	Node(ll x) : v{x}, rptr{nullptr}, lptr{nullptr} {}

	Node(Node *l, Node *r) : lptr{l}, rptr{r} {

		v = 0;
		if(l) v += l->v;
		if(r) v += r->v;
	}

	Node(Node *init) : v{init->v}, lptr(init->lptr), rptr(init->rptr) {}
};

int n, q;

vll ar;
vector<Node *> roots;

Node *build(int l, int r) {

	int mid = (l + r)/2;

	if(l == r) return new Node(ar[l]);
	return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(int q, ll v, int l, int r, Node *x) {

	int mid = (l + r)/2;

	if(l == r) {
		assert(l == q);
		return new Node(v);
	}
	
	if(q > mid)
		return new Node(x->lptr, update(q, v, 1 + mid, r, x->rptr));
	else
		return new Node(update(q, v, l, mid, x->lptr), x->rptr);
}

ll query(int ql, int qr, int l, int r, Node *x) {

	int mid = (l + r)/2;

	if(l > qr or ql > r)
		return 0;

	if(ql <= l and r <= qr)
		return x->v;

	return query(ql, qr, l, mid, x->lptr) + query(ql, qr, 1 + mid, r, x->rptr);
}


int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	roots.reserve(q);
	ar = vll(n);

	for(auto &e : ar)
		cin >> e;

	roots.pb(build(0, n-1));

	ll t, l, r, a, x, k;
	while(q--) {

		cin >> t >> k, --k;

		assert(k < roots.size());

		if(t == 1) {

			cin >> a >> x, --a;
			roots[k] = update(a, x, 0, n-1, roots[k]);
		}
		else if(t == 2) {

			cin >> l >> r, --l, --r;
			cout << query(l, r, 0, n-1, roots[k]) << '\n';
		}
		else if(t == 3) {
			roots.pb(new Node(roots[k]));
		}
	}

	return 0;
}