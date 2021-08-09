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
 
int log2(int n)
{
	int res = 0; n >>= 1;
	while(n)
		res++, n >>= 1;
 
	return res;
}
 
void createST(int l, int r, int node)
{
	if(l == r)
		st[node] = ar[l];
 
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		createST(l, mid, nxt);
		createST(mid+1, r, 1+nxt);
 
		st[node] = max(st[nxt], st[1+nxt]);
	}
}
 
void createST(int n)
{
	int log = log2(n) + (int)(__builtin_popcount(n) > 1);
	st.resize(1 << (log + 1)); fill(st.begin(), st.end(), -inf);
 
	createST(0, n-1, 0);
}
 
int getFirstFree(int l, int r, int node, int req)
{
	if(l == r)
		return (st[node] >= req)?l:-1;
	
	int nxt = 1 + (node << 1), mid = (l + r) >> 1;
	if(st[nxt] >= req)
		return getFirstFree(l, mid, nxt, req);
	if(st[1+nxt] >= req)
		return getFirstFree(1+mid, r, 1+nxt, req);
 
	return -1;
}
 
void update(int i, int l, int r, int node, int x)
{
	if(i < l or i > r)
		return;
	if(l == r)
		st[node] += x;
	else
	{
		int nxt = 1 + (node << 1), mid = (l + r) >> 1;
		update(i, l, mid, nxt, x);
		update(i, 1+mid, r, 1+nxt, x);
 
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
 
	int n, q, a, res; cin >> n >> q;
 
	ar.resize(n);
 
	for(auto &e : ar)
		 cin >> e;
 
	createST(n);
 
	while(q--)
	{
		cin >> a, res = getFirstFree(0, n-1, 0, a);
 
		if(res != -1)
			update(res, 0, n-1, 0, -a);
 
		cout << ++res << ' ';
	}
 
	cout << '\n';
 
	return 0;
}