#include <iostream>
#include <vector>
using namespace std;
const int num=1000000;
const int mod=99997867;
int main(){
    long long i,j,k,left,right,mid;
    long long sum=0,N,D;
    scanf("%lld %lld",&N,&D);
    vector <long long> s(N);
    for(i=0;i<N;i++){
         cin>>s[i];
    }
    /*for(i=0;i<N-2;i++){	//折半
		k=s[i]+D; // s[mid+1]>k>=s[mid]  
        left=i+2;
        right=N-1;
		long long mid0=0;
        while(left<=right) {
        	mid=(left+right)/2;
			if(k>=s[mid]){
				mid0=mid;
        		left=mid+1;
	        }
	        else right=mid-1;
		}
		if(mid0)
			sum+=(mid0-i)*(mid0-i-1)/2;*/
	 for(i=0;i<N-2;i++){ //折半
		k=s[i]+D; // s[mid+1]>k>=s[mid]  
		left=i+1;
		right=N-1;
		while(left<=right) {
			mid=(left+right)/2;
			if(k>=s[mid])left=mid+1;
			else right=mid-1;
		}
		sum+=(right-i)*(right-i-1)/2;
		sum%=mod;
		}
    
    cout<<sum%mod<<endl;
    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;
const int num=1000000;
const int mod=99997867;
int main(){
    long long i,j,k,left,right,mid;
    long long sum=0,N,D;
    scanf("%lld %lld",&N,&D);
    vector <long long> s(N);
    for(i=0;i<N;i++){
         cin>>s[i];
    }
    for(i=0;i<N-2;i++){	//折半
		k=s[i]+D; // s[mid+1]>k>=s[mid]  
        left=i+2;
        right=N-1;
		int flag=0;
        while(left<=right) {
        	mid=(left+right)/2;
			if(k>=s[mid]){
				flag=1;
        		left=mid+1;
	        }
	        else right=mid-1;
		}
		if(flag)
			sum+=(mid-i)*(mid-i-1)/2;

    }
    cout<<sum%mod<<endl;
    return 0;
}
*/
/*
链接：https://www.nowcoder.com/questionTerminal/c0803540c94848baac03096745b55b9b
来源：牛客网

我叫王大锤，是一名特工。我刚刚接到任务：在字节跳动大街进行埋伏，抓捕恐怖分子孔连顺。和我一起行动的还有另外两名特工，我提议

1. 我们在字节跳动大街的N个建筑中选定3个埋伏地点。
2. 为了相互照应，我们决定相距最远的两名特工间的距离不超过D。

我特喵是个天才! 经过精密的计算，我们从X种可行的埋伏方案中选择了一种。这个方案万无一失，颤抖吧，孔连顺！
……
万万没想到，计划还是失败了，孔连顺化妆成小龙女，混在cosplay的队伍中逃出了字节跳动大街。只怪他的伪装太成功了，就是杨过本人来了也发现不了的！

请听题：给定N（可选作为埋伏点的建筑物数）、D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择。
注意：
1. 两个特工不能埋伏在同一地点
2. 三个特工是等价的：即同样的位置组合(A, B, C) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用


输入描述:
第一行包含空格分隔的两个数字 N和D(1?≤?N?≤?1000000; 1?≤?D?≤?1000000)

第二行包含N个建筑物的的位置，每个位置用一个整数（取值区间为[0, 1000000]）表示，从小到大排列（将字节跳动大街看做一条数轴）
*/