/**
题目描述
	多多鸡打算造一本自己的电子字典，里面的所有单词都只由a和b组成。
    每个单词的组成里a的数量不能超过N个且b的数量不能超过M个。
    多多鸡的幸运数字是K，它打算把所有满足条件的单词里的字典序第K小的单词找出来，作为字典的封面。

输入描述:
    共一行，三个整数N, M, K。(0 < N, M < 50, 0 < K < 1,000,000,000,000,000)

输出描述:
    共一行，为字典序第K小的单词。

输入例子1:
    2 1 4

输出例子1:
    ab

例子说明1:
    满足条件的单词里，按照字典序从小到大排列的结果是
        a
        aa
        aab
        ab
        aba
        b
        ba
        baa*/
/*
#include <iostream>
#include <vector>
#include <String.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
const int M = 1000001;
int main() {
    queue<char> q;
    queue<char> temp;
    set<queue <char> > s;
 	int N,M,K,i,j,ra,rb;
    cin>>N>>M>>K;
    for(i=0;i<N;i++){
        q.push('a');
        s.insert(q);
    }
    for(i=0;i<M;i++){
        q.push('b');
        s.insert(q);
    }
    for(i=0;i<M+N;i++){
        if(i<=M-1)
            ra=M-1-i;
            rb=N;
            q.push('b');
            while(j=0;j<ra-1;j++){
                q.push('a')
                s.insert(q);
            }
        
    }

    return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <String.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

set <pair<pair<int,int>,long long> > s;
long long f(int n){
    int i;
    long long sum=1;
    for(i=1;i<=n;i++)
        sum*=i;
    return sum;
}
long long Fac(int m,int n,int k){
    int i,j,k;
    long long sum=0,t;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            k=i<j?i:j;
            t=f(i+j)/f(k);
            s.insert(make_pair(make_pair(i,j),t));
            sum+=t;
            if(sum>=k)
                break;
        }
    }
    return sum;
}
const int M = 1000001;
int main() {
    cout<<Fac(2,1);
}*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;


map <pair<int,int>,long long ,greater<pair<int,int> > > s;
map <pair<int,int>,long long ,greater<pair<int,int> > >::iterator it;
long long f(int n){
    int i;
    long long sum=1;
    for(i=1;i<=n;i++)
        sum*=i;
    return sum;
}
long long Fac(int m,int n){
    if(m==0&&n==0)
        return 0;
    else if(m==0){
        return n+1;
        s.insert(make_pair(make_pair(0,n),n+1));
    }
    else if(n==0){
        return m+1;
        s.insert(make_pair(make_pair(m+1,0),m+1));
    }
    else {
        long long f1,f2;
        f1=Fac(m-1,n);s.insert(make_pair(make_pair(m-1,n),f1));
        f2=Fac(m,n-1);s.insert(make_pair(make_pair(m,n-1),f2));
        return f1+f2+1;
    } 
}
const int M = 1000001;
int main() {
    int m,n,k,i;
    cin>>m>>n>>k;
    long long num=Fac(m,n)-1;
    for(it=s.begin();it!=s.end();it++){
        cout<<"("<<(*it).first.first<<","<<(*it).first.second<<")\t"<<(*it).second<<endl;
    }
    cout<<num<<endl;
    if(k==1){
        cout<<"a"<<endl;
    }
    else{
        while(k>0){
            if(m>0){
                m--;
                num=s[make_pair(m,n)];
                if(num<k){
                    k-=(num+1);
                    m++;
                    n--;
                    cout<<"b";
                }
                else{
                    cout<<"a";
                    k--;
                }
            }
            else{
                for(i=0;i<k;i++){
                    cout<<"b";
                }
                break;
            }
        }
        //cout<<s[make_pair(m,n)];
    }
    /*
    while(k>=0&&m>0&&n>0){
        while(k>=num&&m>0){
            k-=num;
            num=s.find(make_pair(m-1,n));
        }
        m++;
        n--;
    }
    cout<<num<<endl;
    cout<<s.find(make_pair(m,n));*/
}