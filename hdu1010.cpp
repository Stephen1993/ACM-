#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h>
#include<cmath>
using namespace std;

const int MAX=10;
char map[MAX][MAX];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,start_time;
int start_x,start_y,end_x,end_y;

bool DFS(int x,int y,int use_time){
	int next_x,next_y;
	int left_time=start_time-use_time;//ʣ�����ʱ�� 
	int over_time=left_time-abs(x-end_x)-abs(y-end_y);//����û��ǽ������ʱ�䵽���ڴ���ʣ���ʱ�� 
	if(over_time<0||over_time&1){//��ż��֦������������룺�㻨�����ٵ�ʱ�䣨���㵱ǰ��λ�����յ�λ�ú��������� 
		return false;            //Ȼ���㵽���յ㣬�����㻹��ʱ��࣬�������������Ĵӳ��ڴ��˻��Թ�һ����Ȼ������ǰ��һ�� 
	}                            //������ڴ���ʱ����2���������˻�n����ֻ����ǰ��n��������ڴ��ˣ�ʱ��2nΪż������˵���˻���ʵ����Ϊ��ǽ��. 
	for(int i=0;i<4;++i){
		next_x=x+dir[i][0];
		next_y=y+dir[i][1];
		if(next_x==end_x&&next_y==end_y&&left_time==1&&left_time==1){
			return true;
		}
		else if(map[next_x][next_y]=='.'&&next_x>=0&&next_y<m&&next_x<n&&next_y>=0){
			map[next_x][next_y]='X';//�߹��ĵط����Ϊǽ���´ξͲ��������� 
			bool flag=DFS(next_x,next_y,use_time+1);
			map[next_x][next_y]='.';//���ص�ʱ��Ҫ�Ѹõ��Ϊδ��. 
			if(flag)return true;
		}
	}
	return false;
}

int main(){
	while(cin>>n>>m>>start_time,n&&m&&start_time){
		int wall=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				//scanf("%c",&map[i][j]);
				cin>>map[i][j];
				if(map[i][j]=='S'){
					start_x=i;
					start_y=j;
				}
				if(map[i][j]=='D'){
					end_x=i;
					end_y=j;
				}
				if(map[i][j]=='X'){
					wall++;
				}
			}
		}
		if(n*m-wall<=start_time){//��֦��ʣ���·����ǽ���������NO,��Ŀ����˼����˵�߳��Թ���ʱ��Ҫǡ�õ���������ʱ��Ŷ�� 
			cout<<"NO"<<endl;
			continue;
		}
		map[start_x][start_y]='X';
		bool flag=DFS(start_x,start_y,0);
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	}
	return 0;
}