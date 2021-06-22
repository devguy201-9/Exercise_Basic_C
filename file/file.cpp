#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int main()
{
	FILE* fp;
	int n,a[100];
	//ghi file
	cout << "nhap so phan tu: "; cin >> n;
	cout << "nhap mang: " << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	fopen_s(&fp, "E:/thuan.txt", "wt");
	if (fp == NULL)
	{
		cout << "khong mo duoc tap tin.";
		return -1;
	}
	fprintf(fp,"%d\n",n);
	for (int i = 0; i < n; i++)
		fprintf(fp, "%5d", a[i]);
	fclose(fp);
	//doc file
	fopen_s(&fp, "E:/thuan.txt", "rt");
	if (fp == NULL)
	{
		cout << "khong mo duoc tap tin.";
		return -1;
	}
	fscanf_s(fp, "%d",&n);
	for (int i = 0; i < n; i++)
		fscanf_s(fp, "%d", &a[i]);
	fclose(fp);
	cout << "so phan tu cua file la: " << n << endl;
	cout << "mang vua doc la: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	/*DOC NHI PHAN
		thay"rt" / "wt" = "rb" / "wb"
		fread_s(&n, sizeof(n), sizeof(int), 1, fp);
		fwrite(&n, sizeof(int), 1, fp);*/
	return 0;
}
