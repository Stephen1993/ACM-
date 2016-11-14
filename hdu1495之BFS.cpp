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

const int MAX=101+10;
int sum,n,m;
bool mark[MAX][MAX];//��ʾ����a,b��ˮi,j��״̬�Ƿ񵽴�� 

struct Node{
	int a,b,c,time;//������a,b,c���ˮ���͵�ˮ�Ĵ��� 
	Node(){}
	Node(int A,int B,int C,int Time):a(A),b(B),c(C),time(Time){} 
}start;

int BFS(){
	memset(mark,false,sizeof mark);
	start=Node(2*sum,0,0,0);
	mark[start.a][start.b]=true;
	Node oq,next;
	queue<Node>q;
	q.push(start);
	while(!q.empty()){
		oq=q.front();
		q.pop();
		int x=2*sum-oq.a,y=n-oq.b,z=m-oq.c;
		if(x){//��a������Ե�ˮ
			if(oq.b)next=Node(oq.a+min(x,oq.b),oq.b-min(x,oq.b),oq.c,oq.time+1);//b��a��ˮ 
			if(!mark[next.a][next.b]){
				mark[next.a][next.b]=true;
				if(next.a == sum && next.b == sum || (next.a == sum && next.c == sum) || (next.b == sum && next.c == sum))return next.time;
				q.push(next);
			}
			if(oq.c)next=Node(oq.a+min(x,oq.c),oq.b,oq.c-min(x,oq.c),oq.time+1);//c��a��ˮ 
			if(!mark[next.a][next.b]){
				mark[next.a][next.b]=true;
				if(next.a == sum && next.b == sum || (next.a == sum && next.c == sum) || (next.b == sum && next.c == sum))return next.time;
				q.push(next);
			}
		}
		if(y){//��b���浹ˮ 
			if(oq.a)next=Node(oq.a-min(oq.a,y),oq.b+min(oq.a,y),oq.c,oq.time+1);//a��b��ˮ
			if(!mark[next.a][next.b]){
				mark[next.a][next.b]=true;
				if(next.a == sum && next.b == sum || (next.a == sum && next.c == sum) || (next.b == sum && next.c == sum))return next.time;
				q.push(next);
			}
			if(oq.c)next=Node(oq.a,oq.b+min(y,oq.c),oq.c-min(y,oq.c),oq.time+1);//c��b��ˮ
			if(!mark[next.a][next.b]){
				mark[next.a][next.b]=true;
				if(next.a == sum && next.b == sum || (next.a == sum && next.c == sum) || (next.b == sum && next.c == sum))return next.time;
				q.push(next);
			}
		}
		if(z){//��c��ˮ 
			if(oq.a)next=Node(oq.a-min(oq.a,z),oq.b,oq.c+min(oq.a,z),oq.time+1);//a��c��ˮ
			if(!mark[next.a][next.b]){
				mark[next.a][next.b]=true;
				if(next.a == sum && next.b == sum || (next.a == sum && next.c == sum) || (next.b == sum && next.c == sum))return next.time;
				q.push(next);
			}
			if(oq.b)next=Node(oq.a,oq.b-min(oq.b,z),oq.c+min(oq.b,z),oq.time+1);//b��c��ˮ
			if(!mark[next.a][next.b]){
				mark[next.a][next.b]=true;
				if(next.a == sum && next.b == sum || (next.a == sum && next.c == sum) || (next.b == sum && next.c == sum))return next.time;
				q.push(next);
			}
		}
	}
	return -1;
}

int main(){
	while(cin>>sum>>n>>m,sum+n+m){
		if(sum%2){cout<<"NO"<<endl;continue;}
		sum=sum/2;
		int temp=BFS();
		if(temp == -1)cout<<"NO"<<endl;
		else cout<<temp<<endl;
	}
	return 0;
}