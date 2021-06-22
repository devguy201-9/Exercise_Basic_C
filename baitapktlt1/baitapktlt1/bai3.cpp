#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
void docfile(string &s, int& n);
void sapxepvaxoa(string& s, int& n);
void tansuat(string& s, int& n);
void ghifile(string s, int n);
int main()
{
	int n;
	string s1;
	docfile(s1, n);
	sapxepvaxoa(s1, n);
	tansuat(s1, n);
	ghifile(s1, n);
	return 0;
}
void docfile(string &s, int& n)
{
	FILE* f;
	char s1[500];
	fopen_s(&f, "input.txt", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fgets(s1, 500, f);
	s = s1;
	n = s.length();
	fclose(f);
}
void ghifile(string s, int n)
{
	FILE* g;
	fopen_s(&g, "output.txt", "wt");
	if (!g)
	{
		cout << "khong mo duoc file g";
		return;
	}
	for(int i=0;i<n;i++)
		fprintf(g, "%c", s[i]);
	fclose(g);
}
void XoaViTri(string &s,int &n,int k)
{
	for (int i = k + 1; i < n; i++)
		s[i - 1] = s[i];
	n--;
}
void sapxepvaxoa(string &s, int &n)
{
	int vt = 0;
	char temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] > s[j]) {
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
	for (int i = 0; i < n; i++)
		if (s[i] != ' ')
		{
			vt = i;
			break;
		}
	for (int i = vt-1; i >= 0; i--)
		XoaViTri(s, n, i);
}
void tansuat(string &s, int &n)
{
	int dem=0;
	char temp;
	string t;
	temp = s[0];
	s[n] = '\0';
	for (int i = 0; i <= n; i++)
	{
		if (s[i] != temp)
		{
			t += temp;
			//su dung thu vien sstream de chuyen int sang string
			ostringstream convert;
			convert << dem;
			t += convert.str();
			dem = 1;
			temp = s[i];
		}
		else
			dem++;
	}
	s = t;
	n = s.length();
}