#include<iostream>
#include<math.h>
#define max 100
using namespace std;
int ptbac2(float a, float b, float c, float& x1, float& x2);
void bonso(int a1, int b1, int c1, int d1);
void tamgiac(float a, float b, float c);
void tong(int n,int n1, float x);
void chuso(int n);
void nhapmang(int array1[], int &n);
void xuatmang(int array1[], int n);
void cau3a(int array1[], int n);
void cau3b(int array1[], int n,int &k);
int main()
{
	float a, b, c,d,x,x1,x2;
	int a1, b1, c1, d1;
	int n,n1,k;
	int array1[max];
	/*cout << "nhap he so phuong trinh bac 2: " << endl;
	cout << "nhap a (a!=0): "; cin >> a;
	while (a == 0)
	{
		cout << "nhap lai a!=0: "; cin >> a;
	}
	cout << "nhap b: "; cin >> b;
	cout << "nhap c: "; cin >> c;
	int giaipt = ptbac2(a, b, c, x1, x2);
	if (giaipt == 0)
		cout << "phuong trinh bac 2 vo nghiem\n";
	else if (giaipt == 1)
		cout << "phuong trinh bac 2 co mot nghiem: " << x1 << endl;
	else
	{
		cout << "phuong trinh bac 2 co 2 nghiem phan biet: " << endl;
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
	}
	cout << "nhap 4 so nguyen\n";
	cin >> a1 >> b1 >> c1 >> d1;
	bonso(a1, b1, c1, d1);
	cout << "nhap do dai 3 canh cua tam giac: \n";
	cin >> a >> b >> c;
	tamgiac(a, b, c);*/
	//cout << "nhap so nguyen thu n: "; cin >> n;
	//cout << "nhap so nguyen thu n cua tong 2(n>=1): "; cin >> n1;
	//cout << "nhap bien x can tinh: "; cin >> x;
	//tong(n, n1, x);
	/*cout << "nhap gioi han can liet ke so thoa dieu kien: "; cin >> n;
	while (n<10000)
	{
		cout << "nhap lai gioi han so tu 5 chu so: "; cin >> n;
	}
	chuso(n);*/
	nhapmang(array1, n);
	xuatmang(array1, n);
	//cau3a(array1, n);
	cau3b(array1, n,k);
	return 0;
}
int ptbac2(float a, float b, float c, float& x1, float& x2)
{
	float delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		x1 = x2 = 0.0;
		return 0;
	}
	else if (delta == 0)
	{
		x1 = x2 = -b / (2 * a);
		return 1;
	}
	else
	{
		delta = sqrt(delta);
		x1 = (-b + delta) / (2 * a);
		x2 = (-b - delta) / (2 * a);
		return 2;
	}
}
void hoanvi(int& a, int& b)
{
	if (a > b)
	{
		int tam = a;
		a = b;
		b = tam;
	}
}
void hoanvi1(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}
void bonso(int a1, int b1, int c1, int d1)
{
	int max1 = a1;
	if (b1 > max1)
		max1 = b1;
	if (c1 > max1)
		max1 = c1;
	if (d1 > max1)
		max1 = d1;
	cout << "gia tri lon nhat trong 4 so la: " << max1 << endl;
	hoanvi(a1, b1);
	hoanvi(b1, c1);
	hoanvi(c1, d1);
	hoanvi(a1, b1);
	hoanvi(b1, c1);
	hoanvi(a1, b1);
	cout << "4 so theo chieu tang dan: " << a1<<" " <<b1 <<" "<< c1 <<" "<< d1 << endl;
}
void tamgiac(float a, float b, float c)
{
	float pi = 3.141592;
	cout << "chu vi tam giac la: " << a + b + c << endl;
	float tu, mau,h,s,r,r1;
	tu = sqrt(b * b * c * c);
	mau = sqrt(b * b + c * c);
	h = tu / mau;
	s = (0.5) * c * h;
	cout << "dien tich tam giac la: " << s << endl;
	cout << "duong cao tam giac ke tu A la: " << h << endl;
	r = (2 * s) / (a + b + c);
	r1 = (a * b * c) / (4 * s);
	cout << "dien tich duong tron noi tiep tam giac la: " << r * r * pi << endl;
	cout << "dien tich duong tron ngoai tiep tam giac la: " << r1 * r1 * pi << endl;
}
void tong(int n, int n1, float x)
{
	float s = 0, s1 = 0, s2 = 0;
	int tam = 1;
	float tu=0, mau=0,mau1=0;

	for (int i = 1; i <= n; i++)
	{
		tam = tam*i;
		s += tam;
		mau +=(float) 1 / i;
		s1 += i / mau;
	}
	for (int i = 1; i <= n1; i++)
	{
		tu += pow((-1), (i - 1)) * pow(x, i);
		mau1 += (float)1 / i;
		s2 += tu / mau1;
	}
	cout << "tong thu 1 cua " << n << " so nguyen la: " << s << endl;
	cout << "tong thu 2 cua " << n << " so nguyen la: " << s1 << endl;
	cout << "tong thu 3 cua " << n1 << " so nguyen la: " << s2 << endl;
}
int checknt(int n)
{
	if (n < 2) return 0;
	int k = sqrt(n);
	for (int i = 2; i <= k; i++)
		if (n % i == 0) return 0;
	return 1;
}
int sodao(int n)
{
	int dv, s = 0;
	while (n != 0)
	{
		dv = n % 10;
		s = (s * 10)+ dv;
		n /= 10;
	}
	return s;
}
bool doixung(int n)
{
	if (n == sodao(n))
		return 1;
	return 0;
}
void chuso(int n)
{
	cout << "nhung so k thoa dk: " << endl;
	for (int i = 10000; i <= n; i++)
	{
		if ((checknt(i) == 1)&&(doixung(i)==1))
			cout << i << " ";
	}
}
void nhapmang(int array1[], int &n)
{
	cout << "nhap so luong phan tu cua mang: "; cin >> n;
	cout << "nhap mang: " << endl;
	for (int i = 0; i < n; i++)
		cin >> array1[i];
}
void xuatmang(int array1[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;
}
void cau3a(int array1[], int n)
{
	int max1=-1, max2=-1,max3=-1, dem = 0, s = 0;
	int dv, tam;
	for (int i = 0; i < n; i++)
	{
		tam = array1[i];
		if (array1[i] > max1)
			max1 = array1[i];
		if (checknt(array1[i]) == 1)
		{
			dem++;
			if (array1[i] > max2)
				max2 = array1[i];
		}
		if (array1[i] % 2 == 0)
		{
			if (array1[i] > max3)
				max3 = array1[i];
		}
		while (tam > 0)
		{
			dv = tam % 10;
			s += dv;
			tam /= 10;
		}
	}
	cout << "gia tri lon nhat cua day la: " << max1 << endl;
	cout << "co " << dem << " snt trong day" << endl;
	cout << "tong cac chu so cua day la: " << s << endl;
	cout << "gia tri chan lon nhat cua day la: " << max3 << endl;
	cout << "snt lon nhat cua day la: " << max2 << endl;
}
void cau3b(int array1[], int n,int &k)
{
	int dem = 0;
	int dem1 = 0, dem2 = 0, tam = 0, max1 = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (array1[i] + 1 == array1[i + 1])
			dem1++;
		if (dem1 > max1)
			max1 = dem1;
		if ((array1[i] + 1 != array1[i + 1]) && dem1 != 0)
		{
			dem1 = 0;
			dem2++;
		}
	}
	for (int j = n - 1; j > 0; j--)
	{
		if (array1[j] - 1 != array1[j - 1])
			break;
		if (array1[j] - 1 == array1[j - 1])
			tam++;
	}
	if (tam != 0)
			dem2++;
	cout << "co " << dem2 << " day con lien tiep tang trong day" << endl;
	cout << "chieu dai cua day con tang lien tiep dai nhat la: " << max1 << endl;
	cout << "snt ma dao nguoc cua no cung la snt: ";
	for (int i = 0; i < n; i++)
	{
		if (checknt(array1[i]) == 1)
		{
			if (checknt(sodao(array1[i])) == 1)
			{
				cout << array1[i] << " ";
				dem++;
			}
		}
	}
	if(dem==0)
		cout << "khong co";
	cout << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array1[i] > array1[j])
				hoanvi1(array1[i], array1[j]);
		}
	}
	cout << "mang sau khi sap xep tang dan: ";
	xuatmang(array1, n);
	cout << "nhap so lon thu k cua mang: "; cin >> k;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array1[i] < array1[j])
				hoanvi1(array1[i], array1[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) == k)
			cout << "so lon thu " << k << " cua mang la: " << array1[i];
	}
	cout << endl;
	for (int i = n-1; i > 0; i--)
	{
		for (int j = i - 1; j >=0 ; j--)
		{
			if (checknt(array1[i]) == 0)
			{
				if (checknt(array1[j]) == 1)
				{
					hoanvi1(array1[i], array1[j]);
					break;
				}
			}
		}
	}
	cout << "snt ve cuoi mang: ";
	xuatmang(array1, n);
}