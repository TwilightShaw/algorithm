#include <iostream>
#include <math.h>
using namespace std;
void print(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}

void insertSort(int a[],int n){ 
    /*n-1趟 初<始已排好一个*/
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
            a[j+1]=a[j--];
        a[j+1]=temp;
    }
}

void binInsertSort(int a[],int n){
    int i,j,mid,left,right,temp;
    for(i=1;i<n;i++){
        left=0;
        right=i-1;
        while(left<=right){
            mid=(left+right)/2;
            if(a[mid]<a[i])
                left=mid+1;
            else right=mid-1;                
        }
        temp=a[i];
        for(j=i-1;j>right;j--)
            a[j+1]=a[j];
        a[left]=temp;
    }
}

void selectSort(int a[],int n){
    /*每趟选择最小的和未排序数中最前面的换*/
    int i,j,d;
    for(i=0;i<n-1;i++){
        d=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[d])
                d=j;
        }
        if(d!=i)
            swap(a[d],a[i]);
    }
}

void normalBubbleSort(int a[],int n){
    /*相邻元素比较 每一轮最大的放最右*/
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
    }
}

void advancedBubbleSort(int a[],int n){
    int i=0,j,flag=1;
    while(i<n-1&&flag){
        flag=0;
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=1;
            }
        }
        i++;
    }
} 

void shellSort(int a[],int n){
    int i,j,flag=1,gap=n;
    while(gap=gap/2){
        //flag=0;
        for(i=0;i<n-gap;i++){
            if(a[i]>a[i+gap]){
                swap(a[i],a[i+gap]);
                //flag=1;
            }
        }
    }
}

void quickSort(int a[],int s,int t){
    if(s<t){
        int i,j;
        i=s+1;
        j=t;
        while(i<j){
            while(a[i]<a[s]&&i<t)
                i++;
            while(a[j]>a[s]&&j>s)
                j--;
            if(i<j)
                swap(a[i],a[j]);
        }
        swap(a[j],a[s]);
        print(a,8);
        quickSort(a,s,j-1);
        quickSort(a,j+1,t);
    }
}

void heapSort(int a[],int n){

}
int main(){
    int a[8]={5,3,4,7,8,7,3,0};
    print(a,8);
    return 0;
}