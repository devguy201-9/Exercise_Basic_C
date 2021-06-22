#include<iostream>
#include<math.h>
#include<cstring>
#include<stdio.h>
#define max 100
using namespace std;
struct phanso
{
	int tu;
	int mau;
};
struct diem
{
	float x;
	float y;
};
struct thisinh
{
	int sbd;
	char hoten[30];
	int ngoaingu, coso, cnghanh;
};
void nhapmangps(phanso ps[], int& n);
void xuatmangps(phanso ps[], int& n);
void rutgon(phanso ps[],int n);
void dempsdk(phanso ps[], int n);
void dempsnt(phanso ps[], int n);
void sapxeppstang(phanso ps[], int n);
void tongps(phanso ps[], int n);
//BAI 2
void nhapdiem(diem a[],int n);
void xuatdiem(diem a[],int n);
void demptuthu1(diem a[],int n);
void capdiemgannhau(diem a[], int n);
void hcn(diem a[], int n);
void demss(diem a[], int n);
//BAI 3
void nhapts(thisinh b[], int n);
void xuatts(thisinh b[], int n);
void timkqts(thisinh b[], int n, int k);
void max2mon(thisinh b[], int n);
void tbcong(thisinh b[], int n);
void timtsdk(thisinh b[], int n);
void sapxep(thisinh b[], int n);
void xuatts1(thisinh b[], int n);

