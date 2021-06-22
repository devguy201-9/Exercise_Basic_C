#include<iostream>
#include<math.h>
#define max 100
using namespace std;
void nhapmang(int a[], int &n);
void xuatmang(int a[], int n);
void demntthoa(int a[], int n,int &dem);
void daonguocpt(int a[], int n);
void ntnhohon(int a[], int n);
void sapxepgiam(int a[], int n);
void gtlonthuk(int a[], int n, int k1);
void tachmang(int a[], int b[], int c[], int n);
int demsochan(int a[], int n);
int demsole(int a[], int n);
void sapxepchanle(int b[], int c[], int d[], int dem, int dem1);
//bai 2:
void nhapmang2(unsigned long int mang1[], int &n);
void tongchuso(unsigned long int mang1[], int n);
void ntlonnhat(unsigned long int mang1[], int n);
void tonghoanhao(unsigned long int mang1[], int n);
void demuocthucsu(unsigned long int mang1[], int n);
void thaynt(unsigned long int mang1[], int n);
//bai 5
void demnt1ty(int &n);
//bai 6
int slientiepmax(int a[], int n);
int main()
{
	int n,a[max],dem;
	int k1,b[max],c[max],d[max];
	unsigned long int mang1[max];
	nhapmang(a, n);
	//cout << "nhap gt thu k: ";
	//cin >> k1;
	/*demntthoa(a, n,dem);
	daonguocpt(a, n);
	ntnhohon(a, n);*/
	//sapxepgiam(a, n);
	//gtlonthuk(a, n, k1);
	//int x = demsochan(a, n);
	//int y = demsole(a, n);
	//tachmang(a, b, c, n);
	//sapxepchanle(b, c, d, x, y);
	//xuatmang(d, n);*/

	//bai 2:

	//nhapmang2(mang1, n);
	//tongchuso(mang1, n);
	//ntlonnhat(mang1, n);
	//tonghoanhao(mang1, n);
	//demuocthucsu(mang1, n);
	//thaynt(mang1, n);			*****/chua lam xong

	//bai 5:

	//demnt1ty(n);

	//bai 6:

	cout<<"s max thanh phan lien tiep cua mang la: "<<slientiepmax(a, n);
	cout << endl;
	return 0;
}
void nhapmang(int a[], int &n)
{
	cin >> n;
	cout << "nhap mang: "<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int checknt(int a)
{
	if (a < 2) return 0;
	int k = sqrt(a);
	for (int i = 2; i <= k; i++)
		if (a % i == 0) return 0;
	return 1;
}
void demntthoa(int a[], int n,int &dem)
{
	dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (checknt(a[i - 1]) == 1 && checknt(a[i + 1]) == 1)
		{
			dem++;
		}
	}
	cout <<"so phan tu nt thoa dk: "<< dem<<endl;
}
void daonguocpt(int a[], int n)
{
	for (int i = 0; i <=n/2; i++)
	{
		int tam = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tam;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
}
void ntnhohon(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (checknt(a[i]) == 1)
			cout << a[i] << " ";
	}
}
void sapxepgiam(int a[], int n)
{
	int LON = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				LON = a[i];
				a[i] = a[j];
				a[j] = LON;
			}
		}
	}
}
void gtlonthuk(int a[], int n, int k1)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != a[i + 1])
		{
			dem++;
			if (dem == k1)
				cout << a[i];
		}
	}
}
int solonthu2(int a[], int n)
{
	sapxepgiam(a, n);
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != a[i + 1])
			return a[i + 1];
	}
	return a[0];
}
void tachmang(int a[],int b[],int c[], int n)
{
	int k = 0,j=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]%2==0)
		{
			b[j++] = a[i];
		}
		else
		{
			c[k++] = a[i];
		}
	}
}
int demsochan(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			dem++;
		}
	}
	return dem;
}
int demsole(int a[], int n)
{
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			dem1++;
		}
	}
	return dem1;
}
void sapxepchanle(int b[], int c[], int d[], int dem, int dem1)
{
	int tam = 0,temp=0;
	for (int j = 0; j < dem; j++)
	{
		if(b[j]!=0)
			d[tam++] = b[j];
		if (b[j] == 0)
			d[tam++] = b[j];
	}
	for (int k = 0; k < dem1; k++)
	{
		d[tam++] = c[k];
	}
}
//BAI 2


void nhapmang2(unsigned long int mang1[], int& n)
{
	cin >> n;
	cout << "nhap mang duong: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> mang1[i];
	}
}
void tongchuso(unsigned long int mang1[], int n)
{
	int dv,s=0;
	for (int i = 0; i < n; i++)
	{
		while (mang1[i] > 0)
		{
			dv = mang1[i] % 10;
			s = s + dv;
			mang1[i] = mang1[i] / 10;
		}
	}
	cout << "tong cac chu so trong mang= " << s;
	cout << endl;
}
void ntlonnhat(unsigned long int mang1[], int n)
{
	int lon1=0;
	for (int i = 0; i < n; i++)
	{
		if (checknt(mang1[i]) == 1)
		{
			if(mang1[i]>lon1)
				lon1 = mang1[i];
		}
	}
	cout <<"nt lon nhat: "<<lon1;
}
int tong(int x)
{
int sum = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0) {
			sum += i;
		}
	}
	return sum;
}
void tonghoanhao(unsigned long int mang1[], int n)
{	
	cout << "tong cac uoc thuc su(so hoan hao) cua mang la: ";
	for (int i = 0; i < n; i++)
	{
		cout<<tong(mang1[i])<<"	";
	}
	cout << endl;
}
int demuoc(int x)
{
	int dem = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0) {
			dem++;
		}
	}
	return dem;
}
void demuocthucsu(unsigned long int mang1[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		cout << "so luong cac duoc thuc su cua "<<mang1[i]<<" la: "<<demuoc(mang1[i]);
		cout << endl;
	}
	cout << endl;
}
void thaynt(unsigned long int mang1[], int n)			//chua xong
{
	for (int i = 0; i < n; i++)
	{
		if (mang1[i] < checknt(mang1[i]))
			mang1[i] = checknt(mang1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << mang1[i] << " ";
	}
}
//BAI 5:
void demnt1ty(int &n)
{
	int dem = 0;
	cout << "nhap n: "; cin >> n;
	for (int i =1; i <= n; i++)
		if (checknt(i)) dem++;
		cout << dem;
}
//BAI 6:
int slientiepmax(int a[], int n)
{
	int s = 0;
	int max1=-1;
	sapxepgiam(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] - 1 == a[i + 1])
		{
			if (a[i] > s)
				s = s + a[i];
			s = s + a[i + 1];
			if (s > max1)
				max1 = s;
		}
		else
			break;
	}
	return max1;
}