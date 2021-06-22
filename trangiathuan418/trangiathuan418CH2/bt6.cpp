#include<iostream>
#define maxn 1000001
using namespace std;
void ghiketqua(int so)
{
    FILE* f=fopen("BT6.OUT", "wt");
    fprintf(f, "%d\n", so);
    fclose(f);
}

void docfile(int a[],int& n,int &x,int &y)
{
    FILE* f=fopen("BT6.INP", "rt");
    n = 0;
    if (!f)
    {
        cout << "khong mo duoc file f";
        return;
    }
    fscanf(f, "%d %d", &x,&y);
    while (!feof(f))
    {
        fscanf(f, "%d", &a[n++]);
    }
    fclose(f);
}
void hoanvi(int& a, int& b)
{
    int temp = a; a = b; b = temp;
}
void quicksort(int a[], int l, int r)
{
    int x = a[(l + r) / 2];
    int i = l;
    int j = r;
    do
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
            hoanvi(a[i++], a[j--]);
    } while (i<j);
    if (l < j) quicksort(a, l, j);
    if (i < r) quicksort(a, i, r);
}
int binayrysearch(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    int mid;
    do
    {
        mid = (l + r) / 2;
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    } while (l<=r);
    return -1;
}
int xuly(int a[], int n, int x, int y)
{
    int temp,d = 0;
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < x || a[i] < y)
        {
            temp = x - a[i];
            if (binayrysearch(a, n, temp) != -1)
                d++;
        }
        else
            break;
    }
    return d;
}
int main() {
    int n,x,y;
    int *a;
    a = new int[maxn];
    docfile(a, n, x, y);
    ghiketqua(xuly(a, n, x, y));
    delete a;
    return 0;
}
