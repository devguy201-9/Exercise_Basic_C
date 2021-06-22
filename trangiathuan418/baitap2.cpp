#include <iostream>
#include <math.h>
using namespace std;
void cau_a(int *&a, int &n);
void cau_b(int *a, int n);
void cau_c(int *a,int n);
int main()
{
    int *a, n;
    cau_a(a, n);
    cau_b(a, n);
    cau_c(a,n);
    return 0;
}
void cau_a(int *&a, int &n)
{
    FILE *f = fopen("data.in", "rt");
    fscanf(f, "%d", &n);
    a = new int[n * n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(f, "%d", &*(a + n * i + j));
    fclose(f);
}
void cau_b(int *a, int n)
{
    FILE *f = fopen("ketqua1.out", "wt");
    int dem = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (*(a + n * j + i) == 1)
                dem++;
    fprintf(f, "%d\n", dem);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (*(a + n * j + i) == 1)
                fprintf(f, "(%d, %d)\n", i, j);
    fclose(f);
}

void cau_c(int *a, int n)
{
    int *b = new int[n * n];
    //khoi tao mang b chua toan gia tri 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            *(b + n * i + j) = 0;
    //tam giac duoi
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        //  if (*(a + n * i + j) == 1)
        {
            for (int k = 1; k < n; k++)
                if (*(a + n * k + j) == *(a + n * k + i) && *(a + n * k + j) == 1)
                    *(b + n * i + j) = 1;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            *(b + n * i + j) = *(b + n * j + i);

    //ghi file
    FILE *f = fopen("ketqua2.out", "wt");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fprintf(f, "%d  ", *(b + n * i + j));
        fprintf(f, "\n");
    }
    fclose(f);
}
