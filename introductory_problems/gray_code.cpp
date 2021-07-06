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

	int n, x, a; cin >> n, x = 1 << n;

	for(int i = 0; i < x; i++)
	{
		a = i ^ (i >> 1);
		for(int j = 0; j < n; j++)
			cout << ('0' + (a>>j)&1);
		cout << '\n';
	}

	return 0;
}