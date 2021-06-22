#include<iostream>
using namespace std;
long long s = 0;
long long tinhtong(int n)
{
	if (n == 1)
		return 1;
	else
	{
		long long sum = 1;
		for (int i = 2; i <= n; i++)
			sum *= i;
		s=tinhtong(n - 1) + sum;
	}
	return s;
}
int main()
{
	int n;
	cout << "nhap n: "; cin >> n;
	cout << tinhtong(n);
	return 0;
}
