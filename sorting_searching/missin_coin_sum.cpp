#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> ar(n);

	ll res = 1;

	for(auto &e : ar) cin >> e;
	sort(ar.begin(), ar.end());

	for(auto &e : ar)
	{
		// if the loop has reached till here, it is possible to make every sum from 1 to res (inclusive)
		// if the current element is greater than res, then this is the "gap" value
		// otherwise add the current value to res

		if(e > res)
			break;
		res += e;
	}

	cout << res << '\n';

	return 0;
}