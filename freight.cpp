/*
题目描述
    有重量分别为3，5，7公斤的三种货物，和一个载重量为X公斤的箱子（不考虑体积等其它因素，只计算重量）
    需要向箱子内装满X公斤的货物，要求使用的货物个数尽可能少（三种货物数量无限）
输入描述:
    载重量X(1 <= X <= 10000)，一个整数。
输出描述:
    如果无法装满，输出 -1。
    如果可以装满，输出使用货物的总个数。
    输入
        4
    输出
        -1
    说明
        无法装满
    输入
        8
    输出
        2
    说明
        使用1个5公斤，1个3公斤货物
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    //3 5 6 7 8 9 10 11 12 13 14
    int x;
    cin>>x;
    if(x==1||x==2||x==4) cout<<-1;
    else{
        
    }
   return 0;
}