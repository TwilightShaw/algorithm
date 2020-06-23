#include <iostream>
#include <malloc.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    vector <int> h,w;
    int n,m,i,j,t,count=0;
    vector <int>::iterator it;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>t;
        h.push_back(t);
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>t;
        w.push_back(t);
    }
    sort(h.begin(),h.end(),greater<int>());
    sort(w.begin(),w.end(),greater<int>());
    i=0;
    j=0;
    while(i<n&&j<m){
        if(h[i]<=w[j]){
            count++;
            i++;
            j++;
        }
        if(i>=n||j>=m)
            break;
        while(i<n&&h[i]>w[j])
            i++;
    }
    cout<<count;
    return 0;
}