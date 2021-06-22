#include<iostream>
#include<string.h>
#define maxc 1000000
using namespace std;
void docfile(char *s,int &d){
	FILE *f;
	f=fopen("vanban.in","rt");
	d=0;
	char s1[maxc]="";
	while(!feof(f)){
		fgets(s1,maxc,f);
		d++;
		//dung strcat de cong don chuoi ke ca ki tu \n
		strcat(s,s1);
	}
	fclose(f);
}
void docfile2(char *s){
	FILE *f;
	f=fopen("viettat.in","rt");
	while(!feof(f)){
		fgets(s,256,f);
	}
	fclose(f);
}
int demcau(char *s)
{
	int l = strlen(s), d = 1;
	//co the co truong hop gap so: 13.6
	for (int i = 0; i < l; i++)
		if (s[i] == '.' && (s[i + 1] == 32 || s[i + 1] == 10))
			d++;
	return d;
}
void ghihoa(char *s)
{
	FILE *f = fopen("vanban1.out", "wt");
	int l = strlen(s);
	if(s[0] >=97 && s[0]<=122)
		s[0]-=32;
	//co 2 th: .-khoang trang (hoac) .-\n
	for (int i = 1; i < l-2; i++)
		if (s[i] == '.' && (s[i + 1] == 32 || s[i + 1] == 10))
			if(s[i+2] >=97 && s[i+2]<=122)
				s[i+2]-=32;
	fflush(stdin);
	fputs(s, f);
    fclose(f);
}
void suaviettat(char *s, char *s1,char *s2)
{
	FILE *f = fopen("vanban2.out", "wt");
    int n=0;
    char *kq=new char[maxc];
    char *stemp=new char[80];
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == s1[0])
        {  
        	int dem = 0;
        	//sao chep chuoi con cua mang goc vao mang stemp
            for (int j = i; dem < strlen(s1); j++)
                stemp[dem++] = s[j];
            //xoa ki tu rac o cuoi
            stemp[dem]='\0';
            //so sanh 2 chuoi r sao chep vo kq va tang i den sau chu viet tat
            if (strcmp(s1,stemp) == 0){
            	for(int k=0;k<strlen(s2);k++)
                	kq[n++]=s2[k];
            	i=i+strlen(s1)-1;
			}
        }
        else
        	kq[n++]=s[i];
    }
    fputs(kq, f);
    fclose(f);
    delete kq;
    delete stemp;
}
int main()
{
	char *s,*s1,*s2;
	int d;
	s=new char[maxc];
	s1=new char[256];
	s2=new char[256];
	docfile(s,d);
	//xoa 3 ki tu rac o dau chuoi
	s=s+3;
	cout<<"- So cau: "<<demcau(s)<<endl;
	cout<<"- So doan: "<<d<<endl;
	ghihoa(s);
	docfile2(s1);
	//tach tu viet tat va tu can sua
	for(int i=0;i<strlen(s1);i++)
		if(s1[i]==' ')
		{
			s1=s1+i+1;
			s2[i]='\0';
			break;
		}
		else
			s2[i]=s1[i];
	suaviettat(s,s2,s1);
	delete s;
	delete s1;
	delete s2;
	return 0;
}
