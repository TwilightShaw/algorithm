/**
题目描述
	如果version1 > version2 返回1，如果 version1 < version2 返回-1，不然返回0.
	
	输入的version字符串非空，只包含数字和字符.。.字符不代表通常意义上的小数点，只是用来区分数字序列。
	例如字符串2.5并不代表二点五，只是代表版本是第一级版本号是2，第二级版本号是5.

输入描述:
	两个字符串，用空格分割。
	每个字符串为一个version字符串，非空，只包含数字和字符.
输出描述:
	只能输出1, -1，或0
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int M=2001;
void getVersion(int n[],int &len){
	int temp;
	char ch;
	while(cin>>temp) {
		n[len++]=temp;
		ch=getchar();
		if(ch==' '||ch=='\n'||ch=='\0')
			break;
	}
}
int main() {
	int a[M],b[M],len1=0,len2=0,i=0;
	getVersion(a,len1);
	getVersion(b,len2);
	while(i<len1&&i<len2&&a[i]==b[i++]);
	i--;
	if(len1==len2){
		if(a[i]==b[i]) cout<<0;
		else cout<<(a[i]>b[i]?1:-1);
	}
	else{
		if(a[i]==b[i]) cout<<(len1-i>len2-i?1:-1);
		else cout<<(a[i]>b[i]?1:-1);
	}
	return 0;
}