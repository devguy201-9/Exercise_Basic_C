#include<iostream>
#define maxn 1000001
using namespace std;
void ghiketqua(int so)
{
    FILE* f;
    int d = 0;
    fopen_s(&f, "BT7.OUT", "wt");
    fprintf(f, "%d\n", so);
    fclose(f);
}
void docfile(int a[], int& n)
{
    FILE* f;
    fopen_s(&f, "BT7.INP", "rt");
    if (!f)
    {
        cout << "khong mo duoc file f";
        return;
    }
    fscanf_s(f, "%d", &n);
    for(int i=0;i<n;i++)
        fscanf_s(f, "%d", &a[i]);
    fclose(f);
}
int xuly(int a[], int n,bool check[])
{
    int d = 0;
    for (int i = 0; i <= maxn; i++)
        check[i] = true;
    for (int i = 0; i < n; i++)
    {
        if (check[a[i]] == true)
        {
            d++;
            check[a[i]] = false;
        }
    }
    return d;
}
int main() {
    int n;
    int* a;
    bool* check;
    a = new int[maxn];
    check = new bool[maxn];
    docfile(a, n);
    ghiketqua(xuly(a, n, check));
    return 0;
}