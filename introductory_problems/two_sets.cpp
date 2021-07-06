#include<bits/stdc++.h>

#define ull long long
#define NO cout << "NO\n"

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w",stdout);

	ull n, tot; cin >> n, tot = (n*(n+1))>>1;

	if(!(tot & 1))
	{

		tot >>= 1;
		vector<ull> ar1, ar2;

		while(n)
		{
			if(tot >= n)
				ar1.emplace_back(n), tot -= n;
			else
				ar2.emplace_back(n);
			--n;
		}

		cout << "YES\n";

		cout << ar1.size() << '\n';
		for(auto &e : ar1) cout << e << ' ';
		cout << '\n';

		cout << ar2.size() << '\n';
		for(auto &e : ar2) cout << e << ' ';
		cout << '\n';
	}
	else
		NO;
	
	return 0;
}