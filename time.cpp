/*
题目描述
    题目描述
    小爱有一个奇怪的计数器。在第一个时刻计数器显示数字3，在接下来的每一个时刻，屏幕上的数字都会减1，直到减到1为止。
    接下来，计数器会重置为上一个计数周期初始值的两倍，然后再每一个时刻减1。具体过程如下图所示：
    3 1   6 4    12 10
    2 2   5 5    ...
    1 3   4 6    1  21
          3 7
          2 8
          1 9
    找出规律，并打印出t时刻计数器的值。
输入描述:
    输入为时刻t，一个整形数字。0<t<1e12
输出描述:
    计数器显示的值。
示例1
    输入
        4
    输出
        6
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const long long MAX=100000;
long long sum(long long n){
    return 3*pow(2,n);
}
int main(){
    while(true){
        long long i=0,s=0,n,result;
        cin>>n;
        while(n>s){
            s+=sum(i++);
        }
        cout<<1+s-n;
    }
}