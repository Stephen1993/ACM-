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
	/*friend bool operator<(noto a,noto b){//�Զ������ȼ���С��������,Ĭ����return x<a.xΪ���Ӵ�С���� 
		return a.x>b.x;
	}*/
	bool operator<(const noto&a)const{
		return x>a.x;
	}		
};
noto s[MAX];

struct cmp{
	bool operator()(noto a,noto b){//�Զ���ȽϺ���cmp��y��С�������� 
	return a.y>b.y;
    }
};
	
int main(){
	time_t t;
	srand((unsigned)time(&t));
//**************************************************************�Զ������ȼ�����. 
    cout<<"�Զ������ȼ���x��С��������"<<endl; 
    priority_queue<noto>m;
	cout<<"ԭ��x˳��:";
	for(int i=0;i<10;++i){
		s[i].x=rand()%1000;
		cout<<s[i].x<<' ';
		m.push(s[i]);
	}
	cout<<endl<<"����x˳��:";
	for(int i=0;i<10;++i){
		s[i]=m.top();
		m.pop();
		cout<<s[i].x<<' ';
	}
	cout<<endl<<endl;;
//**************************************************************�Զ���ȽϺ�������.
    cout<<"�Զ���ȽϺ���cmp��y��С��������"<<endl;
    priority_queue<noto,vector<noto>,cmp>n;
    cout<<"ԭ��x˳��:";
	for(int i=0;i<10;++i){
		s[i].x=rand()%1000;
		s[i].y=rand()%1000;
		n.push(s[i]);
		cout<<s[i].x<<' ';
	}
	cout<<endl;
	cout<<"ԭ��y˳��:";
	for(int i=0;i<10;++i){
		cout<<s[i].y<<' ';
	}
	cout<<endl<<"����x˳��:";
	for(int i=0;i<10;++i){
		s[i]=n.top();
		n.pop();
		cout<<s[i].x<<' ';
	}
	cout<<endl<<"����y˳��:";
	for(int i=0;i<10;++i){
		cout<<s[i].y<<' ';
	}
	cout<<endl;
	return 0;
}