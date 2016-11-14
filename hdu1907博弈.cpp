#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=48;
int main(){
	int t,n,a;
	cin>>t;
	int num=0;
	while(t--){
		cin>>n;
		num=0;
		int sum=0;
		for(int i=0;i<n;++i){
			cin>>a;
			sum=sum^a;
			if(a==1)num++;
		}
		if(num == n)
            {
                if(!sum) printf("John\n");
                else    printf("Brother\n");     
            }
            else
            {
                if(!sum) printf("Brother\n");
                else    printf("John\n"); 
            }      
	}
	return 0;
}