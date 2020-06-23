/*
题目描述
    为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。
    在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。
    牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
输入描述:
    每个输入包含一个测试用例。
    每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
    接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
    接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
    保证不存在两项工作的报酬相同。
输出描述:
    对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。
示例1
    输入
        3 3 
        1 100 
        10 1000 
        1000000000 1001 
        9 10 1000000000
    输出
        100 
        1000 
        1001
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long MAX=100000;
struct work{
    long long Di;
    long long Pi;
};
bool cmp(work a,work b){
    return a.Di<b.Di;
}
int main(){
    int N,M,i,j,left,right,mid;
    vector <work> w;
    vector <long long> Ai;
    long long max;
    cin>>N>>M;
    w.resize(N);
    Ai.resize(M);
    for(i=0;i<N;i++){
        cin>>w[i].Di>>w[i].Pi;
    }
    for(i=0;i<M;i++){
        cin>>Ai[i];
    }
    sort(w.begin(),w.end(),cmp);
    for(i=0;i<M;i++){//排序好后Ai对于Di的折半查找
        left=0;
        right=N-1;
        while(left<=right){//Di[mid]<=Ai[m]<di[mid+1]
            mid=(left+right)/2;
            if(w[mid].Di<=Ai[i]) left=mid+1;
            else right=mid-1;
        
        }
        max=w[0].Pi;
        for(j=1;j<=right;j++)
            if(max<w[j].Pi)
                max=w[j].Pi;
        cout<<max<<endl;;
    }
    return 0;
}