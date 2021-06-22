#include<iostream>
#include<fstream>
using namespace std;
#define maxn 1000
int n,m,re=0;
int a[maxn][maxn],b[maxn][maxn];
void readfile()
{
	ifstream fi ("MOVE.INP");
	fi>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			fi>>a[i][j];			
	fi.close();
}

int max(int a,int b){
	return a>b?a:b;
}
void createtable()
{
	for(int i=1;i<=m;i++)
		b[i][1]=a[i][1];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int temp;
			temp=max(b[j][i-1],b[j-1][i-1]);
			temp=max(temp,b[j+1][i-1]);
			b[j][i]=a[j][i]+temp;
		}
	re=b[1][n];
	for(int i=2;i<=m;i++)
		re=max(re,b[i][n]);
	cout<<re<<endl;
}
void reftable()
{
	ofstream fo ("MOVE.OUT");
	fo<<re<<endl;
	fo.close();
}
int main()
{
	readfile();
	createtable();
	reftable();
	return 0;
}
