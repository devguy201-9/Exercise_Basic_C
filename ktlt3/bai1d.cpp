#include<iostream>
using namespace std;
long long s = 0,s2=0;
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
long long tinhtong2(int n)
{
	if (n == 1)
		return 2;
	else
	{
		long long temp = 1;
		for (int i = n; i <= 2 * n; i++)
			temp *= i;
		s2 = tinhtong2(n - 1) + temp;
	}
	return s2;
}
int main()
{
	int n;
	cout << "nhap n: "; cin >> n;
	cout << "tong la: " << tinhtong(n);
	//cout << "tong la: " << tinhtong2(n);
	return 0;
}