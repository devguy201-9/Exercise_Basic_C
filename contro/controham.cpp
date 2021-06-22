#include<iostream>
#include<functional>
using namespace std;
//khai bao con tro ham
//	KIEU (* TEN)(int ,double,...);
int tam(int a)
{
	return a;
}
int main()
{
	int a = 2;
	int (*ten)(int) = tam;
	cout << ten(a)<<endl;
	//dung c++ 11 (thu vien funtional)
	function<int(int)>ten1 = tam;
	cout << ten1(5);
	return 0;
}