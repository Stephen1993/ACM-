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

const int MAX=5001;
bool mark[MAX];

int main(){
	int n,t,m;
	cin>>t;
	while(t--){
		cin>>n;
		m=n;
		memset(mark,false,sizeof(bool)*(n+2));
		if(m>3)for(int i=2;i<=n;i+=2)mark[i]=true,m--;
		int num=0,sum=0;
		if(m>3)//Ϊ����ʿ������3�����ܼ�����. 
		for(int j=1;;j++){
			sum=(j%2 == 1?3:2);
			num=0;
			for(int i=1;i<=n;i+=2){
			    if(!mark[i]){
    				num++;
    			}
    			if(num==sum){
			    	mark[i]=true;
			    	m--;//ÿ����һ��ʿ������һ��. 
			    	num=0;
			    }
		    }
		    if(m<=3)break;//δ����ʿ��������3������Ҫ������. 
		}
		cout<<'1';
		for(int i=2;i<=n;++i){
			if(!mark[i]){
				cout<<' '<<i;
			}
		}
		cout<<endl;
	}
	return 0;
} 