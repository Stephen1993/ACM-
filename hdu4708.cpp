#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
int s[MAX][MAX];

int main(){
	int n,m;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)scanf("%d",&s[i][j]);
		}
		int sum=0,num=0,temp=0,k; 
		for(int i=0;i<n/2;++i){//�ӵ�i�п�ʼ���ı��� 
			k=INF,temp=-INF;
			for(int j=0;j<=n-2*i-2;++j){//�ֱ����˳ʱ����תj(��ʱ����תn-2*i-1-j��)�κ����Ͻ�,���½�,���Ͻ�,���½���ӵĺ� 
				m=s[i+j][i]+s[n-1-i][i+j]+s[i][n-1-i-j]+s[n-1-i-j][n-1-i];
				if(m>temp){
					temp=m;
					k=j;
				}else if(m == temp)k=min(k,n-2*i-1-k)<min(j,n-2*i-1-j)?k:j;//���ǵõ���ͬ�����ֵ������ת�������ܸ��� 
			}
			sum+=temp;
			num+=min(k,n-2*i-1-k);
		}
		cout<<sum+s[n/2][n/2]<<' '<<num<<endl;
	}
	return 0;
}