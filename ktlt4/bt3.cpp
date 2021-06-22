#include<iostream>
using namespace std;
void nhapmang(int* a, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> *(a + n * i + j);
}
void xuatmang(int* a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << *(a + n * i + j) << "	";
		cout << endl;
	}
}
int timmax(int* a, int m, int n)
{
	int max = -10000;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (*(a + n * i + j) > max)
				max = *(a + n * i + j);
	return max;
}
void swap(int* a, int* b)
{
	int temp = *a; *a = *b; *b = temp;
}
int *sapxep1(int* a, int m, int n)
{
	int* b = new int[n * m];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			*(b + n * i + j) = *(a + n * i + j);
	for(int i=0;i<m;i++)
		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
				if(*(b + n * i + j)> * (b + n * i + k))
					swap(b + n * i + j, b + n * i + k);
		}
	return b;
}
int* sapxep2(int* a, int m, int n)
{
	int* c = new int[n * m];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			*(c + n * i + j) = *(a + n * i + j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m - 1; j++)
		{
			for (int k = j + 1; k < m; k++)
				if (*(c + n * j + i) > * (c + n * k + i))
					swap(c + n * j + i, c + n * k + i);
		}
	return c;
}
int *sapxep3(int *a, int m, int n)
{
	int* temp = new int[m * n];
	int d = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			*(temp+d) = *(a + n * i + j);
			d++;
		}
	for (int i = 0; i < d - 1; i++)
		for (int j = i + 1; j < d; j++)
			if (*(temp + i) > * (temp + j))
				swap(temp + i, temp + j);
	int* c = new int[n * m];
	d = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			*(c + n * i + j) = *(temp + d);
			d++;
		}
	return c;
}
int main()
{
	int n, m;
	int* a, * b, * c, * d;
	cin >> m >> n;
	a = new int[n * m];
	b = new int[n * m];
	c = new int[n * m];
	d = new int[n * m];
	nhapmang(a, m, n);
	cout << "cau a: " << timmax(a, m, n) << endl;
	b = sapxep1(a, m, n);
	cout << "cau b: " << endl;
	xuatmang(b,m, n);
	c = sapxep2(a, m, n);
	cout << "cau c: " << endl;
	xuatmang(c, m, n);
	d = sapxep3(a, m, n);
	cout << "cau d: " << endl;
	xuatmang(d, m, n);
	delete a;
	delete b;
	delete c;
	delete d;
	return 0;
}