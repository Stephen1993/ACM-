/*
分析:对于白色珠来说，只有每次拿两个白色珠才能消耗2个
所以若是奇数个白色珠,则最后一定只剩下一个白色的,因为每次拿2个白色珠才能消耗，最后一定会剩下一个
若是偶数个白色珠，也只有拿两个消耗两个，最后肯定不剩 
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

const int MAX=10;

int main(){
	int t,b,w;
	cin>>t;
	while(t--){
		cin>>b>>w;
		if(w&1)printf("0.00 1.00\n");
		else printf("1.00 0.00\n");
	}
	return 0;
} 