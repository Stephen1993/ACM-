/*
N! = 1 * 2 * 3 * (2*2) * 5 * (2*3) * 7... 

����10��ԭ������2,5�����ӣ���Ȼ��N!��2�ĸ�������5�ĸ���������ֻ�����5�ĸ������� 

�� N! (1*2*3*4*5*...*N)���ж��ٸ�5��ʵ����ת���ɣ� 
N!�У���5�ı�������+��5^2�ı�������+5^3..... 

��50!�� 
����10��5�ı���������5,15,20,25,30,35,40,45,50 ��50/5=10�� 
����2��5^2�ı���������25,50��50/(5^2)=2�� 
�ɼ�N!��һ����12��5��ˣ���ôβ0Ҳ����12�� 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10;
int n;
int main(){
	int t;
	cin>>t;
	while(t--){
		int sum=0;
		scanf("%d",&n);
		for(int i=1;n;++i){
			sum+=n/5;
			n=n/5;
		}
		printf("%d\n",sum);
	}
	return 0;
} 