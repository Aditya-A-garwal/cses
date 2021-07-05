#include<bits/stdc++.h>

using namespace std;

// for n disks (general case)
// move n-1 disks from START to VIA through end
// move 1 disk from START to END directly
// move n-1 disks from VIA to END through start

// for 1 disk (base case)
// directly move it from START to END directly

void move(int disks, int start, int end, int via)
{
	if(disks <= 1)
		cout << start << ' ' << end << '\n';
	else
	{
		move(disks - 1, start, via, end);
		cout << start << ' ' << end << '\n';
		move(disks - 1, via, end, start);
	}
}

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	cout << -1+(1<<(n)) << '\n';
	move(n, 1, 3, 2);

	return 0;
}
