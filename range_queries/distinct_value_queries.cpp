#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

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

int n, q;

vi bit, ar, ans;
vector<vector<pii>> qry;

void update(int i, int diff)
{
	do
		bit[i] += diff, i += i&(-i);
	while(i <= n);
}

int query(int i)
{
	int res = 0;
	do
		res += bit[i], i -= i&(-i);
	while(i);

	return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	ar.resize(n), qry.resize(n + 1), ans.resize(q);
	bit.resize(n + 1);
	fill(bit.begin(), bit.end(), 0);

	for(auto &e : ar)
		cin >> e;

	for(int i = 0, l, r; i < q; i++)
	{
		cin >> l >> r;
		qry[l].emplace_back(r, i);
	}

	map<int, int> chk;
	for(int i = n; i > 0; i--)
	{
		if(chk.count(ar[i-1]))
			update(chk[ar[i-1]], -1);

		chk[ar[i-1]] = i;
		update(i, 1);

		for(auto &[r, i] : qry[i])
			ans[i] = query(r);
	}

	for(auto &e : ans)
		cout << e << '\n';

	return 0;
}
