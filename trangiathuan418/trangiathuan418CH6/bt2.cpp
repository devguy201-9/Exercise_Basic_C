#include<iostream>
#include <string.h>
using namespace std;
#define maxn 100
#define maxm 10000
int f[maxn][maxm],a[maxn],n,m,result[maxn];
void input(int a[],int &n,int &m)
{
	FILE *f=fopen("KNAPSACK1.INP","rt");
	fscanf(f,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fscanf(f,"%d",&a[i]);
	fclose(f);
}
int max(int a,int b){
	return (a>b)?a:b;
}
void createtable(int f[][maxm],int a[],int n,int m)
{
	for(int i=1;i<=m;i++)
		if(i>=a[1])
			f[1][i]=a[1];
		else
			f[1][i]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(j>=a[i])
				f[i][j]=max(f[i-1][j-a[i]] + a[i],f[i-1][j]);
			else
				f[i][j]=f[i-1][j];
}
void reftable(int f[][maxm],int a[],int n,int m)
{
	int volume=0;
	int k=n,v=m;
	memset(result,0,sizeof(result));
	do{
		while(f[k][v]==f[k-1][v])
			k--;
		result[k]=1;
		v=f[k][v]-a[k];
		volume+=a[k];
	}
	while(v>0);
	FILE *g=fopen("KNAPSACK1.OUT","wt");
	fprintf(g,"%d",volume);
	fclose(g);
}
int main()
{
	input(a,n,m);
	createtable(f,a,n,m);
	reftable(f,a,n,m);
	return 0;
}
