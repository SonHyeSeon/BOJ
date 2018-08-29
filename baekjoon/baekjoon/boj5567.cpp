#include <iostream>
#include <queue>

using namespace std;

int visited[500] = { 1 };
int isFriend[500][500] = { 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		isFriend[a - 1][b - 1] = isFriend[b - 1][a - 1] = 1;
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << isFriend[i][j] << ' ';
		cout << endl;
	}*/
	int friends = 0;
	
	for (int i = 1; i < n; i++)
	{
		if (isFriend[0][i] == 1)
		{
			if (visited[i] == 0) {
				friends++;
				visited[i] = 1;
			}
			//cout << i + 1 << ':';
			for (int j = 1; j < n; j++)
			{
				if (isFriend[i][j] == 1 && visited[j] == 0)
				{
					friends++;
					visited[j] = 1;
					//cout << j + 1 << ' ';
				}
			}
			//cout << endl;
		}
	}

	//cout << endl;

	cout << friends << endl;

	system("pause");
}