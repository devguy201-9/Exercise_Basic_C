#include<iostream>
using namespace std;
long long s = 0;
long long tinhtong(int n)
{
	if (n == 1)
		return 2;
	else
	{
		long long temp = 1;
		for (int i = n; i <= 2 * n; i++)
			temp *= i;
		s = tinhtong(n - 1) + temp;
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
