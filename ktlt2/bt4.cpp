#include<iostream>
#include<math.h>
#define maxn 1000001
using namespace std;
void ghiketqua(int so)
{
    FILE* f;
    int d = 0;
    fopen_s(&f, "BT4.OUT", "wt");
    fprintf(f, "%d\n", so);
    fclose(f);
}
void docfile(int &n)
{
	FILE* f;
	fopen_s(&f, "BT4.INP", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fscanf_s(f, "%d", &n);
	fclose(f);
}

int check(int n) {
    int sum = 1;
    int k = sqrt(n);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0)
            sum += i + n / i;
    }
    return sum;
}
int demcaphh(int n)
{
    int temp, temp2, flag, j = 0;
    int a[100];
    int dem = 0;
    for (int i = 1; i < n; i++)
    {
        temp = check(i);//220 -> 284                
        temp2 = check(temp);//284 -> 220            
        if (temp2 == i && temp != temp2)
        {
            flag = 0;
            a[j++] = temp;
            for (int k = 0; k < j; k++)
                if (i == a[k])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0 && temp <= n)
                dem++;
        }
    }
    return dem;
}
int main() {
    int n;
    docfile(n);
    ghiketqua(demcaphh(n));
    return 0;
}