#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<time.h>
#define INF 999999
using namespace std;
const int MAX=1111;
typedef struct noto{
	int x;
	int y;
	int z;
	/*friend bool operator<(noto a,noto b){//自定义优先级从小到大排序,默认是return x<a.x为按从大到小排序。 
		return a.x>b.x;
	}*/
	bool operator<(const noto&a)const{
		return x>a.x;
	}		
};
noto s[MAX];

struct cmp{
	bool operator()(noto a,noto b){//自定义比较函数cmp按y从小到大排序。 
	return a.y>b.y;
    }
};
	
int main(){
	time_t t;
	srand((unsigned)time(&t));
//**************************************************************自定义优先级排序. 
    cout<<"自定义优先级按x从小到大排序"<<endl; 
    priority_queue<noto>m;
	cout<<"原来x顺序:";
	for(int i=0;i<10;++i){
		s[i].x=rand()%1000;
		cout<<s[i].x<<' ';
		m.push(s[i]);
	}
	cout<<endl<<"现在x顺序:";
	for(int i=0;i<10;++i){
		s[i]=m.top();
		m.pop();
		cout<<s[i].x<<' ';
	}
	cout<<endl<<endl;;
//**************************************************************自定义比较函数排序.
    cout<<"自定义比较函数cmp按y从小到大排序"<<endl;
    priority_queue<noto,vector<noto>,cmp>n;
    cout<<"原来x顺序:";
	for(int i=0;i<10;++i){
		s[i].x=rand()%1000;
		s[i].y=rand()%1000;
		n.push(s[i]);
		cout<<s[i].x<<' ';
	}
	cout<<endl;
	cout<<"原来y顺序:";
	for(int i=0;i<10;++i){
		cout<<s[i].y<<' ';
	}
	cout<<endl<<"现在x顺序:";
	for(int i=0;i<10;++i){
		s[i]=n.top();
		n.pop();
		cout<<s[i].x<<' ';
	}
	cout<<endl<<"现在y顺序:";
	for(int i=0;i<10;++i){
		cout<<s[i].y<<' ';
	}
	cout<<endl;
	return 0;
}