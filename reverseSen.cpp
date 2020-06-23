#include <iostream>
#include <malloc.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
int main(){
    /*
    string str;
    int i;
    stack <string > s;
    while(getline(cin, str,' ')){
        cout<<" === === ==="<<endl;
        cout<<str<<endl;
        if (str.find("\n")!= str.npos||str.empty()) 
            break;
        s.push(str);
        cout<<" === === ==="<<endl;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }*/
    /*int i,j;
    vector<vector<char> >v;
    vector<char> word;
    char ch;
    while((ch=getchar())!='\n'){
        if(ch!=' '){
            word.push_back(ch);
        }
        else {
            if(!word.empty()){
                v.push_back(word);
                word.clear();
            }
        }
    }
    if(!word.empty()){
        v.push_back(word);
        word.clear();
    }
    for(i=v.size()-1;i>=0;i--){
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j];
        cout<<" ";
    }*/
     int i,j;
    vector<string >v;
    vector<char> word;
    char ch;
    while((ch=getchar())!='\n'){
        if(ch!=' '){
            word.push_back(ch);
        }
        else {
            if(!word.empty()){
                v.push_back(word);
                word.clear();
            }
        }
    }
    if(!word.empty()){
        v.push_back(word);
        word.clear();
    }
    for(i=v.size()-1;i>=0;i--){
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j];
        cout<<" ";
    }
    return 0;
}