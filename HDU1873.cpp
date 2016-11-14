#include<iostream>
#include<queue>
#include<string>
using namespace std;

typedef struct noto{
	int ID;
	int number;
	bool operator<(const noto &a)const{
		if(number!=a.number)return number<a.number;
		return ID>a.ID;
	}
};

int main(){
	int n,a,b,k;
	while(cin>>n){
		k=1;
		string d;
		priority_queue<noto>q[5];
		for(int i=0;i<n;++i){
			cin>>d;
			if(d=="IN"){
				noto c;
				c.ID=k++;
				cin>>a>>b;
				c.number=b;
				q[a].push(c);
			}
			else{
				cin>>a;
				if(q[a].empty())cout<<"EMPTY"<<endl;
				else{
					cout<<q[a].top().ID<<endl;
					q[a].pop();
				}
			}
		}
		for(int i=1;i<4;++i){
			while(!q[i].empty()){
				q[i].pop();
			}
		}
	}
	return 0;
}