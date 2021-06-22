#include<iostream>
#include<fstream>
using namespace std;
void showInfo(int* a, size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	//fstream fp("1323.txt",ios::in);  chi ro muc dich mo file
	fstream fp("1323.txt");		//mo file fstream fp("C:/1323.txt");	
	//fp.open("1323.txt")		c2
	size_t n;
	int* arr;
	fp >> n;
	arr = new int[n];
	//while(!fp.eof()) doc den khi het moi dung lai
	for (size_t i = 0; i < n; i++)
	{
		fp >> arr[i];
	}
	showInfo(arr, n);
	fp.close();
	return 0;
}