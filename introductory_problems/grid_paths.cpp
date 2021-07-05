#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
string p; 
bool vis[9][9];
int ans;

inline bool splitVerCheck(const int &i, const int &j)
{
	// if the top and bottom have been visited, but the two sides have not,
	// there will always be one of them which remains unvisited

	return !(vis[i-1][j] and vis[i+1][j] and !vis[i][j+1] and !vis[i][j-1]);
}

inline bool splitHorCheck(const int &i, const int &j)
{
	// if the right and left have been visited, but the top and bottom have not,
	// there will always be one of them which remains unvisited	

	return !(vis[i][j-1] and vis[i][j+1] and !vis[i-1][j] and !vis[i+1][j]);
}

void DFS(int steps, int i, int j)
{

	if(vis[i][j]) return;
 
	if(i == 7 and j == 1)
	{
		ans += (int)(steps >= 47);
		return;
	}

	if(steps > 47) return;

	vis[i][j] = 1;
	if(p[steps] == '?')
	{
		if(splitVerCheck(i-1, j)) DFS(steps + 1, i-1, j);
		if(splitVerCheck(i+1, j)) DFS(steps + 1, i+1, j);
		if(splitHorCheck(i, j-1)) DFS(steps + 1, i, j-1);
		if(splitHorCheck(i, j+1)) DFS(steps + 1, i, j+1);
	}
	else if(p[steps] == 'U' and splitVerCheck(i-1, j)) DFS(steps + 1, i-1, j);
	else if(p[steps] == 'D' and splitVerCheck(i+1, j)) DFS(steps + 1, i+1, j);
	else if(p[steps] == 'L' and splitHorCheck(i, j-1)) DFS(steps + 1, i, j-1);
	else if(p[steps] == 'R' and splitHorCheck(i, j+1)) DFS(steps + 1, i, j+1);
	vis[i][j] = 0;
}
 
int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	memset(vis, 0, sizeof(vis));

	for(int i = 0; i < 9; i++)
		vis[0][i] = vis[i][0] = vis[8][i] = vis[i][8] = 1;

	cin >> p, ans = 0;
 
	DFS(0, 1, 1);

	cout << ans << '\n';
 
	return 0;
}
