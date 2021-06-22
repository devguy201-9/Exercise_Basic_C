#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<ctime>
#define max 10
using namespace std;
//void docfile(const char filename[], int a[][max], int& n);
void inmatran(int a[][max], int n);
bool gianlan(int a[][max], int n);
int checkwinhang(int a[][max], int n, int c, int d);
int checkwincot(int a[][max], int n, int d, int c);
int checkwindcc(int a[][max], int n, int d, int c);
int checkwindcp(int a[][max], int n, int d, int c);
int checkwin(int a[][max], int n, int d, int c);
void ganchomang(int a[][max], int n);
int main()
{
	int a[max][max];
	int xx,xy,ox,oy,temp=0,n=10;
	int xd,tam=0;
	char c;
	//docfile("E:/caro.TXT", a, n);
	//inmatran(a, n);
	srand(time(NULL));
	xd = rand() % 2;
	ganchomang(a, n);
	do
	{
		do {
			if (xd == 1)
			{
				cout << "nhap vi tri can danh cua nguoi danh quan X" << endl;
				cin >> xx >> xy;		//xx la dong ,xy la cot
				a[xx][xy] = 1;
				if (checkwin(a, n, xx, xy) == 1)
				{
					cout << "nguoi danh X thang van co nay" << endl;
					break;
				}
				cout << "nhap vi tri can danh cua nguoi danh quan O" << endl;
				cin >> ox >> oy;
				a[ox][oy] = 0;
				if (checkwin(a, n, ox, oy) == 1)
				{
					cout << "nguoi danh O thang van co nay" << endl;
					break;
				}
			}
			else
			{
				cout << "nhap vi tri can danh cua nguoi danh quan O" << endl;
				cin >> ox >> oy;
				a[ox][oy] = 0;
				if (checkwin(a, n, ox, oy) == 1)
				{
					cout << "nguoi danh O thang van co nay" << endl;
					break;
				}
				cout << "nhap vi tri can danh cua nguoi danh quan X" << endl;
				cin >> xx >> xy;
				a[xx][xy] = 1;
				if (checkwin(a, n, xx, xy) == 1)
				{
					cout << "nguoi danh X thang van co nay" << endl;
					break;
				}
			}
		} while (true);
		inmatran(a, n);
		cout << endl;
		cout << "ban co muon choi tiep hay khong ?" << endl;
		cout << "nhap c de choi tiep hoac ki tu bat ki de thoat "; cin >> c;
	} while (c=='c'||c=='C');
										// CARO DOC TU FILE
	//if (gianlan(a, n)) cout << "so luot danh hop le" << endl;
	//else
	//	cout << "so luot danh khong hop le" << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		if(a[i][j]!=-1)
	//		{
	//			if ((checkwinhang(a, n, i, j) == 1) || (checkwincot(a,n,i,j)==1) || (checkwindcc(a,n,i,j)==1) || (checkwindcp(a,n,i,j)==1))
	//			{
	//				cout <<"o vi tri (" <<i << "," << j<<") thi ";
	//				temp = 1;
	//				if (a[i][j] == 1)
	//				{
	//					cout << "nguoi danh X thang van co nay" << endl;
	//					break;
	//				}
	//				else
	//				{
	//					cout << "nguoi danh O thang van co nay" << endl;
	//					break;
	//				}
	//			}
	//			else
	//				temp = 0;
	//		}
	//	}
	//	if (temp == 1)
	//		break;
	//}
	//if(temp==0)
	//	cout << "van co nay chua co nguoi thang cuoc" << endl;
	return 0;
}
//void docfile(const char filename[], int a[][max], int& n)
//{
//	FILE* fp;
//	fopen_s(&fp, filename, "rt");
//	if (!fp) {
//		cout << "khong the mo file";
//		return;
//	}
//	fscanf_s(fp, "%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			fscanf_s(fp, "%d", &a[i][j]);
//	fclose(fp);
//}
void ganchomang(int a[][max], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -1;
}
void inmatran(int a[][max], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == -1)
				cout << setw(5)<<" ";
			else
				cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
}
bool gianlan(int a[][max], int n)
{
	int dem = 0, dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
				dem++;
			if (a[i][j] == 1)
				dem1++;
		}
	}
	int k = dem - dem1;
	return (abs(k) <= 1);
}
int checkwinhang(int a[][max], int n, int d, int c)
{
	//c la dong ,d la cot
	//kiem tra duong ngang
	int j1 = c;
	int	j2 = c;	//chay qua phai va trai noi can xet
	while (j1 >= 0 && a[d][j1] == a[d][c])
	{
		j1--;
	}
	while (j2 < n && a[d][j2] == a[d][c])
	{
		j2++;
	}
	if (j2-j1-1 == 5)
		return 1;
	return 0;
}
int checkwincot(int a[][max],int n,int d,int c)
{
	int c1 = d;
	int	c2 = d;
	while (c1 >= 0 && a[c1][c] == a[d][c])
	{
		c1--;
	}
	while (c2 < n && a[c2][c] == a[d][c])
	{
		c2++;
	}
	if (c2-c1-1 == 5)
		return 1;
	return 0;
}
int checkwindcc(int a[][max], int n, int d, int c)
{
	int j1 = c, j2 = c;
	int c1 = d ,c2 = d;
	while (j1 >= 0 && c1 >= 0 && a[c1][j1] == a[d][c])
	{
		j1--;
		c1--;
	}
	while (j2 < n && c2 < n && a[c2][j2] == a[d][c])
	{
		j2++;
		c2++;
	}
	if (c2 - c1 - 1 == 5)
		return 1;
	return 0;
}
int checkwindcp(int a[][max], int n, int d, int c)
{
	int j1 = c, j2 = c;
	int c1 = d, c2 = d;
	while (j1 >= 0 && c1 < n && a[c1][j1] == a[d][c])
	{
		j1--;
		c1++;
	}
	while (j2 < n && c2 >=0 && a[c2][j2] == a[d][c])
	{
		j2++;
		c2--;
	}
	if (j2-j1-1 == 5)
		return 1;
	return 0;
}
int checkwin(int a[][max], int n, int d, int c)
{
	if ((checkwinhang(a, n, d, c) == 1) || (checkwincot(a, n, d, c) == 1) || (checkwindcc(a, n, d, c) == 1) || (checkwindcp(a, n, d, c) == 1))
		return 1;
	return 0;
}