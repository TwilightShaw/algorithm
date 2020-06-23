#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct tagSL_NODE
{
    int iV;
    struct tagSL_NODE *pstNext;
}SL_NODE_S;
typedef struct MY_SET
{
    SL_NODE_S *pstFirst;
}MY_SET_S;

void insertItem(MY_SET_S *&pstSet,int item){
    SL_NODE_S *p,*q,*r;
    p=(SL_NODE_S *)malloc(sizeof(SL_NODE_S));
    p->iV=item;
    p->pstNext=NULL;
    if(pstSet==NULL)
    {
        pstSet=(MY_SET_S*)malloc(sizeof(MY_SET_S));
        pstSet->pstFirst=p;
    }
    else{
        q=pstSet->pstFirst;
        while(q!=NULL&&q->iV<item){
            r=q;
            q=q->pstNext;
        }
        r->pstNext=p;
        p->pstNext=q;
    }
}
MY_SET_S* create(int a[],int n){
    MY_SET_S *list=NULL;
    int i;
    SL_NODE_S *p,*q,*r;
    for(i=1;i<=n;i++){
       insertItem(list,a[i-1]);
    }
    return list;
}
void print(MY_SET_S *set){
    if(set!=NULL){
        SL_NODE_S *p=set->pstFirst;
        while(p){
            cout<<p->iV<<"  ";
            p=p->pstNext;
        }
        cout<<endl;
    }
}
void SetSub(MY_SET_S *pstSetA,MY_SET_S *pstSetB, MY_SET_S *&pstSetC){
    SL_NODE_S *p,*q,*r,*list;
    p=pstSetA->pstFirst;
    q=pstSetB->pstFirst;
    pstSetC=(MY_SET_S*)malloc(sizeof(MY_SET_S));
    pstSetC->pstFirst=NULL;
    r=NULL;
    while(p!=NULL&&q!=NULL){
        if(p->iV<q->iV){
            p=p->pstNext;
        }
        else if(p->iV==q->iV){
            if(pstSetC->pstFirst==NULL){
                pstSetC->pstFirst=p;
            }
            else{
                r->pstNext=p;
            }
            r=p;
        }
        else{
            q=q->pstNext;
        }
    }
    r->pstNext=p;
}
int main(){
    int a[]={1,3,2},b[]={1,3,5};
    MY_SET_S *pstSetA=create(a,3);
    print(pstSetA);
    MY_SET_S *pstSetB=create(b,3);
    print(pstSetB);
    MY_SET_S *pstSetC;
    SetSub(pstSetA,pstSetB,pstSetC);
    print(pstSetC);
    return 0;
}