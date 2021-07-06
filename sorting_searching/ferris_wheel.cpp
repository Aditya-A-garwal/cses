#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x, i, j, ans{0}; cin >> n >> x, i = 0, j = n-1;
	vector<ll> ar(n);

	for(auto &e : ar) cin >> e;
	sort(ar.begin(), ar.end());

	while(i < j)
	{
		// if the weight is low enough, give both a single gondola
		// otherwise give only the heavier person their own gondola
		i += (int)(ar[i] + ar[j] <= x);
		j--, ans++;
	}

	// If they are equal, then one child (the ith or jth) did not get a gondola
	ans += (int)(i == j);

	cout << ans << '\n';

	return 0;
}