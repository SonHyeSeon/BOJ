#include <iostream>
#include <string>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	string map[100];
	for (int i = 0; i < h; i++)
		cin >> map[i];

	for (int i = 0, cloud=-1; i < h; i++, cloud=-1)
	{
		for (int j = 0; j < w; j++)
		{
			if (map[i][j] == 'c')
				cloud = 0;
			cout << cloud << ' ';
			if (cloud > -1)
				cloud++;
		}
		cout << endl;
	}

	system("pause");
}