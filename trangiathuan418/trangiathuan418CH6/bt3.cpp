#include<iostream>
using namespace std;
#define maxn 100
#define maxm 10000
int a[maxn],c[maxn],f[maxn][maxm];
int n,m;
void input()
{
	FILE *fi=fopen("KNAPSACK2.INP","rt");
	fscanf(fi,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fscanf(fi,"%d%d",&a[i],&c[i]);
	fclose(fi);
}
int max(int a,int b){
	return a>b?a:b;
}
void createtable()
{
	for(int i=1;i<=maxn;i++)
		f[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(j<a[i])
				f[i][j]=f[i-1][j];
			else
				f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+c[i]);
		}
}
int main()
{
	input();
	createtable();
	FILE *g=fopen("KNAPSACK2.OUT","wt");
	fprintf(g,"%d",f[n][m]);
	fclose(g);
	return 0;
}
