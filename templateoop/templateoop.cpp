#include<iostream>
using namespace std;
//dung ham showinfo cho bat ki kieu du lieu nao
template<class T>void showinfo(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
}
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,6 };
//	showinfo<int>(a, sizeof(a) / sizeof(int));
//	return 0;
//}