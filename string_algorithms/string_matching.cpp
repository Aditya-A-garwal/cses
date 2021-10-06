#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned ll;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;

const ll mod = 1e9 + 7;

int kmpMatch(const string &a, const string &b) {

	int res = 0, i, j;
	const int n = a.size(), m = b.size();

	vi lps(m + 1); lps[0] = 0;

	i = 1, j = 0;
	while(i < m) {

		if(b[i] == b[j]) {
			lps[i] = j + 1;
			i++;
			j++;
		}
		else if(j != 0) {
			j = lps[j - 1];
		}
		else {
			lps[i] = 0;
			i++;
		}
	}


	i = 0, j = 0;
	while(i < n) {
		if(a[i] == b[j]) {
			i++,
			j++;
			if(j == m) {
				res++,
				j = lps[j - 1];
			}
		}
		else if(j != 0) {
			j = lps[j - 1];
		}
		else {
			i += 1;
		}
	}

	return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a, b; cin >> a >> b;
	cout << kmpMatch(a, b) << '\n';

	return 0;
}