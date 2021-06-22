							//chuong trinh chay tot tren moi truong dev-c++

#include<iostream>
using namespace std;
#define maxn 10000
void input(int a[], int& n);
void createtable(int a[], int n);
void output(int a[], int n);
int a[maxn], L[maxn], P[maxn],n;
int main()
{
	input(a, n);
	createtable(a, n);
	output(a, n);
	return 0;
}
void input(int a[], int& n)
{
	FILE *f=fopen("SEQUENCE.INP","rt");
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;i++)
		fscanf(f,"%d",&a[i]);
	fclose(f);
}
void output(int a[], int n)
{
	FILE *f=fopen("SEQUENCE.OUT","wt");
	int maxL=0;
	for(int i=1;i<=n;i++)
		if(L[i]>maxL)
			maxL=L[i];
	fprintf(f,"%d",maxL);
	fclose(f);
}
void createtable(int a[], int n)
{
	for(int i=1;i<=n;i++)
	{
		int maxLj=0,maxPi=0;
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]<=a[i] && L[j]>maxLj)
			{
				maxLj=L[j];
				maxPi=j;
			}
			L[i]=maxLj+1;
			P[i]=maxPi;
		}
	}
}
