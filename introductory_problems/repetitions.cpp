#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	string s; cin >> s;

	int ans = 1, l;
	char prv = ' ';

	for(auto &c : s)
		(c == prv)?(ans = max(ans, ++l)):(l = 1), prv = c;

	cout << ans;

	return 0;
}