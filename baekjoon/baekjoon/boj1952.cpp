#include <iostream>

using namespace std;

int m, n;
int visited[102][102] = { 0 };

void showVisited() {
	cout << "=============showVisited============" << endl;
	for (int i = 0; i < m + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
			cout << visited[i][j] << '\t';
		cout << endl;
	}
	cout << "====================================" << endl;
}

int main()
{

	cin >> m >> n;

	for (int i = 0; i < m + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (i == 0 || j == 0 || i == m + 1 || j == n + 1)
				visited[i][j] = -1;
		}
	}

	int move[4][2] = {
		{0,+1},
		{1,0},
		{0,-1},
	{-1,0}
	}, dir = 0;
	int cnt = 0;
	int check = 1;
	for (int i = 1, j = 1; visited[i][j] == 0;check++)
	{
		if (check == m * n)
			break;
		cout << "(" << i << "," << j << ") ¹æ¹®" << endl;
		if (visited[i + move[dir][0]][j + move[dir][1]] != 0) {
			visited[i][j] = 2;
			cnt++;
			dir = (dir + 1) % 4;
		}
		else {
			visited[i][j] = 1;
		}
		i += move[dir][0]; j += move[dir][1];
		showVisited();
	}
	cout << cnt << endl;
	system("pause");
}