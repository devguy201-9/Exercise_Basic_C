									//CHUA XONG


#include<iostream>
#include<conio.h>
using namespace std;
#define max 100
#define duong 1
#define am -1
typedef struct bignum
{
	char docso[max];
	int dau;
	int vitrisomax;
};
void inso(bignum n)
{
	int i;
	if (n.dau == am) cout << "-";
	for (i = n.vitrisomax; i >= 0; i--)
		cout << int(n.docso[i]);
}
int kiemtra(char x[])
{
	if (x[0] != '-' && !isdigit(x[0]))		//kiem tra mang co thuoc tu - 1 2 3 4 5 6 7 8 9
		return 0;
	int len = strlen(x);
	for (int i = 1; i < len; i++)
		if (!isdigit) return 0;
	return 1;
}
void nhapso(bignum& n)
{
	char temp[256];
	cin.getline(temp, 256);
	if (!kiemtra(temp))
	{
		n.vitrisomax = 0;
		n.dau = duong;
		n.docso[0]=0;
	}
	else
	{
		if (n.docso[0] != '-')
		{
			n.dau = duong;
			n.vitrisomax = strlen(temp)-1;
			for (int i = 0; i <= n.vitrisomax; i++)
				n.docso[i] = temp[n.vitrisomax - i]-48;
		}
		else
		{
			n.dau = am;
			n.vitrisomax = strlen(temp)-2;
			for (int i = 0; i <= n.vitrisomax; i++)
				n.docso[i] = temp[n.vitrisomax -i+1]-48;
		}
	}
}
void subtract(bignum &b,bignum &a, bignum c)
{

}
void addbig(bignum a, bignum b, bignum& c)
{
	int carry;
	int i;
	if (a.dau == b.dau)
		c.dau = duong;
	else
	{
		if (a.dau == am)
		{
			a.dau = duong;
			subtract(b, a, c);
			a.dau = am;
		}
		else
		{
			b.dau = duong;
			subtract(a, b, c);
			b.dau = am;
		}
		return;
	}
}
int main()
{
	bignum a;
	do {
		cout << "nhap bignum a: " << endl;
		nhapso(a);
		inso(a);
		cout << endl;
		cout << "nhan phim esc de thoat" << endl;
	} while (getch() != 27);
	return 0;
}