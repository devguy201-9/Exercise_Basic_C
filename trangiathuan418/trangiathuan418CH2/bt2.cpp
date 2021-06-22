#include<iostream>
#include<math.h>
#define maxn 1000000001
#define maxnt 51000000
using namespace std;
								//bai nay chay khoang 35s
void ghiketqua(int so,int so2)
{
	FILE* f=fopen("BT2.OUT", "wt");
    fprintf(f, "%d\n", so);
    fprintf(f, "%d\n", so2);
	fclose(f);
}
int main() {
    bool *check;
    int dem = 0;
    int* a;
    a = new int[maxnt];
    check = new bool[maxn];
    int k = sqrt(maxn);
    for (int i = 2; i <= maxn; i++) {
        check[i] = true;
    }
    for (int i = 2; i <= k; i++) {
        if (check[i] == true) {
            for (int j = pow(i,2); j <= maxn; j += i) {
                check[j] = false;
            }
        }
    }
    for (int i = 2; i <= maxn; i++)
        if (check[i] == true)
        {
            a[dem++] = i;
        }
    int temp = a[0];
    int dem2 = 0;
    for (int i = 1; i < dem - 1; i++)
    {
        if ((a[i] * 2) == (temp + a[i + 1]))
            dem2++;
        temp = a[i];
    }
    ghiketqua(dem,dem2);
    delete check;
    delete a;
    return 0;
}
