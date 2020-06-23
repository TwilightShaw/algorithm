/**
 链接：https://www.nowcoder.com/questionTerminal/8314cb12d35b4e2a920b3bd0474fe1f2
来源：牛客网

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
// 栈 
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
	int m,n,k,i,j,num=0;
	cin>>m>>n>>k;
	int stack1[M],stack2[M],top=-1;
	int array[M+2][M+2];
	memset(array,0,sizeof(array));
	//int **array;
	//array = new int*[m];    //int*[m]表示一个有m个元素的指针数组
	//for (int i = 0; i < m+2; ++i){
	//    array[i] = new int[n+2];
	//}
	for(i=0; i<m+2; i++){
		array[i][n+1]=1;
		array[i][0]=1;
	}
	for(i=0; i<n+2; i++){
		array[0][i]=1;
		array[m+1][i]=1;
	}
	stack1[++top]=1;
	stack2[top]=1;
	array[1][1]=1;
	while(top!=-1) {
		num++;
		i=stack1[top];
		j=stack2[top--];
		//cout<<"("<<i<<","<<j<<")"<<array[i][j]<<endl;
		// 右
		if(over(array,i+1,j,k)) {
			//array[i+1][j]=1;
			stack1[++top]=i+1;
			stack2[top]=j;
		}
		// 上
		if(over(array,i,j+1,k)) {
			//array[i][j+1]=1;
			stack1[++top]=i;
			stack2[top]=j+1;
		}
		//cout<<"\t\t"<<num<<endl;
	}
	cout<<num;
	return 0;
}
*/ 

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
int count(int a[][M+2],int i,int j,int k) {
	// 访问 
	if(a[i][j]) return 0;
	// 不满足条件 
	if(Fac(i-1)+Fac(j-1)>k) return 0; 
	else{
		a[i][j]=1;
		return(1+count(a,i+1,j,k)+count(a,i,j+1,k));
	}
}
int main() {
	int m,n,k,i;
	cin>>m>>n>>k;
	int array[M+2][M+2];
	memset(array,0,sizeof(array));
	for(i=0; i<m+2; i++){
		array[i][n+1]=1;
		array[i][0]=1;
	}
	for(i=0; i<n+2; i++){
		array[0][i]=1;
		array[m+1][i]=1;
	}
	cout<<count(array,1,1,k);
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