#include<iostream>
using namespace std;
long long fib(int n);
long long f[100];
double tinhtong(int n,int n2);
double s = 0;
int main()
{
	int n;
	f[1] = 1; f[2] = 1;
	cout << "nhap n: "; cin >> n;
	tinhtong(n,n);
	cout << "tong la: " << s;
	return 0;
}
long long fib(int n)
{
	if (!f[n])
		f[n] = fib(n - 1) + fib(n - 2);
	return f[n];
}
double tinhtong(int n,int n2)
{
	if (n == 1)
		return 1.0/2;
	else
	{
		double temp =(double)n/(1 + fib(n));
		s += tinhtong(n - 1,n2);
		if (n == n2)	//xet truong hop khi o buoc cuoi thi gt tra ve se khong duoc cong vao s
			s += temp;
		return temp;
	}
}