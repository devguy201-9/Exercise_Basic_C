#include<iostream>
using namespace std;

int tinhtong(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += (n - i) * tinhtong(i);
		return sum;
	}
}
int main()
{
	int n;
	cout << "nhap n: "; cin >> n;
	cout << "tong la: " << tinhtong(n);
	return 0;
}