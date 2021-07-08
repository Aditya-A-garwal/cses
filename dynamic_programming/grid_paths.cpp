#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; char c; cin >> n;
	int numWays[n + 2][n + 2];
	bool safe[n][n];

	memset(safe, 0, sizeof(safe));
	memset(numWays, 0, sizeof(numWays));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> c, safe[i][j] = c != '*';

	numWays[1][1] = (int)safe[0][0];

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(!safe[i-1][j-1]) continue;
			numWays[i][j] = (numWays[i][j] + numWays[i-1][j]) % mod;
			numWays[i][j] = (numWays[i][j] + numWays[i][j-1]) % mod;
		}
	}

	cout << numWays[n][n] << '\n';


	return 0;
}