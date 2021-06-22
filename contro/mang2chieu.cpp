#include<iostream>
using namespace std;
//CAP PHAT DONG TRONG MANG 2 CHIEU

//tao ham lay phan tu tu mang 2 chieu
int lay(int row, int col, int ptthu)
{
	return (row * ptthu) + col;
}
int main()
{
	int row = 5, col = 10;
	int n = row * col;
	int* array = new int[n];
	array[lay(2, 3, col)] = 12;		//VD
	cout << array[lay(2, 3, col)] << endl;
		//thay vi cap phat con tro vao mang 2 chieu thi ta cap mang 1 chieu r goi ham lay phan tu nhu mang 2 chieu
	return 0;
}