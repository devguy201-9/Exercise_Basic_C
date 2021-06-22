#include<iostream>
#include<math.h>
#define max 50
using namespace std;
struct dt
{
	int x, y;
	float r;
};
void nhapdt(dt& dt1);
void xuatdt(dt dt1);
float cvdt(dt dt1, float pi);
float dtdt(dt dt1, float pi);
void vttuongdoi(dt dt1, dt dt2);
int main()
{
	dt dt1, dt2;
	float pi = 3.14159;
	nhapdt(dt1);
	xuatdt(dt1);
	cout << "chu vi cua duong tron=" << cvdt(dt1, pi) << endl;
	cout << "dien tich cua duong tron=" << dtdt(dt1, pi) << endl;
	cout << "nhap toa do va ban kinh cho duong tron 2:" << endl;
	nhapdt(dt2);
	vttuongdoi(dt1, dt2);
	return 0;
}
void nhapdt(dt& dt1)
{
	cout << "nhap toa do tam x: "; cin >> dt1.x;
	cout << "nhap toa do tam y: "; cin >> dt1.y;
	cout << "nhap ban kinh cua duong tron: "; cin >> dt1.r;
}
void xuatdt(dt dt1)
{
	cout << "toa do tam x,y va ban kinh r cua duong tron la: ((" << dt1.x << "," << dt1.y << ")," << dt1.r << ")" << endl;
}
float cvdt(dt dt1, float pi)
{
	return 2 * pi * dt1.r;
}
float dtdt(dt dt1, float pi)
{
	return pi * dt1.r * dt1.r;
}
void vttuongdoi(dt dt1, dt dt2)
{
	float cong, tru;
	int tam;
	cong = dt1.r + dt2.r;
	tru = abs(dt1.r - dt2.r);
	tam = sqrt(pow((dt2.x - dt1.x), 2) + (pow((dt2.y - dt1.y), 2)));
	if (dt1.y == dt2.y && dt1.x == dt2.x && dt1.r == dt2.r)
		cout << "hai duong tron trung nhau" << endl;
	if (dt1.y == dt2.y && dt1.x == dt2.x && dt1.r < dt2.r)
		cout << "duong tron 1 nam trong duong tron 2" << endl;
	if (dt1.y == dt2.y && dt1.x == dt2.x && dt1.r > dt2.r)
		cout << "duong tron 2 nam trong duong tron 1" << endl;
	if (tru < tam && tam < cong)
		cout << "hai duong tron cat nhau" << endl;
	if (tam == tru)
		cout << "hai duong tron tiep xuc trong" << endl;
	if (tam == cong)
		cout << "hai duong tron tiep xuc ngoai" << endl;
	if (tam > cong)
		cout << "hai duong tron nam ngoai nhau" << endl;
	if (tam < tru)
		cout << "hai duong tron dung nhau" << endl;
}