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

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int mxN = 1e6 + 3;

	int n, cnt[mxN] = {}; cin >> n;

	int a, q;
	while(n--)
	{
		cin >> a;
		for(int i = 1; i*i <= a; i++)
		{
			if(a % i == 0)
			{
				cnt[i] += 1, q = a / i;
				cnt[q] += (q != i);
			}
		}
	}

	for(int i = mxN-1; i >= 1; i--)
	{
		if(cnt[i] >= 2)
		{
			cout << i << '\n';
			break;
		}
	}

	return 0;
}