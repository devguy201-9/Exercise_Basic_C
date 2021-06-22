#include<iostream>
using namespace std;
string write(int num);
string convert(int x, int b) {
    if (x == 0) { return ""; }
    return convert(x / b, b) + write(x % b);
}
string write(int num) {
    if (num == 0) { return "0"; };
    if (num == 1) { return "1"; };
    if (num == 2) { return "2"; };
    if (num == 3) { return "3"; };
    if (num == 4) { return "4"; };
    if (num == 5) { return "5"; };
    if (num == 6) { return "6"; };
    if (num == 7) { return "7"; };
    if (num == 8) { return "8"; };
    if (num == 9) { return "9"; };
    if (num == 10) { return "A"; };
    if (num == 11) { return "B"; };
    if (num == 12) { return "C"; };
    if (num == 13) { return "D"; };
    if (num == 14) { return "E"; };
    if (num == 15) { return "F"; };
}
int main()
{
    int a, b;
    cout << "nhap a: "; cin >> a;
    cout << "nhap b: "; cin >> b;
    cout << "sau chuyen doi la: " << convert(a, b);
    return 0;
}