// 2018.09.28 : 틀렸습니다.
//
//#include <iostream>
//using namespace std;
//int medals[1000][3] = { 0 };
//int ranking[1000] = { 1 };
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	for (int i = 0; i < n; i++)
//	{
//		int id;
//		cin >> id;
//		cin>> medals[id-1][0] >> medals[id-1][1]>> medals[id-1][2];
//		ranking[i] = 1;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 3; j++)
//			cout << medals[i][j] << ' ';
//		cout << endl;
//	}
//	cout << endl;
//	for (int i = 0, flag=0; i < 3; i++, flag++)
//	{
//		for (int p = 0; p < n - 1; p++) {
//			cout << "p=" << p<<", medals[p]["<<i<<"]="<<medals[p][i]<<endl;
//			for (int q = p + 1; q < n; q++) {
//				if (flag == 1 && medals[p][i - 1] != medals[q][i - 1])
//					continue;
//				if (flag == 2 && medals[p][i - 2] != medals[q][i - 2])
//					continue;
//				cout << "\tq=" << q << ", medals[q][" << i << "]=" << medals[q][i] << endl;
//				if (medals[p][i] > medals[q][i])
//				{
//					ranking[q]++;
//					cout << "\t\traking q 증가" << endl;
//					cout << "\t\tranking[p]=" << ranking[p] << ", ranking[q]=" << ranking[q] << endl;
//				}
//				else if (medals[p][i] < medals[q][i])
//				{
//					ranking[p]++;
//					cout << "\t\traking p 증가" << endl;
//					cout << "\t\tranking[p]=" << ranking[p] << ", ranking[q]=" << ranking[q] << endl;
//				}
//				
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << ranking[i] << ' ';
//	cout << endl;
//
//
//	cout << ranking[k - 1] << endl;
//	system("pause");
//}


#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int medals[1001][3];
	int target[3];
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		for (int j = 0; j < 3; j++)
			cin >> medals[num][j];
	}

	int rank = 1;
	for (int i = 1; i <= n; i++) {
		if (medals[i][0] > medals[k][0])
			rank++;
		else if (medals[i][0] == medals[k][0]) // 금메달 수 같음
			if (medals[i][1] > medals[k][1])
				rank++;
			else if (medals[i][1] == medals[k][1]) // 은메달 수 같음
				if (medals[i][2] > medals[k][2])
					rank++;
	}
	cout << rank << endl;
}