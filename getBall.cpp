/**
 链接：https://www.nowcoder.com/questionTerminal/8314cb12d35b4e2a920b3bd0474fe1f2
来源：牛客网

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

#include <iostream>
#include <string.h>
using namespace std;
const int M=101;
int Fac(int i){
	int sum=0;
	if(i==1)	return 1;
	else if(i==2) return 2;
	else {
		while(i>2) {
			sum++;
			i=(i+1)/2;
		}
		return sum+1;
	}
}
int main() {
	int N,n,i;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>n;
		cout<<Fac(n)<<endl;
	}
	return 0;
} 
/* 
#include <iostream>
#include <string.h>
using namespace std;
const int M=101;
int Fac(int i){
	int sum=0;
	while(i) {
		sum+=i%10;
		i/=10;
	}
	return sum;
}
int over(int a[][M+2],int i,int j,int k) {
	if(a[i][j]) return 0;
	if(Fac(i-1)>k) return 0;
	if(Fac(i-1)+Fac(j-1)>k) return 0;
	a[i][j]=1;
	return 1;
}
int main() {
	int m,n,k,i,j,sum,num=0;
	cin>>m>>n>>k;
	for(i=0;i<m;i++){
		sum=Fac(i);
		if(sum>k) break;
		for(j=0;j<m&&sum<=k;j++){
			sum+=Fac(j);
		} 
		num+=j-1;
	}
	cout<<num;
	return 0;
}*/ 