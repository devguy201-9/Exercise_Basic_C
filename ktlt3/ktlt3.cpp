#include<iostream>
using namespace std;
int ucln(int a, int b)
{
	if (!a || !b)
		return a + b;
    else if (a > b)
        return ucln(a % b, b);
    else
        return ucln(a, b % a);
}
int main()
{
    int a, b;
    cout << "nhap so a,b: "; cin >> a;
    cin >> b;
    cout << ucln(a, b);
    return 0;
}