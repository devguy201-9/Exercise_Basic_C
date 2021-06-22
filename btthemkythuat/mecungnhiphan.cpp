#include<iostream>
#define max 6
using namespace std;
struct o
{
	int row, col;
};
int a[max][max] = {
	{1,0,1,1,0,0},
	{0,1,0,1,0,0},
	{0,1,0,1,1,0},
	{1,0,0,0,1,1},
	{0,1,1,1,0,0},
	{1,0,0,0,1,1},
};
int temp[max][max];
int n = 6;
o kq[100];
int nk = 0;
int check(o x, int huong)
{
	switch (huong)
	{
	case 0: if (x.col == 0) return 1;		//trai
		break;
	case 1: if (!x.row) return 1;		//tren
		break;
	case 2: if (x.col == n-1) return 1;		//phai
		break;
	case 3: if (x.row == n-1) return 1;		//duoi
		break;
	}
	return 0;
}
void khoitao()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = 0;
}
void mecung(o x, int huong)
{
	if (check(x, huong))
	{
		cout << "tim duoc duong di" << endl;
		for (int i = 0; i < nk; i++)
			cout << "(" << kq[i].row << "," << kq[i].col << ")-->";
		cout <<"end."<< endl;
	}
	for(int i=1;i>=-1;i--)
		for(int j=1;j>=-1;j--)
			if ((i || j) && x.row+i >= 0 && x.row+i < n && x.col+j >= 0 && x.col+j < n)
			{
				o tieptheo;
				tieptheo.row = x.row + i;
				tieptheo.col = x.col + j;
				if (a[tieptheo.row][tieptheo.col] == a[x.row][x.col] && !temp[tieptheo.row][tieptheo.col])
				{
					temp[tieptheo.row][tieptheo.col] = 1;
					kq[nk++] = tieptheo;
					mecung(tieptheo, huong);
					nk--;
					temp[tieptheo.row][tieptheo.col] = 0;
				}
			}
}
int main()
{
	khoitao();
	o start;
	start.row = 2;		//vi tri xuat phat
	start.col = 2;
	temp[start.row][start.col] = 1;
	kq[nk++] = start;
	mecung(start,2);
	return 0;
}