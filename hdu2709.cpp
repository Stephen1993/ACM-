/*
����:�ٶ���Ҫ��Ľ��Ϊs[n],���ֱ����s[n-1]����+1
����s[n]+=s[n-1];
��nΪż����a+b+c..+d=n��a,b,c,d...>=2,��s[n]+=s[n/2];//��2����1������n/2��1����ת��Ϊs[n/2]
���ԣ�nΪ���� =��s[n]=s[n-1]
nΪż�� =��s[n]=s[n-1]+s[n/2] 
*/
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

const int MAX=1000000+10;
const int mod=1000000000;
int s[MAX];

int main(){
	s[1]=1;
	for(int i=2;i<MAX;++i){
		s[i]=s[i-1];
		if(i%2 == 0)s[i]+=s[i/2];
		s[i]%=mod;
	}
	int n;
	while(cin>>n){
		cout<<s[n]<<endl;
	}
	return 0;
}