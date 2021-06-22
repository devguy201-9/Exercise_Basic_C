#include<iostream>
using namespace std;
void btvd(int n);
void bt66(int n);
int main()
{
	int n;
	cin >> n;
	btvd(n);
	cout << endl;
	bt66(n);
}
void btvd(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			if ((j >= n - 1 - i) && (j <= n - 1 + i))
				cout << " * ";
			else
				cout << "   ";
		}
		cout << endl;
	}
}
void bt66(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < i)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}

}