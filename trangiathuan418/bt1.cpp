#include<iostream>
#include<math.h>
using namespace std;
long long tinhtong(int x,int n){
	if(n==0) return x;
	return tinhtong(x,n-1)+pow(-1,n)*pow(x,2*n+1);
}
long long tinhtong1(int x,int n){
	long long s1=0;
	for(int i=0;i<=n;i++)
		s1+=(pow(-1,i)*pow(x,2*i+1));
	return s1;
}
int main()
{
	int x,n;
	cout<<"nhap x: ";cin>>x;
	cout<<"nhap n: ";cin>>n;
	cout<<tinhtong(x,n)<<endl;
	cout<<tinhtong1(x,n);
	return 0;
}
