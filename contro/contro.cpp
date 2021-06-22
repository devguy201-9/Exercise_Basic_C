#include<iostream>
using namespace std;
int main()
{
	int c = 9;
	int* p = &c;
	int array[4] = { 1,4,8,6 };
	int* p1 = array;
	//int* a = nullptr;
	*p = 20;
	cout << c << endl;
	cout << *p << endl;
	cout << *(array + 1) << endl;
	//cap phat dong
	int* p2 = new int;
	*p2 = 30;
	cout << *p2 << endl;
	delete p2;
	p2 = nullptr;
	int max;
	cout << "nhap so max "; cin >> max;
	int* array1 = new int[max];
	delete[] array1;
	return 0;
}