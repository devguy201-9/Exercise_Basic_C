#include<iostream>
using namespace std;
double tinhy(int n);
double tinhx(int n);
double tinhx(int n)
{
	if (n == 0)
		return 1;
	return (tinhx(n - 1) / 3.0) + (tinhy(n - 1) / 2.0) + 27;
}
double tinhy(int n)
{
	if (n == 0)
		return 2;
	return (tinhx(n - 1) / 5.0) + (tinhy(n - 1) / 7.0) + 11;
}
int main()
{
	int n;
	cout << "nhap n: "; cin >> n;
	cout << "x=" << tinhx(n) << "	y=" << tinhy(n);
	return 0;
}