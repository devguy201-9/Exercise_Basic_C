#include<iostream>
#include<string.h>
#define maxn 100
using namespace std;
void ghiketqua(int a[],int n)
{
    FILE* f=fopen("BT5.OUT", "wt");
    for(int i=0;i<n;i++)
        fprintf(f, "%d",a[i]);
    fclose(f);
}
void docfile(char s[],char s1[])
{
    FILE* f=fopen("BT5.INP", "rt");
    if (!f)
    {
        cout << "khong mo duoc file f";
        return;
    }
    fgets(s, 100, f);
    s[strlen(s) - 1] = '\0';
    fgets(s1, 100, f);
    fclose(f);
}
int docso(char kitu)
{
    int so;
    switch (kitu)
    {
    case '0': so = 0;
        break;
    case '1': so = 1;
        break;
    case '2': so = 2;
        break;
    case '3': so = 3;
        break;
    case '4': so = 4;
        break;
    case '5': so = 5;
        break;
    case '6': so = 6;
        break;
    case '7': so = 7;
        break;
    case '8': so = 8;
        break;
    case '9': so = 9;
        break;
    }
    return so;
}
void layso(int b[],int c[], char s[], char s1[],int &n)
{
    char temp[2];
    if (strlen(s) < strlen(s1))
    {
        n = strlen(s1) - strlen(s);
        for (int i = 0; i <= n; i++)
            b[i] = 0;
        for (int i = 0; i < strlen(s); i++)
            b[n++] = docso(s[i]);
        for(int i=0;i< strlen(s1);i++)
            c[i] = docso(s1[i]);
    }
    else if(strlen(s) > strlen(s1))
    {
        n = strlen(s) - strlen(s1);
        for (int i = 0; i <= n; i++)
            b[i] = 0;
        for (int i = 0; i < strlen(s1); i++)
            b[n++] = docso(s1[i]);
        for (int i = 0; i < strlen(s); i++)
            c[i] = docso(s[i]);
    }
    else
    {
        n = strlen(s);
        for (int i = 0; i <n ; i++)
            b[i] = docso(s[i]);
        for (int i = 0; i < n; i++)
            c[i] = docso(s1[i]);
    }
}
void xuly(int a[], int b[], int c[], int n)
{
    int temp, tam = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        temp = b[i] + c[i]+tam;
        if (temp > 9)
        {
            tam = temp;
            temp = temp % 10;
            tam /= 10;
        }
        else
            tam = 0;
        a[i] = temp;
    }
}
int main() {
    int n;
    int a[maxn],b[maxn],c[maxn];
    char s[maxn],s1[maxn];
    docfile(s,s1);
    layso(b, c, s, s1, n);
    xuly(a, b, c, n);
    ghiketqua(a, n);
    return 0;
}
