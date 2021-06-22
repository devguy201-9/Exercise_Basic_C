#include<iostream>
using namespace std;
bool itnhatam(int a[], int n)
{
	a[n] = -1;
	int i =0;
	while (a[i]>=0)
	{
		i++;
	}
	return (i < n);
}
//kiểm tra mảng toàn âm
bool ktam(int a[], int n)
{
	a[n] = 1;
	int i = 0;
	while (a[i] < 0)
	{
		i++;
	}
	return (i >= n);
}
int main()
{
	int a[8]={ 6,1,8,9,4,-2,1,-9 };
	int b[8] = { 6,1,8,9,4,2,1,9 };
	int c[8] = { -6,-1,-8,-9,-4,-2,-1,-9 };
	return 0;
}