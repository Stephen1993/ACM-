#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=200;
int main(){
	int n;
	while(cin>>n,n){
		n=(n-1960)/10+2;
		n=1<<n; 
		double s=0,i=0;
		while(++i){//�ö������Ƚϡ� 
			s+=log10(i)/log10(2);
			if(s>=n){
				cout<<i-1<<endl;//��ʵÿ���󵽽�����Դ�������,�´ξͲ��ü�����. 
				break;
			}
		}
	}
	return 0;
}