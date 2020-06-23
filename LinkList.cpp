#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct Node{
    int data;
    struct Node *link;
}LNode,*LinkList;
/*
*输出链表
*/
void print(LinkList p){
    while(p){
        cout<<p->data<<" ";
        p=p->link;
    }
    cout<<endl;

}

/*
*建立链表
*/
LinkList create(int a[],int n){
    LinkList p,q=NULL,r;
    int i;
    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(struct Node));//p=(LinkList)malloc(sizeof(LNode))
        p->data=a[i];
        p->link=NULL;
        if(q==NULL){
            q=p;
        }
        else {
            r->link=p;
        }
        r=p;
    }
    return q;
}

/*
*值有序 插入Item 不递减
*/
void insertItem(LinkList &list,int item){
    LinkList p,q,r;
    p=(LinkList)malloc(sizeof(LNode));
    p->data=item;
    p->link=NULL;
    if(list==NULL)
        list=p;
    else{
        q=list;
        while(q!=NULL&&q->data<item){
            r=q;
            q=q->link;
        }
        r->link=p;
        p->link=q;
    }
}
/*
*删除q指向节点
*/
void deleteNode(LinkList &list,LinkList q){
    if(q==NULL)
        list=list->link;
    else{
        LinkList p=list,r;
        while(p&&p!=q){
            r=p;
            p=p->link;
        }
        r->link=q->link;
        free(q);
    }
}
/*
*销毁
*/
void destroy(LinkList &list)
{
    LinkList q=list;
    while(q){
        list=q->link;
        free(q);
    }
}

/*
删除所有item
*/
void deleteItem(LinkList &list,int item){
    LinkList p,q;
    p=list->link;
    q=list;
    while(p){
        if(p->data==item)
        {
            q->link=p->link;
            free(p);
            p=q->link;
        }
        else{
            q=p;
            p=p->link;
        }
    }
    while(list->data==item){
        p=list;
        list=list->link;
        free(p);
    }
}

/**
 * 逆转一个链表
*/
void reverse(LinkList &list){
    LinkList p=list,q=NULL,r;
    while(p){
        r=q;
        q=p;
        p=p->link;
        q->link=r;
    }
    list=q;
}

/**
 * 两个有序合并成一个
*/
LinkList merge(LinkList lista,LinkList listb){
    LinkList p,q,r,list;
    p=lista;
    q=listb;
    if(lista->data<listb->data){
        list=lista;
        r=lista;
        p=lista->link;
    }
    else {
        list=listb;
        r=listb;
        q=listb->link;
    }
    while(p!=NULL&&q!=NULL){
        if(p->data<=q->data){
            r->link=p;
            r=p;
            p=p->link;
        }
        else {
            r->link=q;
            r=q;
            q=q->link;
        }
    }
    r->link=p?p:q;
    return list;
}

/**
 * 复制链表
*/ 
LinkList copy(LinkList lista){
    LinkList listb=NULL,p,q,r;
    q=lista;
    while(q){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=q->data;
        p->link=NULL;
        if(!listb){
            listb=p;
        }
        else{
            r->link=p;
        }
        r=p;
        q=q->link;
    }
    return listb;
}

/**
 * 链表有头结点list，链表最大值移至表尾
*/
void maxToEnd(LinkList &list){
    LinkList p,q,r,s;
    p=list->link;
    s=list;
    q=list;
    while(p){
        if(p->data>s->data){
            r=q;
            s=p;
        }
        q=p;
        p=p->link;
    }
    if(s!=q){
        if(s==list)
            list=list->link;
        else{
            r->link=s->link;
        }
        q->link=s;
        s->link=NULL;
    }
}

int main(){
    //int a[8]={0,2,3,4,6,7,7,7};
    int a[8]={5,3,4,7,8,7,3,0};
    LinkList l=create(a,8),l2,l3;
    print(l);
    l2=copy(l);
    print(l2);
    maxToEnd(l);
    print(l);
    //reverse(l);
    //print(l);
    //int b[]={1,3,4,9};
    //l2=create(b,4);
    //print(l2);
    //l3=merge(l,l2);
    //print(l3);
    //insertItem(l,9);
    //print(l);
    //insertItem(l,3);
    //print(l);
    return 0;
}