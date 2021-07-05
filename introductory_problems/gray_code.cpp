#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// to get a valid set of size n =>

	// generate valid set of size n-1
	// reverse the above set and append it to the original
	// postfix the first half with a "0" and the second with a "1"

	vector<string> ans{"0", "1"};
	int n, i; cin >> n;

	while(--n)
	{
		i = ans.size() - 1;
		for(int x = i; x >= 0; x--)
		{
			ans.emplace_back(ans[x]);
			ans[x] += '0', ans.back() += '1';
		}
	}

	for(auto &s : ans) cout << s << '\n';

	return 0;
}