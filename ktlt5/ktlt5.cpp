#include<iostream>
#define maxc 80
using namespace std;
void demam(char s[], int& d1, int& d2)
{
	d1 = 0, d2 = 0;
	int l = strlen(s);
	for (int i = 0; i < l; i++)
		if (s[i] != ' ' && (s[i] == 'a' || s[i] == 'u' ||
			s[i] == 'i' || s[i] == 'o' || s[i] == 'e'))
			d1++;
		else if (s[i] != ' ')
			d2++;
}
int daonguoc(char s[])
{
	int i = 0, j = strlen(s) - 1,flag=0;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			flag = 1;
			break;
		}
		i++; j--;
	}
	if (flag == 1) return 0;
	return 1;
}
int demtu(char s[])
{
	int l = strlen(s), d = 1;
	for (int i = 0; i < l; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			d++;
	return d;
}
void demkitumoitu(char s[],int max)
{
	int kitu = 0;
	max = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] != ' ')
			kitu++;
		else {
			cout << kitu << " ";
			if (kitu > max)
				max = kitu;
			kitu = 0;
		}
	cout << kitu;
	if (kitu > max)
		max = kitu;
}
void demammax(char s[])
{
	int d=0,max = -1,vt=0;
	int temp,l,leng=0;
	for (int i = 0; i < strlen(s); i++)
	{
		leng++;
		if (s[i] != ' ' && (s[i] == 'a' || s[i] == 'u' ||
			s[i] == 'i' || s[i] == 'o' || s[i] == 'e'))
				d++;
		else if (s[i] == ' ') {
			if (d > max) {
				max = d;
				temp = vt;
				l = leng;
			}
			vt = i+1;
			d = 0;
			leng = 0;
		}
	}
	if (d > max) {
		max = d;
		temp = vt;
		l = leng;
	}
	for (int i=0; i < l; i++)
		cout << s[temp++];
}
void tanso(char s[])
{
	int l = strlen(s);
	int d[255];
	for (int i = 0; i < l; i++)
		d[s[i]] = 0;
	for (int i = 0; i < l; i++)
		d[s[i]]++;
	for(int i=0;i<l;i++)
		if (d[s[i]] != 0 && s[i]!=' ')
		{
			cout << s[i]<< d[s[i]] << " ";
			d[s[i]] = 0;
		}
}
char* tachchuoi(char *s,int k)
{
	int l = strlen(s), d = 1;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
			d++;
		if (d == k+1)
			s[i] = '\0';
	}
	return s;
}
int demchuoicon(char s[], char s1[])
{
	int d = 0;
	while (strstr(s, s1) != NULL)
	{
		d++;
		strcpy_s(s, maxc, strstr(s, s1) + 1);
	}
	return d;
}
int main()
{
	char s[maxc],s2[maxc];
	//char* s1=new char[maxc];
	int d1, d2,k;
	strcpy_s(s,maxc ,"programming is art");
	//demam(s, d1, d2);
	//cout << d1 << " " << d2 << endl;
	//cout << demtu(s) << endl;
	//demammax(s);
	//tanso(s);
	/*for (int i = 0; i < strlen(s); i++)
		s1[i] = s[i];
	s1[strlen(s)] = '\0';
	cout << "nhap k tu: ";
	cin >> k;
	cout << tachchuoi(s1,k);*/
	strcpy_s(s2, maxc, "is art");
	cout << demchuoicon(s, s2);
	return 0;
}