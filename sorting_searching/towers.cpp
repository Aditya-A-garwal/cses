#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x; cin >> n;
	multiset<int> towertops;
	multiset<int>::iterator it;

	for(int i = 0; i < n; i++)
	{
		cin >> x, it = towertops.upper_bound(x);
		if(it == towertops.end())
			towertops.insert(x);
		else
		{
			towertops.erase(it);
			towertops.insert(x);
		}
	}

	cout << towertops.size() << '\n';

	return 0;
}