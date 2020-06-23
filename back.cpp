#include <iostream>
#include <malloc.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    string s;
    int i,k;
    cin>>s;
    for(i=0,k=-1;i<s.length();i++){
        if(s[i]!='<'){
            s[++k]=s[i];
        }
        else{
            s[k]=s[++i];
        }
    }
    s.erase(k+1, s.length());
    cout<<s;
    return 0;
}