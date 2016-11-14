#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<map>
#define INF 9999999
using namespace std;
const int MAX=10000;
bool prime[MAX];
void Prime(){
	for(int i=2;i<MAX/2;++i)prime[2*i]=true;
	for(int i=3;i*i<MAX;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<MAX;j+=2*i){
				prime[j]=true;
			}
		}
	}
}
typedef struct{
	int time;
	int number;
}noto;
noto start,end;
int bfs(){
	if(start.number==end.number)return start.time;
	map<int,int>Q;
	queue<noto>enqueue;
	noto outqueue,next;
	enqueue.push(start);
	Q[start.number]=1;
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		for(int i=0;i<4;++i){
			int s[4]={outqueue.number/1000,(outqueue.number/100)%10,(outqueue.number/10)%10,outqueue.number%10};
			int j;
			if(i==0)j=1;
			else j=0;
			for(;j<=9;++j){
				if(s[i]!=j){
					s[i]=j;
					next.number=s[0]*1000+s[1]*100+s[2]*10+s[3];
					next.time=outqueue.time+1;
					if(next.number==end.number)return next.time;
					if(!Q[next.number]&&!prime[next.number]){
						enqueue.push(next);
						Q[next.number]=1;
					}
				}
			}
		}
	}
}
int main(){
	Prime();
	int t;
	cin>>t;
	while(t--){
		cin>>start.number>>end.number;
		start.time=0;
		cout<<bfs()<<endl;
	}
	return 0;
}