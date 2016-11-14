#include<iostream>
#include<queue>
using namespace std;
int dir[8][2]={{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1}};
//int biaoji[111][111];
struct noto{
	char a;
	int b;
	int num;
}A,B;

int BFS(noto a,noto b){
	if(a.a==b.a&&a.b==b.b)return a.num;
	noto next,outqueue;
	queue<noto>enqueue;
	enqueue.push(a);
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		//biaoji[outqueue.a][outqueue.b]=1;
		for(int i=0;i<8;++i){
			next.a=outqueue.a+dir[i][0];
			next.b=outqueue.b+dir[i][1];
			next.num=outqueue.num+1;
			if(next.a==b.a&&next.b==b.b)return next.num;
			//if(!biaoji[next.a][next.b])
			   if(next.a>='a'&&next.a<='h'&&next.b>=1&&next.b<=8)
		      	  enqueue.push(next);
		}
	}
}

int main(){
	while(cin>>A.a>>A.b>>B.a>>B.b){
		A.num=0;
		//memset(biaoji,0,sizeof(biaoji));
		int sum=BFS(A,B);
		cout<<"To get from "<<A.a<<A.b<<" to "<<B.a<<B.b<<" takes "<<sum<<" knight moves."<<endl;
	}
	return 0;
}