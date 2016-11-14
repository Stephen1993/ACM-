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

const int MAX=10000+10;
char s[MAX][77];
int rnum[77],next[MAX];

int get_next(int n){
	int i=-1,j=0;
	next[0]=-1;
	while(j<n){
		if(i == -1 || strcmp(s[i],s[j]) == 0)next[++j]=++i;//��ÿһ�п���һ���ַ���next 
		else i=next[i];
	}
	return n-next[n];
}

int main(){
	int r,w,x,y;
	while(cin>>r>>w){
		memset(rnum,0,sizeof rnum);
		for(int i=0;i<r;++i){
			cin>>s[i];
			for(int j=1;j<=w;++j){
				for(x=0,y=j;y<w;++x,++y){
					if(s[i][x%j] != s[i][y])break;//�ж��Ƿ���ѭ������ 
				}
				if(y == w)++rnum[j];//ͳ������ѭ�����ڳ��ȵĸ���,��aaaaa����a,aa,aaa,aaaa,aaaaa���ѭ������ 
			}
		}//��yҲ���Ժ���һ����,���ǱȽ�ÿһ���ַ���ȴ�Ƚ���,�����ñ���ͳ��(�����Ǳ���ͳ��)ȥ�� 
		for(y=1;y<=w;++y)if(rnum[y] == r)break;//�������й�ͬ��С����y,0~y-1Ϊһ������ 
		for(int i=0;i<r;++i)s[i][y]='\0';
		x=get_next(r);//��0~y�й�ͬ��С����x,0~x-1Ϊһ������ 
		cout<<x*y<<endl;
	}
	return 0;
}