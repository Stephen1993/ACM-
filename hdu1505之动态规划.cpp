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
int hight[2][MAX];//�Ե�i�е�j����Ϊһ��ľ��,ÿ������Ե�i��Ϊ�׵�������,���������i�е��������е����һ������. 
int Left[MAX],Right[MAX];//��hdu1056һ��������˺����Ҷ�. 

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
				if(a == 'F')hight[i%2][j]=hight[(i-1)%2][j]+1;//���i�еĵ�j�����ľ��ĸ߶�.
				else hight[i%2][j]=0;
				Left[j]=Right[j]=j; 
			}
			//���ǰ�hdu1505��һ��,������i��hdu1506����,ÿ����������ֵ. 
			for(int j=1;j<=m;++j){//���������������߶ȵ�ľ��������. 
				while(hight[i%2][Left[j]-1] >= hight[i%2][j])Left[j]=Left[Left[j]-1];
			}
			for(int j=m;j>=1;--j){//���������������߶ȵ�ľ������Ҷ�. 
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