/*
题目描述
    给定两个-100到100的整数x和y,对x只能进行加1，减1，乘2操作，
    问最少对x进行几次操作能得到y？
    例如：
    a=3,b=11: 可以通过3*2*2-1，3次操作得到11；
    a=5,b=8：可以通过(5-1)*2，2次操作得到8；
输入描述:
    输入以英文逗号分隔的两个数字，数字均在32位整数范围内
输出描述:
    操作次数
示例1
    输入
        3,11
    输出
        3
*/
/* 
     -10 -> -20  归成  10 -> 20
    - 20 -> -10  归成  “直接加”

    - 20 -> 10   归成   1-> 10         +21
     -10 -> 20   归成   1-> 20         +11

     20 -> -10   归成   1-> 10         +21
     10 -> -20   归成   1-> 20         +11

     20 -> 10   归成   “直接减”
     10 -> 20   归成   10 -> 20
*//*
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <math.h>
using namespace std;
const long long MAX=1000;
#define MIN(a,b) ((a)<(b)?(a):(b))
int func(int x,int y){
    if(x==y) return 0;
    else if (x<0||x>100) return 500;
    else if(x+1==y||x-1==y||x*2==y) return 1;
    else  return 1+MIN(func(x*2,y),MIN(func(x+1,y),func(x-1,y)));
}
int main(){
    int x,y,N;
    cin>>x;
    getchar();
    cin>>y;
    if(x==0&&y==0)  //00
        N=0;
    else if(y==0&&x!=0) //+0 -0
        N=fabs(x);
    else if(x>=0&&y<0||x<=0&&y>0) //+- -+ 0+ 0-
        N=fabs(x)+1+func(1,fabs(y));
    else {  //++ --
        if(x<=y&&y<=0||x>=y&&y>=0)
            N=fabs(x-y);
        else 
            N=func(fabs(x),fabs(y));
    }
    cout<<N;
}*/
//别人 bfs
/*暴力
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <math.h>
using namespace std;
int x, y;
queue<int> qu;
int solve() {
    if(x == y) return 0;
    qu.push(x);
    int cnt = 0, size = 1;
    while(!qu.empty()) {
        cnt++;
        int size = qu.size();
        for(int i = 0; i < size; i++) {
            int t = qu.front(); qu.pop();
            if(t + 1 == y || t - 1 == y || t*2 == y) return cnt;
            if(t + 1 <= 100) qu.push(t + 1);
            if(t - 1 >= -100) qu.push(t - 1);
            if(2 * t <= 200 && 2 * t >= -200) qu.push(2*t);
        }
    }
}
 
int main() {
    scanf("%d,%d", &x, &y);
    cout<<solve()<<endl;
}
*/
/* 擦除
#include <iostream>
#include <istream>
#include <vector>
using namespace std;
 
vector<int> record;
long ans = 0;
void bfs(int target){
    ans++;
    int num = record.size();
    for(int i = 0; i<num; i++){
        if(record[i]+1 == target || record[i]-1 == target || record[i]*2 == target){
            return;
        }
        record.push_back(record[i]+1);
        record.push_back(record[i]-1);
        record.push_back(record[i]*2);
    }  
    record.erase(record.begin(), record.begin()+num-1);
    bfs(target);
}
int main(){
    int x, y;
    char ch;
    cin >> x;
    record.push_back(x);
    cin >> ch;
    cin >> y;
     
    if(x == y){
        cout << 0;
        return 0;
    }
     
    bfs(y); 
    cout << ans;
    return 0;
}*/
/* map防重复

#include <bits/stdc++.h>
using namespace std;
int bfs(int x,int y,map<int,int> &m){
    queue<int> que;
    int sum=0;
    que.push(x);
    m.insert(make_pair(x,0));
    while(!que.empty()){
        int temp=que.front();
        que.pop();
        if(temp>100||temp<-100)
            continue;
        sum=m[temp];
        if(temp==y){
            break;
        }
        if(m.find(temp+1)==m.end()){
            que.push(temp+1);
            m.insert(make_pair(temp+1,sum+1));
        }
        if(m.find(temp-1)==m.end()){
            que.push(temp-1);
            m.insert(make_pair(temp-1,sum+1));
        }
        if(m.find(temp*2)==m.end()){
            que.push(temp*2);
            m.insert(make_pair(temp*2,sum+1));
        }
    }
    return sum;
}
int main(){
    int x,y;
    scanf("%d,%d",&x,&y);
    map<int,int> m;
    cout<<bfs(x,y,m);
    return 0;
}
*/