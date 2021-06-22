#include<iostream>
using namespace std;
int max(int x,int y);
void readfile();
void findpath();
int maxPathSum();
void result();
int f[1000][1000];
int a[1000][1000],n;
int main()
{
	readfile();
	FILE *fi=fopen("TRIANGLE.OUT","wt");
	fprintf(fi,"%d",maxPathSum());
	fclose(fi);
	return 0;
}
void readfile(){
	FILE *fi=fopen("TRIANGLE.INP","rt");
	fscanf(fi,"%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			fscanf(fi,"%d",&a[i][j]);
	fclose(fi);
}
int maxPathSum() 
{ 
     for (int i=n-1; i>=0; i--) 
     { 
        for (int j=0; j<=i; j++) 
        {
            if (a[i+1][j] > a[i+1][j+1]) 
                a[i][j] += a[i+1][j]; 
            else
                a[i][j] += a[i+1][j+1]; 
        } 
     } 
     return a[0][0]; 
} 
