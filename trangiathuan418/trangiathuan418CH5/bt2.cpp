#include<iostream>
#include<string.h>
using namespace std;
void docfile(char *s){
	FILE *f;
	f=fopen("str1.txt","rt");
	while(!feof(f)){
		fgets(s,80,f);
	}
	fclose(f);
}
int demtu(char *s)
{
	int l = strlen(s), d = 1;
	for (int i = 0; i < l; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			d++;
	return d;
}
int demkitumoitu(char *s)
{
	int kitu = 0,max=0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] != ' ')
			kitu++;
		else {
			if (kitu > max)
				max = kitu;
			kitu = 0;
		}
	if (kitu > max)
		max = kitu;
	return max;
}
void ghifile(char *s)
{
	FILE* g;
	g=fopen("str1.out", "wt");
	if (!g)
	{
		cout << "khong mo duoc file g";
		return;
	}
	fprintf(g, "%d %d",demtu(s),demkitumoitu(s));
	fclose(g);
}
int main()
{
	char *s;
	s=new char[80];
	docfile(s);
	ghifile(s);
	return 0;
}
