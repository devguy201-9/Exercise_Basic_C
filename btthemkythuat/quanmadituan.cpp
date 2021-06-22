#include<iostream>
#define max 5
using namespace std;
void khoitao(int a[][max])
{
	for (int i = 0; i < max; i++)
		for (int j = 0; j < max; j++)
			a[i][j] = 0;
}
int check(int i, int j)
{
	return (i >= 0 && i < max && j >= 0 && j < max);
}
void xuat(int a[][max])
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			cout << "	" << a[i][j];
		}
		cout << endl;
	}
}
//ham quay lui de tim duong cho quan ma
void ma(int step, int i, int j, int a[][max], int* l, int* k, int& ok)
{
	int m, inext, jnext;
	for (m = 0; m < 8; m++)
	{
		inext = i + l[m];
		jnext = j + k[m];
		if (check(inext, jnext) && (a[inext][jnext] == 0))
		{
			a[inext][jnext] = step + 1;
			if (step == m * m - 1)
				ok = 1;
			else
			{
				ma(step + 1, inext, jnext, a, l, k, ok);
				if (!ok)
					a[inext][jnext] = 0;
			}
		}
	}
}
int main()
{
	int a[max][max], i, j, ok = 0;
	int l[8] = { -2,-1,1,2,2,1,-1,-2 };
	int k[8] = { 1,2,2,1,-1,-2,-2,-1 };
	cout << "nhap vi tri cua quan ma:" << endl;
	cin >> i >> j;
	khoitao(a);
	a[i][j] = 1;
	ma(1, i, j, a, l, k, ok);
	cout << endl;
	if (ok)
		xuat(a);
	else
		cout << "khong co loi giai";
	return 0;
}