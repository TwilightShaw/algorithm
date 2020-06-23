/**
题目描述
	给定一个整数数组,判断其中是否有3个数和为N
输入描述:
	输入为一行
	逗号前为一个整数数组，每个元素间用空格隔开；逗号后为N
输出描述:
	输出bool值
	True表示存在3个和为N的数
	False表示不存在3个和为N的数
*/
/*
#include <iostream>
#include <algorithm>
using namespace std;
const int M=2001;
char* exist(int a[],int len,int N)
{
	int i,j,k;
	for(k=0;k<len;k++){
		if(k==0) i=1;
		else i=0;
		if(k==len-1) j=len-2;
		else j=len-1;
		for(;i<j;){
			if(a[i]+a[j]==N-a[k]) {
			return "True";
		}
			else if(a[i]+a[j]<N-a[k]){
				if(i+1==k) i+=2;
				else i++; 
			}
			else if(a[i]+a[j]>N-a[k]){
				if(j-1==k) j-=2;
				else j--;
			}
		}	
	}
	return "False";
}
int main() {
	int N,temp,a[M],len=0;
	while(cin>>temp) {
		a[len++]=temp;
		if(getchar()==',')
			break;
	}
	cin>>N;
	//cout<<len<<endl;
	sort(a,a+len);
	for(int k=0;k<len;k++){
		cout<<a[k]<<"  "; 
	} 
	cout<<endl<<N<<"\n\n";
	cout<<exist(a,len,N);
	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int M=2001;
char* exist(int a[],int len,int N)
{
	int i,j,k;
	for(k=0;k<len;k++){
		i=0;
		j=len-1;
		while(i<j){
			if(a[i]+a[j]<N-a[k]||i==k) i++;
			else if(a[i]+a[j]>N-a[k]||j==k) j--;
			else if(a[i]+a[j]==N-a[k]) return "True";
		}	
	}
	return "False";
}
int main() {
	int N,a[M],temp,len=0;
	char ch;
	while(cin>>temp) {
		a[len++]=temp;
		if(getchar()==',')
			break;
	}
	cin>>N;
	sort(a,a+len);
	cout<<exist(a,len,N);
	return 0;
}