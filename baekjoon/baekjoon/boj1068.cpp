#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> erasing;
int main()
{
	int n;
	cin >> n;

	int parent[51] = { 0 };
	int childs[50][50] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> parent[i];
		childs[parent[i]][i] = 1;

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << childs[i][j] << ' ';
		cout << endl;
	}
	int erase;
	cin >> erase;

	// erase node
	int isErased[51] = { 0 };	// 0 : not erased, 1 : erased

	erasing.push(erase);
	while (!erasing.empty())
	{
		int p = erasing.front();
		isErased[p] = 1;
		for (int i = 0; i < n; i++)
		{
			if (childs[p][i] == 1)
			{
				erasing.push(i);
				childs[p][i] = 0;
			}
		}
		erasing.pop();
	}

	for (int i = 0; i < n; i++)
		cout << isErased[i] << ' ';
	cout << endl;

	//count leaf node
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (isErased[i] == 1)	// erased node
			continue;

		if (parent[i] != -1)
		{
			int isLeaf = 1;
			for(int j=0;j<n && isLeaf==1;j++)
				if (parent[j] == i && isErased[j]==0)
					isLeaf = 0;
			count += isLeaf;
			cout <<"i : "<<i<<",isLeaf : " << isLeaf << ", count: "<<count<<endl;
		}
	}
	cout << count << endl;
	system("pause");
}