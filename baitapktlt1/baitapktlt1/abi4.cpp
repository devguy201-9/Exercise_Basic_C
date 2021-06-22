#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int checktrung(int a[], int n, int k);
string chuoikytu ="abcdefghijklmnopqrstuvwxyz";
void docfile(const char filename[], int& n)
{
    FILE* f;
    fopen_s(&f, filename, "rt");
    if (!f)
    {
        cout << "khong mo duoc file f";
        return;
    }
    fscanf_s(f, "%d", &n);
    fclose(f);
}
void ghifile(int n)
{
    FILE* g;
    int a[300];
    fopen_s(&g, "sokhac.txt", "wt");
    if (!g)
    {
        cout << "khong mo duoc file g";
        return;
    }
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 100;
        a[i] = temp;
        if (checktrung(a, i, temp))
        {
            fprintf(g, "%d ", temp);
        }
        else
            i--;
    }
    fclose(g);
}
int checktrung(int a[],int n, int k)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (k == a[i])
            flag = 1;
    if (flag == 0) return 1;
    return 0;
}
void ghifile2(int n)
{
    char temp;
    FILE* g;
    fopen_s(&g,"kytu.txt", "wt");
    if (!g)
    {
        cout << "khong mo duoc file g";
        return;
    }
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        temp = chuoikytu[rand() % chuoikytu.length()];
        fprintf(g,"%c ",temp);
    }
    fclose(g);
}
void ghifile3(int n)
{
    char temp;
    FILE* g;
    fopen_s(&g, "chuoi.txt", "wt");
    if (!g)
    {
        cout << "khong mo duoc file g";
        return;
    }
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int temp3 = rand() % 15 + 1;
        for (int j = 0; j<temp3; j++)
        {
            int temp2 = rand() % 7 + 1;
            for (int k = 0; k < temp2; k++)
            {
                temp = chuoikytu[rand() % chuoikytu.length()];
                fprintf(g, "%c", temp);
            }
            fprintf(g, " ");
        }
        fprintf(g,"\n");
    }
    fclose(g);
}
int main()
{
    int n,m,k;
    docfile("sokhac.inp", n);
    ghifile(n);
    docfile("kytu.inp", m);
    ghifile2(m);
    docfile("chuoi.inp", k);
    ghifile3(k);
    return 0;
}