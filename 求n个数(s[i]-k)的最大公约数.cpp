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
		while(true){//判断gcd是否可以是全部的s[i]-t(t=0~k)的公约数 
			temp=gcd;
			for(int i=0;i<n;++i){
				int num=s[i]/gcd;//最多是gcd的num倍
				if(num>0 && s[i]-num*gcd<=k)continue;//表示gcd可以是s[i]-t的约数(t=0~k)
				//gcd将减小,num=s[i]/gcd必须变大才可能满足s[i]-num*gcd<=k,所以由s[i]去确认新的最大可能的gcd 
				gcd=s[i]/(num+1);//s[i]可能可以的最大约数 
			}
			if(gcd == temp)break;
		}
		//time=n*logn 
		cout<<gcd<<endl;
	}
	return 0;
}