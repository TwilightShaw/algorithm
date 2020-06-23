/*
题目描述
    牛牛和妞妞去海边捡了一大袋美丽的贝壳，千辛万苦地运回家后，牛牛和妞妞打算分掉这些贝壳。
    牛牛提出，他和妞妞轮流从还没有分配的贝壳中取一定数量的贝壳，直到贝壳分完为止。
    分配规则是牛牛每次取剩余贝壳的1/10（向下取整），妞妞每次固定取m个贝壳，妞妞先取。
    妞妞想要得到不少于一半的贝壳，又不想太过分，那么她一次最少取多少个贝壳才能得到不少于一半的贝壳呢？
输入描述:
    一个正整数n，表示贝壳的总数量，1<=n<=1000000000000000000。
输出描述:
    一个正整数m，表示妞妞一次最少取的贝壳数量。
示例1
    输入
        10
    输出
        1
示例2
    输入
        70
    输出
        3
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const long long MAX=100000;
int enough(long long n,long long mid){
    long long sum=0;
    while(n>=mid){
            n-=mid;
            sum+=mid;
            n-=floor(n/10);
            if(sum>=2/n) return  1;
        }
    sum+=mid-n;
    if(sum>=2/n) return  1;
    return 0;
}
int main(){
    long long left=1,right,mid,n;
    int f1,f2;
    cin>>n;
    right=n;
    while(left<=right){
        mid=(left+right)/2;
        f1=enough(n,mid);
        if(!f1)
            left=mid+1;
        else
            right=mid-1;
    }
    cout<<right<<endl;

    return 0;
}