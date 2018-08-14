#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	cin.ignore();

	while (t--)
	{
		string noise;
		getline(cin, noise);
		cout << noise << endl;
		vector<string> noises;
		for(int next = 0; noise.find(' ') != string::npos;)
		{
			next = noise.find(' ');
			noises.push_back(noise.substr(0, next));
			noise.erase(0, next+1);
		}
		noises.push_back(noise);

		cout << "noises: ";
		for (int i = 0; i < noises.size(); i++)
			cout << noises.at(i) << ' ';
		cout << endl;

		string cry;
		getline(cin, cry);
		while (cry != "what does the fox say?")
		{

			cry = cry.substr(cry.find("goes ") + 5);

			for (int i = 0; i < noises.size(); i++)
			{
				if (noises.at(i) == cry)
				{
					noises.erase(noises.begin() + i);
					i--;
				}
			}
			// pow, ow 같은 예외 발생
			/*while (noise.find(cry) != string::npos)
			{
				cout << noise.find(cry) << ' ' << cry.length() << endl;
				noise.erase(noise.find(cry), cry.length());
			}*/

			getline(cin, cry);
		}

		// pow, ow 같은 예외 발생
		//for (int i = 0; i < noise.length();)
		//{
		//	if (noise[i] == ' ')
		//	{
		//		while (noise[i] == ' ')
		//			i++;
		//	}
		//	else
		//	{
		//		while (noise[i] != ' ')
		//			cout << noise[i++];
		//		cout << ' ';
		//	}
		//}
		//cout << endl;

		for (int i = 0; i < noises.size(); i++)
			cout << noises.at(i) << ' ';
		cout << endl;
	}
	system("pause");
}