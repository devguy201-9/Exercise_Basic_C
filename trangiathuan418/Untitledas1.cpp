#include<iostream>
#include<string.h>
#define maxc 1000000
using namespace std;
void docfile(char *s){
	FILE *f;
	int n;
	f=fopen("str.inp","rt");
	char s1[maxc]="";
	fscanf(f,"%d",&n);
	for(int i=0;i<=n;i++){
		fgets(s1,maxc,f);
		strcat(s,s1);
	}
	fclose(f);
}
void cau_1(char *s){
	int d=0,n=0,n1=0,max=0;
	int a[100];
	char s1[256];
	char s2[256];
	for(int i=0;i<=strlen(s);i++){
		if(s[i]==10||s[i]==0){
			a[n++]=d;
			if(d>max){
				max=d;
				strcpy(s1,s2);
				s2[0]='\0';
				n1=0;
			}
			d=0;
		}
		else{
			s2[n1++]=s[i];
			d++;
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n"<<s1<<endl;
}
void cau_2(char *s){
	char s1[80];
	int n=0;
	for(int i=0;i<=strlen(s);i++)
		if(s[i]==10 || s[i]==0){
			s1[n]='\0';
			//co the mo file ouput r ghi s1 vo luon
			cout<<s1<<endl;
		}else if(s[i]==32){
			s1[0]='\0';
			n=0;
		}else
			s1[n++]=s[i];
}
int demtu(char *s)
{
	int l = strlen(s), d = 1;
	for (int i = 0; i < l; i++)
		if ((s[i] == ' ' || s[i] == '\n') && s[i + 1] != ' ')
			d++;
	return d;
}
int demkitumoitu(char *s)
{
	int kitu = 0;
	int max = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' ' || s[i]==10){
			if (kitu > max)
				max = kitu;
			kitu = 0;
		}else
			kitu++;
	if (kitu > max)
		max = kitu;
	return max;
}
int demchuoicon(char *s, char s1[])
{
	int d = 0;
	while (strstr(s, s1) != NULL)
	{
		d++;
		strcpy(s, strstr(s, s1) + 1);
	}
	return d;
}
int main()
{
	char *s=new char[maxc];
	char s1[80];
	docfile(s);
	s+=4;
	cau_1(s);
	cau_2(s);
	cout<<"so tu: "<<demtu(s)<<endl;
	cout<<"so ki tu max moi tu: "<<demkitumoitu(s)<<endl;
	strcpy(s1,"your");
	cout <<"cau 5:"<<demchuoicon(s, s1);
	return 0;
}
