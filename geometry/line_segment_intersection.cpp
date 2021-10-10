#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define x first
#define y second

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

istream &operator>>(istream &stream, pll &other) {
	stream >> other.first >> other.second;
	return stream;
}

pll p1, p2, p3, p4;

int orientation(pll &a, pll &b, pll &c) {

	// -1 if anticlockwise
	// 0 if collinear
	// 1 if clockwise

	ll c1 = (b.y - a.y) * (c.x - b.x);
	ll c2 = (c.y - b.y) * (b.x - a.x);

	if(c1 == c2)
		return 0;
	return (c1 > c2)?(1):(-1);
}

bool lieson(pll &a, pll &b, pll &c) {
	return (min(a.x, c.x) <= b.x) and (b.x <= max(a.x, c.x)) and (min(a.y, c.y) <= b.y) and (b.y <= max(a.y, c.y));
}

void solve() {

	cin >> p1 >> p2 >> p3 >> p4;

	int o1 = orientation(p1, p2, p3);
	int o2 = orientation(p1, p2, p4);

	int o3 = orientation(p3, p4, p1);
	int o4 = orientation(p3, p4, p2);

	if(o1 != o2 and o3 != o4)
		goto success;
	if(!o1 and lieson(p1, p3, p2))
		goto success;
	if(!o2 and lieson(p1, p4, p2))
		goto success;
	if(!o3 and lieson(p3, p1, p4))
		goto success;
	if(!o4 and lieson(p3, p2, p4))
		goto success;

	cout << "NO\n";
	return;

success:
	cout << "YES\n";
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while(t--)
		solve();

	return 0;
}