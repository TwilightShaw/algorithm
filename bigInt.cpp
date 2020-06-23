#include <iostream>
#include <malloc.h>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    char *s1,*s2,*s3;
    int i,j;
    vector <int> v1,v2,v3;
    vector <int>::iterator it;

    s1=(char *)malloc(sizeof(char)*100);
    s2=(char *)malloc(sizeof(char)*100);
    scanf("%s %s",s1,s2);
    
    for(i=strlen(s1)-1;i>=0;i--)
        v1.push_back(s1[i]-'0');
    for(i=strlen(s2)-1;i>=0;i--)
        v2.push_back(s2[i]-'0');
    v3.resize(v1.size()+v2.size(),0);
    for(i=0;i<v1.size();i++){
        for(j=0;j<v2.size();j++){
            v3[i+j]+=v1[i]*v2[j];
            if(v3[i+j]>=10){
                v3[i+j+1]+=(v3[i+j]/10);
                v3[i+j]%=10;
            }
        }
    }
    /*for(i=0;i<v1.size()+v2.size();i++){
        if(v3[i]>=10){
            v3[i+1]+=(v3[i]/10);
            v3[i]%=10;
            }
    }*/
    it=v3.end();
    it--;
    for(;it>=v3.begin();it--){
        if(*it!=0)
            break;
    }
    for(;it>=v3.begin();it--){
            cout<<*it;
    }
    return 0;
}