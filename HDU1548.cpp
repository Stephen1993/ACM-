#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int biaoji[502];
int n,a,b;
struct noto{
	int m;
	int num;
	int time;
}d[502];
int bfs(){
	queue<noto>enqueue;
	noto outqueue;
	enqueue.push(d[a]);
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		biaoji[outqueue.m]=1;
		if(outqueue.m+outqueue.num<=n){
			if(!biaoji[outqueue.m+d[outqueue.m].num]){
				d[outqueue.m+d[outqueue.m].num].time=outqueue.time+1;
				enqueue.push(d[outqueue.m+outqueue.num]);
			}
		   if((outqueue.m+outqueue.num)==b)return d[outqueue.m+outqueue.num].time;
		}
		if(outqueue.m-outqueue.num>=1){
  		  
  		  if(!biaoji[outqueue.m-outqueue.num]){
  		  	d[outqueue.m-d[outqueue.m].num].time=outqueue.time+1;
  		  	enqueue.push(d[outqueue.m-outqueue.num]);
  		  }
  		  if(outqueue.m-outqueue.num==b)return d[outqueue.m-outqueue.num].time;
    	}
     }
    return -1;
}
int main(){
	while(cin>>n,n){
		memset(biaoji,0,sizeof(biaoji));
		cin>>a>>b;
		for(int i=1;i<=n;++i){
			scanf("%d",&d[i].num);
			d[i].m=i;
		}
		d[a].time=0;
		if(a==b){
			cout<<0<<endl;
			continue;
		}
		int sum=bfs();
		cout<<sum<<endl;
	}
	return 0;
}