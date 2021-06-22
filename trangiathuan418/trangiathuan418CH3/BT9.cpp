#include<iostream>
using namespace std;
long long fib(int n);
long long f[100];
int main()
{
	int n;
	f[1] = 1; f[2] = 1;
	cout << "nhap n: "; cin >> n;
	cout << fib(n);
	return 0;
}
long long fib(int n)
{
	if (!f[n])
		f[n] = fib(n - 1) + fib(n - 2);
	return f[n];
}
