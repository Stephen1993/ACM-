#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=1001;
int hight[2][MAX];//以第i行第j列作为一块木板,每次求出以第i行为底的最大面积,最后求所有i行的最大面积中的最大一个即可. 
int Left[MAX],Right[MAX];//和hdu1056一样求最左端和最右端. 

int main(){
	int n,m,t;
	char a;
	cin>>t;
	while(t--){
	    cin>>n>>m;
		int Max=0;
		for(int i=0;i<2;++i)hight[i][m+1]=hight[i][0]=-1;
		for(int i=1;i<=m;++i)hight[0][i]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a;
				if(a == 'F')hight[i%2][j]=hight[(i-1)%2][j]+1;//求第i行的第j列这块木板的高度.
				else hight[i%2][j]=0;
				Left[j]=Right[j]=j; 
			}
			//就是把hdu1505变一下,看成有i个hdu1506即可,每次求面积最大值. 
			for(int j=1;j<=m;++j){//求连续的有这样高度的木板的最左端. 
				while(hight[i%2][Left[j]-1] >= hight[i%2][j])Left[j]=Left[Left[j]-1];
			}
			for(int j=m;j>=1;--j){//求连续的有这样高度的木板的最右端. 
				while(hight[i%2][Right[j]+1] >= hight[i%2][j])Right[j]=Right[Right[j]+1];
			}
			for(int j=1;j<=m;++j){
				if((Right[j]-Left[j]+1)*hight[i%2][j] > Max)Max=(Right[j]-Left[j]+1)*hight[i%2][j];
			}
		}
		cout<<Max*3<<endl;
	}
	return 0;
}