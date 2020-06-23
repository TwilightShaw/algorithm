/**
题目描述
	输入N，求N！末尾的第一个非零数字。如6 ! = 720，因此6的阶乘末尾的非零位是2。
输入描述:
	仅一行，包含一个整数N（0<=N<=10,000,000）
输出描述:
	仅一行，包含一个整数，表示最右边的非零的值
示例
	输入
		6
	输出
		2
	说明
		6 ! = 720
*/
/*
1!=1	2!=2	3!=6	4!=24->4	5!=120->2	6!=720->2	7!=5040->4	8!=40320->2
9!=32680->8	10!=326880->8	11!=39916800->8	12!=479,001,600->6
*/
#include <iostream>
#include <string.h>
using namespace std;
const int M=101;
long fac(long n){
	if(n==1) return 1;
	else if(n==2) return 2;
	else if(n==3) return 6;
	else{
		long t=fac(n-1)*n,t2=0;
		while(t&&!t2){
			t2=t%10;
			t/=10;
		}
		return t2;
	}
}
int main() {
	long n;
	cin>>n;
	cout<<fac(n);
	return 0;
} 