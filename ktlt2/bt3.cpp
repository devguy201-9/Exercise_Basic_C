                            //O(n^3)


#include<iostream>
#define maxn 30001
using namespace std;
void ghiketqua(int so)
{
    FILE* f;
    int d = 0;
    fopen_s(&f, "BT3.OUT", "wt");
    fprintf(f, "%d\n", so);
    fclose(f);
}

void docfile(int a[], int& n)
{
    FILE* f;
    fopen_s(&f, "BT3.INP", "rt");
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
    } while (i < j);
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
    } while (l <= r);
    return -1;
}
int xuly(int a[], int n)
{
    int temp, d = 0;
    int tam,tam1;
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {       //2 9 5 7 10
            //2 5 7 9 10
            //9 5 7     5 9 7
        tam = a[i] * 3;     //21      2 9 10  
        for (int j = 0; j < n; j++)
        {
            if (a[j] != a[i])
            {
                tam1 = tam - a[j];      //21-2=19
                for (int k = 0; k < n; k++)
                {
                    if (a[k] < tam1 && a[k] != a[i] && a[k] != a[j])
                    {
                        temp = tam1 - a[k];
                        if(binayrysearch(a, n, temp) != -1)
                        {
                            if (temp != a[i] && temp != a[j] && temp!=a[k])
                            {

                                //cout << a[i] << " la " << a[j] << " " << a[k] << " " << temp << endl;
                                d++;
                            }
                        }
                    }
                }
            }
        }
    }
    return d;
}
int main() {
    int n;
    int* a;
    a = new int[maxn];
    docfile(a, n);
    cout << xuly(a, n);
    return 0;
}