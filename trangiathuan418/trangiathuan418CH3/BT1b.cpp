#include<iostream>
using namespace std;
int sd = 0,sum=0,d=0;
int sodao(int n)
{
    if (n == 0) return sd;
    int donvi = n % 10;
    sd = sd * 10 + donvi;
    sodao(n / 10);
}
int maxchuso(int n, int& max)
{
	int dv;
	if (n == 0) return max;
	else
	{
		dv = n % 10;
		if (dv > max) max = dv;
	}
	return maxchuso(n / 10, max);
}
int tinhTong(int n)
{
    if (n != 0)
    {
        int dv = n % 10;
        sum = sum + dv;
        tinhTong(n / 10);
    }
    return sum;
}
int demcsn(int n)
{
    if (n != 0)
    {
        d++;
        int dv = n % 10;
        demcsn(n / 10);
    }
    return d;
}
int main()
{
    int n,max=0;
    cout << "nhap n: "; cin >> n;
	cout <<sodao(n) <<" "<<maxchuso(n, max)<<" "<<tinhTong(n)<<" "<<demcsn(n);
    return 0;
}
