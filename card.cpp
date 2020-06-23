/**
题目描述
	给你n张卡片，卡片上仅包含大写英文字母，现你可从这n张卡片中选出k张，要求得到尽可能高的分数。
	关于分数的计算方式，在你所选择的k张卡片中，含有相同字母的卡片分数为卡片数乘以相同卡片个数。
	就样例而言，选择九张D和其他任意一张，得到的结果为9*9+1 。
输入描述:
	输入包含两行，第一行含两个整数n，k(0<k<=n<=1,000,000）
	
	第二行为每张卡片上的字母
输出描述:
	输出仅包含一行，输出尽可能高的分数
示例1
	输入
		15 10 
		DZFDFZDFDDDDDDF
	输出
		82
*//*
#include <iostream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int M=1000001;
int split(char* a,char ch){
    int i=0,k=-1;
    while(a[i]){
        if(a[i]!=ch)
            a[++k]=a[i];
        i++;
    }
    a[++k]='\0';
    return i-k;
}
bool compare(int a,int b)
{
      return a>b;
 
}
int main() {
    int n,k;
    while(cin>>n>>k){
        long long i,b[26]={0},count=0,sum=0;
        char a[M];
        scanf("%s",a);
        for(i=0;a[i];){
            b[count++]=split(a,a[i]);
        }
        sort(b,b+count,compare);
        i=0;
        while(k>0){
            if(k<=b[i]){
                sum+=k*k;
                break;
            }
            sum+=b[i]*b[i];
            k-=b[i++];
        }
        cout<<sum<<endl;
    }
    return 0;
}*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 1000001;
int main() {
 	vector<int> b(28);
 	int n,k;
    while(cin>>n>>k){
        long long sum=0,t;
        int i;
        char a[M];
        scanf("%s",a);
        printf("%s",a);
        fill(b.begin(), b.end(), 0);
        for(i=0;a[i];i++){
            b[a[i]-'A']++;
        }
        sort(b.rbegin(), b.rend());
        i=0;
        while(k>0){
        	t=(k<=b[i]?k:b[i]);
        	sum+=t*t;
            if(k<=b[i]){
                break;
            }
            k-=b[i++];
        }
        cout<<sum<<endl;
    }
    return 0;
}