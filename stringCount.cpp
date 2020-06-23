/**
题目描述
	对字符串进行RLE压缩，将相邻的相同字符，用计数值和字符值来代替。例如：aaabccccccddeee，则可用3a1b6c2d3e来代替。

输入描述:
    输入为a-z,A-Z的字符串，且字符串不为空，如aaabccccccddeee
    输出描述:
压缩后的字符串，如3a1b6c2d3e
    输入
        aaabccccccdd
    输出
        3a1b6c2d
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int M=100000;
int split(char* a,char ch){
    int i=0,k=-1;
    while(a[i]){
        if(a[i]!=ch)
            a[++k]=a[i];
        i++;
    }
    a[++k]='\0';
    return i-k;
}
int main() {
    int count=0,i;
    vector <pair<int,char> > b(52);
    char a[M],ch;
    scanf("%s",a);
    for(i=0;a[i];){
        ch=a[i];
        b.push_back(make_pair(split(a,a[i]),ch));
        count++;
    }
    
    /*vector<pair<int,char> > ::iterator iter;
    for(iter=b.begin();iter!=b.end();iter++){
        cout<<(*iter).first<<(*iter).second;
    }*/
    for(i=b.size()-count;i!=b.size();i++)
        cout<<b[i].first<<b[i].second;
    return 0;
}