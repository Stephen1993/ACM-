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
const int MAX=10000;
int s[5];
bool mark[MAX];
typedef struct{
	int number;
	int time;
}noto;
noto start;
int n;
void zhuan(int x){
	s[1]=x/1000;
	s[2]=(x/100)%10;
	s[3]=(x/10)%10;
	s[4]=x%10;
}
int bfs(){
	queue<noto>enqueue;
	noto outqueue,next;
	enqueue.push(start);
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		zhuan(outqueue.number);
		next.time=outqueue.time+1;
		for(int i=1;i<5;++i){
			if(i==1){
				next.number=s[2]*1000+s[1]*100+s[3]*10+s[4];
				if(next.number==n)return next.time;
				if(!mark[next.number])
				{enqueue.push(next);mark[next.number]=true;}
				if(s[i]==1){
					next.number=9*1000+s[2]*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=(s[1]-1)*1000+s[2]*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				if(s[i]==9){
				    next.number=1*1000+s[2]*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=(s[1]+1)*1000+s[2]*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
			}
			else if(i==4){
				next.number=s[1]*1000+s[2]*100+s[4]*10+s[3];
				if(next.number==n)return next.time;
				if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				if(s[i]==1){
					next.number=s[1]*1000+s[2]*100+s[3]*10+9;
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=s[1]*1000+s[2]*100+s[3]*10+s[4]-1;
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				if(s[i]==9){
				    next.number=s[1]*1000+s[2]*100+s[3]*10+1;
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=s[1]*1000+s[2]*100+s[3]*10+s[4]+1;
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
			}
			else if(i==2){
				next.number=s[1]*1000+s[3]*100+s[2]*10+s[4];
				if(next.number==n)return next.time;
				if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				if(s[i]==1){
					next.number=s[1]*1000+9*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				   if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=s[1]*1000+(s[2]-1)*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				if(s[i]==9){
				    next.number=s[1]*1000+1*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=s[1]*1000+(s[2]+1)*100+s[3]*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
			}
			else{
				if(s[i]==1){
					next.number=s[1]*1000+s[2]*100+9*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=s[1]*1000+s[2]*100+(s[3]-1)*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				if(s[i]==9){
				    next.number=s[1]*1000+s[2]*100+1*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
				else{
				    next.number=s[1]*1000+s[2]*100+(s[3]+1)*10+s[4];
					if(next.number==n)return next.time;
				    if(!mark[next.number])
				    {enqueue.push(next);mark[next.number]=true;}
				}
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1000;i<MAX;++i){
			mark[i]=false;
		}
		cin>>n>>start.number;
		mark[start.number]=true;
		start.time=0;
		int sum=bfs();
		cout<<sum<<endl;
	}
	return 0;
}
