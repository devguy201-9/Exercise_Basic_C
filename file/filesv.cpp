#include<iostream>
#include<stdio.h>
#include<fstream>
#include<iomanip>
using namespace std;
typedef struct MH
{
	char mamh[15];
	char tenmh[20];
	int stc;
	float diem;
};
typedef struct SV
{
	char mssv[10];
	char hoten[20];
	int tuoi, somon;
	MH kq[100];
	int tongtc, tongtctl;
	float dtbc, dtbtl;
};
void docfile(const char filename[], SV& s);
void insv(SV s);
int main()
{
	SV a;
	docfile("E:/docsv.TXT",a);
	insv(a);
	return 0;	
}
void docfile(const char filename[], SV& s)
{
	char temp[100];
	FILE* fp;
	fopen_s(&fp, filename, "rt");
	if (!fp)
	{
		cout << "file khong mo duoc!";
		return;
	}
	fgets(s.mssv, 10, fp);
	s.mssv[strlen(s.mssv)-1] = '\0';		//xoa ki tu xuong dong khi doc
	fgets(s.hoten, 20, fp);
	s.hoten[strlen(s.hoten)-1] = '\0';
	fscanf_s(fp, "%d", &s.tuoi);
	fscanf_s(fp, "%d", &s.somon);
	for (int i = 0; i < s.somon; i++)
	{
		fgets(temp, 100, fp);
		fgets(temp, 100, fp);
		fgets(s.kq[i].mamh,15, fp);
		s.kq[i].mamh[strlen(s.kq[i].mamh) - 1] = '\0';
		fgets(s.kq[i].tenmh, 20, fp);
		s.kq[i].tenmh[strlen(s.kq[i].tenmh) - 1] = '\0';
		fscanf_s(fp, "%d", &s.kq[i].stc);
		fscanf_s(fp, "%f", &s.kq[i].diem);
	}
	fclose(fp);
}
void insv(SV s)
{
	cout << "ma so sinh vien: " << s.mssv << endl;
	cout << "ho va ten sinh vien: " << s.hoten << endl;
	cout << "tuoi: " << s.tuoi << endl;
	cout << "so mon hoc: " << s.somon << endl << endl;
	cout << "MA MH		TEN MH			SO TC	DIEM" << endl;
	for (int i = 0; i < s.somon; i++)
	{
		cout << s.kq[i].mamh << "	"<< s.kq[i].tenmh <<setw(8) <<right <<s.kq[i].stc << setw(9)<<right<< s.kq[i].diem << endl;
	}
}