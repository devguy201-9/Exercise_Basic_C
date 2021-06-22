#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<stdio.h>
#define max 100
using namespace std;
void taotk(int a[]);
void taotienrand(int b[]);
void tentk(int k);
void checktk(int &k);
void phim1();
void phim2(int a[], int b[], int &k);
void phim3(int a[], int b[], int &k, int &add);
void phim4(int a[], int b[], int &k,int &k2, int &add);
void phim5(int a[], int b[]);
void phim6();
void phim7();
void chonphim(int a[],int b[],int& luachon, int& k, int& add, int& k2);
int main(int argc,char* argv[])
{
	int a[max],b[max],add;	//mang a: chua so tai khoan
	int luachon, k, k2;		//mang b: chua so tien ngau nhien
							//k: la so tai khoan can thuc hien
							//k2: la so tai khoan thu 2 can thuc hien
							//add: la bien cong them so tien vao tai khoan
	

	printf("%d", argc);
	//for (int i = 0; i < argc; i++)
		//printf("%s", argv[i]);
	int arg1 = atoi(argv[1]);
	//int arg2 = atoi(argv[2]);
	//int arg3 = atoi(argv[3]);
	printf("%d", arg1);
	luachon = arg1;
	/*if (luachon == 2)
	{
		k = arg2;
	}
	if (luachon == 3)
	{
		k = arg2;
		add = arg3;
	}*/
	/*if (argc == 4)
	{
		luachon = 4;
		k = arg1;
		k2 = arg2;
		add = arg3;
	}*/
	/*while (chuoisangso(argv[1]) > 7)
		{
			cout << "nhap sai cu phap" << endl;
			cout << "vui long nhap lai lua chon: ";
			return 0;
		}*/
	taotk(a);
	taotienrand(b);
	chonphim(a,b,luachon, k, add, k2);
	return 0;
}
void taotk(int a[])		//ham tao tai khoan tu 1-> 20
{
	for (int i = 1; i <= 20; i++)
	{
		a[i] = i;
	}
}
void taotienrand(int b[])		//ham tao ra so tien ngau nhien cho 20 tai khoan
{
	srand(time(NULL));
	for (int i = 1; i <= 20; i++)
	{
		b[i] = rand() % (1000+1-100) + 100;
	}
}
void tentk(int k)		//danh sach ten khach hang cho tung tai khoan
{
	switch (k)
	{
	case 1: cout << "	TEN KH: DangQuocViet";
		break;
	case 2: cout << "	TEN KH: HoangVanBao";
		break;
	case 3: cout << "	TEN KH: LuuThanhTuan";
		break;
	case 4: cout << "	TEN KH: HoangThiThanhMai";
		break;
	case 5: cout << "	TEN KH: NguyenThiHuynhHoa";
		break;
	case 6: cout << "	TEN KH: CaoThiXuanDung";
		break;
	case 7: cout << "	TEN KH: DoHongViet";
		break;
	case 8: cout << "	TEN KH: PhamThiThuHuong";
		break;
	case 9: cout << "	TEN KH: NguyenThiThuHien";
		break;
	case 10: cout << "	TEN KH: NguyenThiTraMy";
		break;
	case 11: cout << "	TEN KH: TranThiThuy";
		break;
	case 12: cout << "	TEN KH: TranTrongDung";
		break;
	case 13: cout << "	TEN KH: MacVanViet";
		break;
	case 14: cout << "	TEN KH: PhamVanCuong";
		break;
	case 15: cout << "	TEN KH: NguyenVanLong";
		break;
	case 16: cout << "	TEN KH: TranThiMinhChau";
		break;
	case 17: cout << "	TEN KH: BuiPhuongThao";
		break;
	case 18: cout << "	TEN KH: DangHuyenThi";
		break;
	case 19: cout << "	TEN KH: LeKhanhVy";
		break;
	case 20: cout << "	TEN KH: DoHoangMy";
		break;
	
	}
}
void checktk(int &k)
{
	while (k > 20)
	{
		cout << "khong ton tai so tai khoan nay" << endl;
		cout << "vui long nhap tai khoan khac: "; cin >> k;
	}
}
void phim1()		//ham liet ke danh sach cac chuc nang cua tung lua chon
{
	cout << "nhan phim 1: hien danh sach cu phap va chuc nang tuong ung " << endl;
	cout << "nhan phim 2: truy van so tien trong tai khoan" << endl;
	cout << "nhan phim 3: chuyen tien vao tai khoan" << endl;
	cout << "nhan phim 4: chuyen tien qua tai khoan khac" << endl;
	cout << "nhan phim 5: liet ke chi tiet cac tai khoan" << endl;
	cout << "nhan phim 6: cac sinh vien thuc hien chuong trinh" <<  endl;
	cout << "nhan phim 7: thoat chuong trinh" << endl << endl;
}
void phim2(int a[], int b[], int &k)		//ham truy xuat tai khoan
{		
	checktk(k);
	for (int i = 1; i <= 20; i++)
	{
		if (a[i] == k)
		{
			cout << "so tien hien tai cua tai khoan " << a[i] << " la: " << b[i];
			tentk(a[i]);
			cout << endl;
		}
	}		
	cout << endl;
}
void phim3(int a[], int b[], int &k, int &add)		//ham chuyen tien vao tai khoan
{
	int s = 0,tam,tam2;		//tam: de hien thi lai so tai khoan
							//tam2: de hien thi so tien truoc khi duoc cong
							//s: so tien sau khi duoc cong
	checktk(k);
	while (add < 0)
	{
		cout << "so tien khong hop le" << endl;
		cout << "vui long nhap lai so tien: "; cin >> add;
	}
	for (int i = 1; i <= 20; i++)
	{
		if (a[i] == k)
		{
			tam2 = b[i];
			b[i] += add;
			s = b[i];
			tam = a[i];
		}
	}
	cout << "so tien ban dau cua tai khoan " << tam << " la "<<tam2;
	cout << endl;
	cout << "so tien hien tai cua tai khoan " << tam << " la " << s;
	cout << endl << endl;
}
void phim4(int a[], int b[], int &k, int &k2, int &add)			//ham chuyen tien qua tai khoan khac
{
	int s = 0, tam,tam1,sub;		//tam: de hien thi so tai khoan chuyen tien
									//tam1: de hien thi so tai khoan nhan tien
									//s: so tien cua tai khoan sau khi nhan
									//sub: so tien con lai cua tai khoan sau khi chuyen
	checktk(k);
	checktk(k2);
	while (add < 0)
	{
		cout << "so tien khong hop le" << endl;
		cout << "vui long nhap lai so tien: "; cin >> add;
	}
	for (int i = 1; i <= 20; i++)
	{
		if (a[i] == k)
		{
			while (add > b[i])
			{
				cout << "so tien trong tai khoan khong du de thuc hien" << endl;
				cout << "vui long nhap lai so tien: "; cin >> add;
			}
			b[i] -= add;
			sub = b[i];
			tam = a[i];
		}	
		if (a[i] == k2)
		{
			b[i] += add;
			s = b[i];
			tam1 = a[i];
		}
	}
	cout << "so tien hien tai cua tai khoan " << tam << " la " <<sub ;
	cout << endl;
	cout << "so tien hien tai cua tai khoan " << tam1 << " la " << s;
	cout << endl<<endl;
}
void phim5(int a[], int b[])			//ham liet ke chi tiet tat ca cac tai khoan
{
	cout << "					*******************************" << endl;
	cout <<"					" <<"danh sach tat ca cac tai khoan: " << endl;
	cout << "					*******************************" << endl;
	for (int i = 1; i <= 20; i++)
	{
		cout << "			" << "tai khoan " << a[i] << " so tien hien tai: " << b[i];
		tentk(a[i]);
		cout << endl;
	}
	cout << endl;
}
void phim6()		//ham danh sach sinh vien
{
	cout << "	3119410418	" << "Tran Gia Thuan" << endl;
	cout << "	3119410385	" << "Dinh Cong Thanh" << endl;
	cout << "	3119410420	" << "Ho Tan Thuan" << endl;
	cout <<	"	3119410394	" << "Nguyen Tan Thanh" << endl;
	cout << endl;
}
void phim7()		//ham thoat ra khoi chuong chinh
{
	cout << "\n				** nhan enter de thoat chuong trinh **";
	exit(0);
}
void chonphim(int a[],int b[],int &luachon,int &k,int &add,int &k2)
{
	phim1();
	switch (luachon)
	{
		case 1: phim1();
			break;
		case 2: phim2(a, b, k);
			break;
		case 3: phim3(a, b, k, add);
			break;
		case 4: phim4(a, b, k, k2, add);
			break;
		case 5: phim5(a, b);
			break;
		case 6: phim6();
			break;
		case 7: phim7();
			break;
	}
}