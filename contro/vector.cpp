#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> array;
	array.push_back(9);		//them 9 vao cuoi mang (stack)
	cout << array.back() << endl;	//tra ve phan tu cuoi cua mang (stack)
	array.pop_back();		//xoa 1 phan tu o cuoi mang (stack)
	return 0;
}