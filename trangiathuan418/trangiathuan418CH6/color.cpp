#include<iostream>
#define maxn 1000
using namespace std;
int n, a[maxn][maxn],sm=0,m[maxn];
void docfile(){
	FILE* f=fopen("colorx.inp", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fscanf(f,"%d",&a[i][j]);
	fclose(f);
}
void tomau(){
	FILE* f=fopen("colorx.out", "wt");
    int kt;
    for(int i=1;i<=n;i++)
        if(!m[i]) {
            sm++;
            m[i]=sm;
            for(int j=i+1;j<=n;j++)
                if((a[i][j]==0)&&(m[j]==0)){
                    kt=1;
                    for(int k=i+1;k<j;k++)
                        if((a[k][j]==1)&&(m[i]==m[k])){
                            kt=0;
                            break;
                        }
                    if(kt==1) m[j]=sm;
                }                   
        }
    fprintf(f,"%d",sm);
    fclose(f);
}
int main(){
    docfile();
    tomau();
    return 0;
}
