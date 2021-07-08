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
 
	for(auto &e : ar) cin >> e;
	sort(ar.begin(), ar.end());
 
	ll median = ar[n >> 1], res = 0;
	for(auto &e : ar) res += abs(median - e);
 
	cout << res << '\n';
 
	return 0;
}