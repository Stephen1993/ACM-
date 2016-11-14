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

const int MAX=100000+10;
int n,k,mark[MAX*2];

struct Node{
	int x,time;
}start;

int BFS(int &flag){
	if(start.x == k)return 0;
	mark[start.x]=flag;
	queue<Node>q;
	q.push(start);
	Node oq,next;
	while(!q.empty()){
		oq=q.front();
		q.pop();
		next.time=oq.time+1;
		if(oq.x<k){
			next.x=oq.x+1;
			if(mark[next.x] != flag){
				if(next.x == k)return next.time;
				q.push(next);
				mark[next.x]=flag;
			}
		}
		if(oq.x>0){
			next.x=oq.x-1;
			if(mark[next.x] != flag){
				if(next.x == k)return next.time;
				q.push(next);
				mark[next.x]=flag;
			}
		}
		if(oq.x<k){
			next.x=oq.x*2;
			if(mark[next.x] != flag){
				if(next.x == k)return next.time;
				q.push(next);
				mark[next.x]=flag;
			}
		}
	}
}

int main(){
	int num=0;
	while(cin>>n>>k){
		start.x=n,start.time=0;
		cout<<BFS(++num)<<endl;
	}
	return 0;
}