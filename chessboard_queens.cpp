#include<bits/stdc++.h>

using namespace std;

int board[8][8];
bool colTaken[8];
int cnt;

void placeQueen(int row)
{
	if(row >= 8) cnt++;

	// go through every cell in this line
	for(int j = 0; j < 8; j++)
	{
		// only do something if this coloumn is not taken and cell is not under attack
		if(colTaken[j] or board[row][j]) continue;

		// place all the attacks for this cell down-right and down-left
		for(int x = j+1, y = row+1; x < 8 and y < 8; x++, y++) ++board[y][x];
		for(int x = j-1, y = row+1; x >= 0 and y < 8; x--, y++) ++board[y][x];
		colTaken[j] = 1;

		placeQueen(row + 1);

		// remove all the attacks for this cell down-right and down-left
		for(int x = j+1, y = row+1; x < 8 and y < 8; x++, y++) --board[y][x];
		for(int x = j-1, y = row+1; x >= 0 and y < 8; x--, y++) --board[y][x];
		colTaken[j] = 0;
	}
}

int main(int argc, char *argv[])
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(colTaken, 0, sizeof(colTaken));
	cnt = 0;

	char c;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			cin >> c, board[i][j] = (int)(c == '*');

	placeQueen(0);

	cout << cnt << '\n';

	return 0;
}