int main()
{
	phanso ps[max];
	int n;
	//nhapmangps(ps, n);
	/*rutgon(ps, n);
	xuatmangps(ps, n);
	dempsdk(ps, n);
	dempsnt(ps, n);
	sapxeppstang(ps, n);
	xuatmangps(ps, n);*/
	//tongps(ps, n);

	//BAI 2

	diem a[max];
	/*cout << "nhap so luong diem= "; cin >> n;
	nhapdiem(a, n);
	xuatdiem(a, n);
	demptuthu1(a, n);
	capdiemgannhau(a, n);
	//hcn(a, n);
	demss(a, n);*/

	//BAI 3	
	thisinh b[max];
	int k;
	cout << "nhap so luong thi sinh: "; cin >> n;
	nhapts(b, n);
	cout << "\n	danh sach cua tat ca thi sinh" << endl << endl;
	xuatts(b, n);
	cout << "nhap sbd cua ts can tim: "; cin >> k;
	cout << endl;
	timkqts(b, n, k);
	tbcong(b, n);
	max2mon(b, n);
	timtsdk(b, n);
	xuatts1(b, n);
	return 0;
}
void nhapmangps(phanso ps[], int& n)
{
	cout << "nhap so luong phan so n= ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap phan so thu " << i << " :" << endl;
		cin >> ps[i].tu;
		cin >> ps[i].mau;
	}
}
void xuatmangps(phanso ps[], int& n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << ps[i].tu << "/" << ps[i].mau << ";";
}
int ucln(int a, int b)
{
	int r = a % b;
	while (r!=0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
void rutgon(phanso ps[],int n)
{
	for (int i = 0; i < n; i++)
	{
		int c = ucln(ps[i].tu, ps[i].mau);
		ps[i].tu = ps[i].tu / c;
		ps[i].mau = ps[i].mau / c;
	}
}
void dempsdk(phanso ps[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		float chia = (float)ps[i].tu / (float)ps[i].mau;
		if (chia > 0 && chia < 1)
			dem++;
	}
	if(dem==0)
		cout << "khong co phan so nho hon 1 va lon hon 0" << endl;
	else
		cout << "co "<<dem<<" phan so nho hon 1 va lon hon 0" << endl;
}
int checknt(int x)
{
	if (x < 2) return 0;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++)
		if (x % i == 0) return 0;
	return 1;
}
void dempsnt(phanso ps[], int n)
{
	int dem = 0;
	rutgon(ps, n);
	for (int i = 0; i < n; i++)
	{
		if ((checknt(ps[i].tu) == 1) && (checknt(ps[i].mau) == 1))
			dem++;
	}
	if (dem == 0)
		cout << "khong co ps ma tu va mau deu la snt" << endl;
	else
		cout << "co " << dem << " ps ma tu va mau deu la snt" << endl;
}
void hoanvi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}
void sapxeppstang(phanso ps[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		float chia = (float)ps[i].tu / (float)ps[i].mau;
		float chia1 = (float)ps[i+1].tu / (float)ps[i+1].mau;
		if (chia > chia1)
		{
			hoanvi(ps[i].tu, ps[i + 1].tu);
			hoanvi(ps[i].mau, ps[i + 1].mau);
		}
	}
}
void tongps(phanso ps[], int n)
{
	int stu=0,smau=0,tam,tam1;
	rutgon(ps, n);
	for (int i = 0; i < n-1; i++)
	{
		if (i == 0)
		{
			tam = ps[i].tu;
			tam1 = ps[i].mau;
			stu += tam * ps[i + 1].mau + ps[i + 1].tu * tam1;
			smau += tam1 * ps[i + 1].mau;
			int c = ucln(stu, smau);
			stu /= c;
			smau /= c;
		}
		else
		{
			stu = stu * ps[i + 1].mau + ps[i + 1].tu * smau;
			smau = smau * ps[i + 1].mau;
			int c = ucln(stu,smau);
			stu /= c;
			smau /= c;
		}
	}
	cout << "tong gia tri cac phan so= " << stu << "/" << smau;
	cout << endl;
}
//BAI 2
void nhapdiem(diem a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap x"<<i<<"= "; cin >> a[i].x;
		cout << "nhap y" << i << "= "; cin >> a[i].y;
	}
}
void xuatdiem(diem a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i].x <<","<< a[i].y << "	";
	}
	cout << endl;
}
void demptuthu1(diem a[],int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].x > 0 && a[i].y > 0)
			dem++;
	}
	if (dem == 0)
		cout << "khong co diem nao thuoc phan tu thu 1" << endl;
	else
		cout << "co " << dem << " diem thuoc phan tu thu 1" << endl;
}
void capdiemgannhau(diem a[], int n)
{
	int min = 1000000,vitri=0;
	float s = 0;
	for (int i = 0; i < n-1; i++)
	{
		s =(float) sqrt(pow(a[i + 1].x - a[i].x, 2) + pow(a[i + 1].y - a[i].y, 2));
		if (s < min)
		{
			min = s;
			vitri = i;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (i == vitri)
		{
			cout << "cap diem gan nhau nhat la: ";
			cout << a[i].x << "," << a[i].y << "	" << a[i + 1].x << "," << a[i + 1].y;
			cout << endl;
		}
	}
}
void hcn(diem a[], int n)
{
	int max1 = -1,max2=-1;
	int min1 = 1000000,min2= 1000000;
	for (int i = 0; i < n; i++)
	{
		if (a[i].x <= min1 && a[i].y <= min2)
		{
			min1 = a[i].x;
			min2 = a[i].y;
		}
		if (a[i].x >= max1 && a[i].y >= max2)
		{
			max1 = a[i].x;
			max2 = a[i].y;
		}
	}
	cout << max1 << " " << max2 << "	" << min1 << " " << min2;
}
void demss(diem a[], int n)
{
	int dem = 0,dem1=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].x == a[j].x)
				dem++;
			if (a[i].y == a[j].y)
				dem1++;
		}
	}
	cout << "so doan thang song song voi truc tung la: " << dem << endl;
	cout << "so doan thang song song voi truc hoanh la: " << dem1<<endl;
}
//BAI 3
void nhapts(thisinh b[], int n)
{
	cout << "***nhap thong tin thi sinh" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap sbd thi sinh: "; cin >> b[i].sbd;
		cin.ignore(32767, '\n');
		cout << "nhap ho va ten thi sinh: ";
		gets_s(b[i].hoten);
		cout << "nhap diem mon ngoai ngu: "; cin >> b[i].ngoaingu;
		cout << "nhap diem mon co so: "; cin >> b[i].coso;
		cout << "nhap diem mon chuyen nghanh: "; cin >> b[i].cnghanh;
		cout << endl;
	}
}
void xuatts(thisinh b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << b[i].sbd<<"	"<< b[i].hoten;
		cout << endl;
		cout << "diem mon ngoai ngu: " << b[i].ngoaingu;
		cout << endl;
		cout << "diem mon co so: " << b[i].coso;
		cout << endl;
		cout << "diem mon chuyen nghanh: " << b[i].cnghanh;
		cout << endl << endl;
	}
}
void timkqts(thisinh b[], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (b[i].sbd == k)
		{
			cout << b[i].sbd << "	" << b[i].hoten;
			cout << endl;
			cout << "diem mon ngoai ngu: " << b[i].ngoaingu;
			cout << endl;
			cout << "diem mon co so: " << b[i].coso;
			cout << endl;
			cout << "diem mon chuyen nghanh: " << b[i].cnghanh;
			cout << endl << endl;
		}
	}
}
void max2mon(thisinh b[], int n)
{
	int max1 = -1,vitri=0,s;
	for (int i = 0; i < n; i++)
	{
		s = 0;
		s = b[i].coso + b[i].cnghanh;
		if (s >= max1)
			max1 = s;
	}
	for (int i = 0; i < n; i++)
	{
		s = 0;
		s = b[i].coso + b[i].cnghanh;
		if (s == max1)
		{
			cout << b[i].sbd << "	" << b[i].hoten;
			cout <<"	" << b[i].coso;
			cout <<"	" << b[i].cnghanh;
			cout << endl << endl;
		}
	}
}
void tbcong(thisinh b[], int n)
{
	int s = 0,s1=0,s2=0;
	for (int i = 0; i < n; i++)
	{
		s += b[i].ngoaingu;
		s1 += b[i].coso;
		s2 += b[i].cnghanh;
	}
	cout << "mon ngoai ngu: " << (float)s / n << endl;
	cout << "mon co so: " << (float)s1 / n << endl;
	cout << "mon chuyen nghanh: " << (float)s2 / n << endl;
	cout << endl;
}
void timtsdk(thisinh b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((b[i].cnghanh >= 8) && (b[i].coso >= 8) && (b[i].ngoaingu >= 5))
		{
			cout << b[i].sbd << "	" << b[i].hoten << "	";
			cout << b[i].ngoaingu << "	";
			cout << b[i].coso << "	";
			cout << b[i].cnghanh;
			cout << endl << endl;
		}
	}
}
void sapxep(thisinh b[], int n)
{
	thisinh c;
	int s, s1;
	for (int i = 0; i < n; i++)
	{
		s = b[i].coso + b[i].cnghanh;
		s1 = b[i + 1].coso + b[i + 1].cnghanh;
		if (s < s1)
		{
			c = b[i];
			b[i] = b[i + 1];
			b[i + 1] = c;
		}
	}
}
void xuatts1(thisinh b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (b[i].ngoaingu >= 5)
		{
			sapxep(b, n);
			cout << b[i].sbd << "	" << b[i].hoten<<"	" << b[i].ngoaingu<< "	" << b[i].coso<< "	"  << b[i].cnghanh;
			cout << endl << endl;
		}
	}
}