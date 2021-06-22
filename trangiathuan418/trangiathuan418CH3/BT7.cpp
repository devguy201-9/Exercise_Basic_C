#include<iostream>
#define maxn 100
using namespace std;
void nhapmang(int a[], int n);
void timmax(int a[],int l,int r,int &max);
int main()
{
	int n, max,a[maxn];
	cout << "nhap n: "; cin >> n;
	nhapmang(a, n);
	timmax(a,1,n,max);
	cout<<max;
	return 0;
}
void nhapmang(int a[], int n)
{
	cout << "nhap mang:" << endl;
	for (int i = 1; i <=n; i++)
		cin >> a[i];
}
void timmax(int a[],int l,int r,int &max)
{
	int max1,max2;
	if(l==r)
		max=a[l];
	else
	{
		timmax(a,l,(l+r)/2,max1);
		timmax(a,(l+r)/2+1,r,max2);
		if(max1>max2)
			max=max1;
		else
			max=max2;
	}
}
