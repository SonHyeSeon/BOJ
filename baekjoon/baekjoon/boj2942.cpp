#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int r, g;
	cin >> r >> g;

	//// �ð� �ʰ�
	//for (int i = 1;; i++) {
	//	if (r%i == 0 && g%i == 0)
	//	{
	//		cout << i << ' ' << r / i << ' ' << g / i << endl;
	//		if (r / i == 1 || g / i == 1)
	//			break;
	//	}
	//}


	// 1. �ִ����� ���ϱ� �� ��Ŭ���� ȣ����
	int gcd=0, tr=r, tg=g;
	while (gcd==0) {
		if (tr >= tg)
			if(tr%tg!=0) tr %= tg;
			else gcd = tg;
		else if (tg > tr)
			if (tg%tr!=0) tg %= tr;
			else gcd = tr;
	}

	// 2. �ִ������� ��� ���ϱ�
	stack<int> divisors;
	int printed = 1;
	for (int i = 1; i <= gcd / 2; i++) {
		if (gcd%i == 0) {
			cout << i << ' ' << r / i << ' ' << g / i << endl;
			divisors.push(gcd/i);
			printed = i;
		}
	}
	
	while (!divisors.empty()) {
		int p = divisors.top();
		divisors.pop();
		if (printed < p)
			cout << p << ' ' << r / p << ' ' << g / p << endl;
	}
}