/*
题目描述
    现给定n个整数，并定义一个非负整数m，且令f(m) = (m%a1)+(m%a2)+...+(m%an)。
    此处的X % Y的结果为X除以Y的余数。
    现请你找出一个m，求出f(m)的最大值。
输入描述:
    输入包含两行，第一行为一正整数n，(1<n<=3000)
    第二行为n个整数a1,a2,...,an ，其中(2<=ai<=10^5)
输出描述:
    输出仅包含一行，输出f(m)的最大值
示例1
    输入
        3
        3 4 6
    输出
        10
    说明
    就样例而言，当m取11时可取得最大值。
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
using namespace std;
const long long MAX=100000;

/*int gcd(int a,int b){
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
int bei(int a,int b){
    return a*b/gcd(a,b);
}*/
int main(){
    int N,t,i,m,sum=0;
    //vector <int> a;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>t;
        sum+=t;
        //a.push_back(t);
    }
    /*sort(a.begin(),a.end(),greater<int>());
    m=a[0];
    for(i=1;i<a.size();i++){
        m=bei(m,a[i]);
    }
    cout<<m<<endl;*/
    cout<<sum-N;
}