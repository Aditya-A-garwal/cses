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

const ll mod = 1e9 + 7;
using matrix = array<array<ll, 2>, 2>;

matrix mult(matrix &a, matrix &b)
{
	matrix res;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			res[i][j] = 0;
			for(int k = 0; k < 2; k++)
				(res[i][j] += a[i][k] * b[k][j]) %= mod;
		}
	}

	return res;
}

matrix pow(matrix &m, ll n)
{
	matrix res;
	res[0][0] = res[1][1] = 1;
	res[1][0] = res[0][1] = 0;

	while(n)
	{
		if(n & 1)
			res = mult(res, m);
		n >>= 1, m = mult(m, m);
	}

	return res;
}

ll fib(ll n)
{
	if(n <= 1)
		return n;

	matrix m;
	m[0][0] = 1, m[0][1] = 1;
	m[1][0] = 1, m[1][1] = 0;

	matrix res = pow(m, n-1);
	return res[0][0];
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n; cin >> n;
	cout << fib(n) << '\n';

	return 0;
}