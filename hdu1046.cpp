#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<iomanip>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=10;
int n,m;
int main(){
	int t,num=1;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    cout<<"Scenario #"<<num++<<":\n";
		if((m*n)&1){
			cout<<fixed<<setprecision(2)<<(m*n-1)+sqrt(2)<<endl;
		}
		else{
			cout<<fixed<<setprecision(2)<<m*n*1.0<<endl;
		}
		cout<<endl;
	}
	return 0;
}
/*
���m*nΪż����ż����С����������m*n/2��������Ҳ��m*n/2������
���m*nΪ���������ȼ�ȥ1���������ĳ��Ȼ�Ҫ����sqrt(2)
*/ 