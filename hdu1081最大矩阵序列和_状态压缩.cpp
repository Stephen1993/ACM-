#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 9999999
using namespace std;
const int MAX=111;
int s[MAX][MAX];//C�����i�е�j��ǰ������֮��. 
int main(){
	int n,a;
	while(cin>>n){
		for(int i=0;i<n;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&a);
				s[i][j]=s[i][j-1]+a; 
			}
		}
		int max=-INF,sum;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<=n;++j){
				sum=0;
				for(int k=0;k<n;++k){
					if(sum<0){
						sum=0;
					}
					sum+=s[k][j]-s[k][i];//��k�е�j�е���i�е������д�ֵ. 
					if(sum>max){
						max=sum;
					}
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
//��������Ҫ����״̬ѹ���۽�ʡʱ��. 