#include<iostream>
#define maxn 1000001
using namespace std;
		//O(n^2)

int xuly(int a[], int n)
{
	int maxs = -100000;
	int s;
	for (int i = 0; i < n - 1; i++)
	{
		s = a[i];
		for (int j = i + 1; j < n; j++)
		{
			s += a[j];
			if (s > maxs)
				maxs = s;
		}
	}
	return maxs;
}
void docfile(int a[], int& n)
{
	FILE* f;
	fopen_s(&f, "VD1.INP", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fscanf_s(f, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf_s(f, "%d", &a[i]);
	fclose(f);
}
int main()
{
	int n;
	int* a;
	a = new int[maxn];
	docfile(a, n);
	cout << "output=" << xuly(a, n) << endl;
	return 0;
}