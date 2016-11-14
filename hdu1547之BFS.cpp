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

const int MAX=100+10;
char Map[MAX][MAX];
int n,m,sx,sy,s[MAX*MAX];
int dir0[6][2]={0,1,0,-1,1,0,-1,0,-1,-1,1,-1};//ż�������ߵ÷���(���±��0��ʼ)
int dir1[6][2]={0,1,0,-1,1,0,-1,0,-1,1,1,1};//���������ߵ÷��� 

int BFS(bool flag,int sx,int sy){
	char ch=Map[sx][sy];
	Map[sx][sy]='E';
	int sum=0;
	queue<int>q;
	int oq,a,b;
	q.push(sx*m+sy);//����x*n+y�������
	while(!q.empty()){
		oq=q.front();
		q.pop();
		if(flag)s[sum]=oq;//�ȼ�¼��,���sum<3����Ҫ��ԭ�� 
		++sum;
		int x=oq/m,y=oq%m;
		for(int i=0;i<6;++i){
			if(x%2)a=x+dir1[i][0],b=y+dir1[i][1];
			else a=x+dir0[i][0],b=y+dir0[i][1];
			if(a<0 || b<0 || a>=n || (a%2 && b>=m-1) || b>=m)continue;
			if(Map[a][b] == 'E')continue;//��ʾ�õ�Ϊ��
			if(flag && Map[a][b] != ch)continue;//������Χ��ͨ����ͬ��ɫ���� 
			Map[a][b]='E';
			q.push(a*m+b);
		}
	}
	if(flag && sum<3){
		for(int i=0;i<sum;++i)Map[s[i]/m][s[i]%m]=ch;
	}
	return sum;
}

int main(){
	while(cin>>n>>m>>sx>>sy){
		--sx,--sy;
		for(int i=0;i<n;++i)cin>>Map[i];
		int ans=0,sum=0;//sum��ʾ�ܵ�����
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j]>='a' && Map[i][j]<='z')++sum;
			}
		}
		BFS(true,sx,sy);
		for(int i=0;i<m;++i){
			if(Map[0][i] != 'E')ans+=BFS(false,0,i);//��ѯ�붥����ͨ���� 
		}
		cout<<sum-ans<<endl;
	}
	return 0;
}