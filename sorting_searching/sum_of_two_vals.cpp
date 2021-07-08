#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<pair<unsigned int, int>> ar(n);

	int p = 0;
	for(auto &[a, b] : ar) cin >> a, b = ++p;
	sort(ar.begin(), ar.end());

	int i = 0, j = n-1;
	while(i < j)
	{
		unsigned int sum = ar[i].first + ar[j].first;
		if(sum > x) j--;
		else if(sum < x) i++;
		else
		{
			cout << ar[i].second << ' ' << ar[j].second << '\n';
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}