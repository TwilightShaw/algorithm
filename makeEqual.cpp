/*
题目描述
    题目给定a1,a2...an，这样一个长度为n的序列，现在你可以给其中一些元素加上一个值x（只能加一次），
    然后可以给另外一些值减上一个值x（只能减一次），剩下的元素不能再进行操作。问最后有没有可能找到一个值x使所有元素的值相等。
输入描述:
    输入第一行为一个整数k，代表有k个序列(k<100)，接下来有2*k行:
    偶数行为一个整数n，代表给定序列的长度(1<=n<=100,000)
    奇数行包含n个元素，a1,a2...an，代表序列中的元素(0<=ai<=100,000)
输出描述:
    输出k行，每行一个YES或者NO
    输入
        1
        5
        1 3 3 2 1
    输出
        YES
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const long long MAX=100000;

int main(){
    int k,n,i,num;
    set <int> a;
    set <int>::iterator i1,i2,i3;  
    cin>>k;
    for(i=0;i<k;i++){
        cin>>n;
        while(n--)
        {
            cin>>num;
            a.insert(num);
        }
        if(a.size()>3) 
            cout<<"NO"<<endl;
        else{
            if(a.size()==3) 
            {
                i1 = i2 = a.begin();
                i2++;
                i3 = a.end();
                i3--;
                if(*(i1)+*(i3)==2*(*i2))
                    cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else cout<<"YES"<<endl;
        }
        a.clear();
    }
    return 0;
}