#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	int n; cin >> n;

	if(n == 1)
		cout << '1' << endl;
	else if(n <= 3)
		cout << "NO SOLUTION" << endl;
	else
	{
		for(int i = 2; i <= n; i += 2) cout << i << ' ';
		for(int i = 1; i <= n; i += 2) cout << i << ' ';
	}


	return 0;
}