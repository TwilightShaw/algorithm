/*
题目描述
    背包问题
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long MAX=100000;
struct bagpag{
    int value;
    int weight;
    double per;
};
bool cmp(bagpag a,bagpag b) {
    return a.per>b.per;
}
int main(){
    /*
    0-1背包
    给定n种物品和一个背包。物品i的重量是Wi，其价值为Vi，背包的容量为C。
    应如何选择装入背包的物品，使得装入背包中物品的总价值最大?

    背包 
    物品数量足够
    */

    //首先计算每种物品单位重量的价值Vi/Wi
    //自己写
    int v,w,count=0;
    vector <bagpag> b(MAX);
    while(cin>>v>>w){
        b[count].value=v;
        b[count].weight=w;
        b[count++].per=1.0*v/w;
    }
    sort(b.begin(),b.begin()+count,cmp);
    
    return 0;
}