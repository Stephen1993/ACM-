#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=3*100000+10;
int s[MAX];

int main(){
	int n,k;
	while(cin>>n>>k){
		int gcd=INF,temp;
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
			gcd=min(gcd,s[i]);
		}
		while(true){//�ж�gcd�Ƿ������ȫ����s[i]-t(t=0~k)�Ĺ�Լ�� 
			temp=gcd;
			for(int i=0;i<n;++i){
				int num=s[i]/gcd;//�����gcd��num��
				if(num>0 && s[i]-num*gcd<=k)continue;//��ʾgcd������s[i]-t��Լ��(t=0~k)
				//gcd����С,num=s[i]/gcd������ſ�������s[i]-num*gcd<=k,������s[i]ȥȷ���µ������ܵ�gcd 
				gcd=s[i]/(num+1);//s[i]���ܿ��Ե����Լ�� 
			}
			if(gcd == temp)break;
		}
		//time=n*logn 
		cout<<gcd<<endl;
	}
	return 0;
}