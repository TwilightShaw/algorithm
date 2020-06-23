/**
题目描述
	从左上角顺时针输出矩阵
	3 3
	1 2 3
	4 5 6
	7 8 9
	-1 -1	
	//
	1,2,3,6,9,8,7,4,5 
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int M=600;
struct direct{
	int x;
	int y;
};
int main() {
	int a[M][M],b[M][M],x,y,i,j;
	int c[3][2];
	direct d[4];
	d[0].x=1;d[0].y=0;
	d[1].x=0;d[1].y=-1;
	d[2].x=-1;d[2].y=0;
	d[3].x=0;d[3].y=1;
	cin>>x>>y;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			cin>>a[i][j];
			b[i][j]=0;
		}
	}
	
}