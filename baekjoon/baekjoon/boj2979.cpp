#include <iostream>

using namespace std;

int main()
{
	int price[3];
	for (int i = 0; i < 3;i++)
		cin >> price[i];

	int cnt[100] = { 0 };
	int min = 100, max = 1;
	for (int i = 0, s, f; i < 3; i++)
	{
		cin >> s >> f;
		if (s < min)
			min = s;
		if (f > max)
			max = f;
		for (; s < f; s++)
			cnt[s]++;
	}

	int result = 0;
	for (;min<max;min++)
	{
		result += price[cnt[min] - 1]*cnt[min];
		cout << min << ' ' << cnt[min] << ' ' << price[cnt[min] - 1] << ' ' << result << endl;
	}

	cout << result << endl;

	system("pause");
}