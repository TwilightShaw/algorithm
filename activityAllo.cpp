/*
题目描述
    活动安排
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long MAX=100000;

bool cmp(const pair<int,int> a, const pair<int ,int> b) {
    return a.second<b.second;
}
int main(){
    int i,count=0;
    vector <pair<int,int> > a;
    vector <pair<int,int> > b;
    a.push_back(make_pair(0,6));
    a.push_back(make_pair(1,4));
    a.push_back(make_pair(2,13));
    a.push_back(make_pair(3,5));
    a.push_back(make_pair(3,8));
    a.push_back(make_pair(5,7));
    a.push_back(make_pair(5,9));
    a.push_back(make_pair(6,10));
    a.push_back(make_pair(8,11));
    a.push_back(make_pair(8,12));
    a.push_back(make_pair(12,14));
    sort(a.begin(),a.end(),cmp);
    /*for(i=0;i<a.size();i++)
        cout<<a[i].first<<"\t"<<a[i].second<<endl;*/
    //排序后加入
    b.push_back(a[0]);
    for(i=1;i<a.size();i++){
        if(a[i].first>=b.back().second)
            b.push_back(a[i]);
    }
    for(i=0;i<b.size();i++)
        cout<<b[i].first<<"\t"<<b[i].second<<endl;
    return 0;
}