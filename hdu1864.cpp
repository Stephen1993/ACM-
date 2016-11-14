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

const int MAX=31;
double value[MAX],max_money,Q;
int k;

void DFS(int i,double now_money,double s_money){//now_money表示目前报销的钱,s_money表示后面发票剩余的总钱数. 
	if(i>=k){max_money=max(max_money,now_money);return;}
	//是否报销第i张发票. 
	if(now_money+value[i]<=Q/*&& now_money+s_money>max_money*/){//now_money+s_money>max_money,不需要这个剪枝,因为在前面剪枝递归时就一定会满足这个条件. 
		DFS(i+1,now_money+value[i],s_money-value[i]); 
	}
	if(/*now_money<=Q&&*/now_money+s_money-value[i]>max_money){//now_money<=Q,不需要这个剪枝,因为在前面剪枝递归时就一定会满足这个条件.
		DFS(i+1,now_money,s_money-value[i]);
	}
	return;
}

int main(){
	double b;
	int n,m;
	char a,c;
	while(cin>>Q>>n,n){
		k=0;
		for(int i=0;i<n;++i){
			cin>>m;
			double money_A=0,money_B=0,money_C=0;
			bool flag=true;
			for(int j=0;j<m;++j){
				cin>>a>>c>>b; 
				if(a == 'A')money_A+=b;
				else if(a == 'B')money_B+=b;
				else if(a == 'C')money_C+=b;
				else flag=false;
			}
			if(money_A+money_B+money_C>Q || money_A+money_B+money_C>1000.0)flag=false;
			if(money_A<=600.0 && money_B<=600.0 && money_C<=600.0 && flag){
				value[k++]=money_A+money_B+money_C;
			}
		}
		double sum_money=0;
		for(int i=0;i<k;++i)sum_money+=value[i];
		max_money=0;
		DFS(0,0,sum_money);
		cout<<fixed<<setprecision(2)<<max_money<<endl;
	}
	return 0;
}