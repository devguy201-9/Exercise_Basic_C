#include<iostream>
#include<ctime>
#define max 100
using namespace std;
void hinhve(int a,int b);
//void nhapmang(int a[], int &n);
//void xuamang(int a[], int n);
int main()
{
//	int a[max];
//	int nSize;
//	int n;

	int a,b;
	cout << "nhap chieu cao ="; cin >> a;
	cout << "nhap chieu rong ="; cin >> b;
	cout << endl;
	hinhve(a,b);
//	nhapmang(a, nSize);
//	xuamang(a, nSize);
	return 0;
}
void hinhve(int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			if (i == 0 || i == a - 1 || j == 0 || j == b - 1)
			{
				cout << "* ";
			}
			else
				cout << "  ";
	cout << endl;
	}
}
//void nhapmang(int a[], int &n)
//{	
//	srand(time(NULL));
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		a[i] = rand() % 100 + 1;
//}
//void xuamang(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << a[i] << "	";
//}
