#include<bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n, q, a, b, ans = 1; cin >> n >> q;
	vector<int> pos(n + 1), ar(n + 1);
 
	for(int i = 0; i < n; i++)
		cin >> ar[i], pos[ar[i]] = i;

	for(int i = 1; i < n; i++)
		ans += pos[i] > pos[i+1];
 
	while(q--)
	{
		cin >> a >> b, a--, b--;

		// If the numbers are consecutive, storing them in a vector will cause repeat pairs
		vector<pair<int, int>> contribs;
		
		if(ar[a] == 1+ar[b])
		{
			if(ar[b] > 1) contribs.emplace_back(ar[b]-1, ar[b]);
			contribs.emplace_back(ar[b], ar[a]);
			if(ar[a] < n) contribs.emplace_back(ar[a], ar[a]+1);

		}
		else if(ar[b] == 1+ar[a])
		{
			if(ar[a] > 1) contribs.emplace_back(ar[a]-1, ar[a]);
			contribs.emplace_back(ar[a], ar[b]);
			if(ar[b] < n) contribs.emplace_back(ar[b], ar[b]+1);
		}
		else
		{
			if(ar[a] > 1) contribs.emplace_back(ar[a]-1, ar[a]);
			if(ar[a] < n) contribs.emplace_back(ar[a], ar[a]+1);
			if(ar[b] > 1) contribs.emplace_back(ar[b]-1, ar[b]);
			if(ar[b] < n) contribs.emplace_back(ar[b], ar[b]+1);
		}

		// Remove current contributions to the chaos
		for(auto &[x, y] : contribs)
			ans -= pos[x] > pos[y];

 		swap(pos[ar[a]], pos[ar[b]]);
		swap(ar[a], ar[b]);

		// Add new contributions to the chaos
		for(auto &[x, y] : contribs)
			ans += pos[x] > pos[y];

		cout << ans << '\n';
	}
 
	return 0;
}