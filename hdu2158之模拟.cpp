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
int s[MAX],num[MAX],pos[MAX];//pos��¼i�ĵ�һ��λ��
int mark[MAX];//��� 

int main(){
	int n,m,q,a;
	while(cin>>n>>m,n+m){
		memset(mark,0,sizeof mark);
		memset(pos,-1,sizeof pos);
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
			if(pos[s[i]] == -1)pos[s[i]]=i;//��¼s[i]�ĵ�һ��λ�� 
		}
		s[n]=n;
		for(int i=1;i<=m;++i){
			scanf("%d",&q);
			int l=n,r=-1,maxlen=INF;
			for(int j=0;j<q;++j){
				scanf("%d",&a);
				num[a]=0;
				mark[a]=i;//���a���ֹ� 
				if(pos[a]>r)r=pos[a];//�ҵ����ֹ���a�����Ҷ�λ�� 
				if(pos[a]<l)l=pos[a];//�ҵ����ֹ���a�������λ�� 
			}
			for(int j=l;j<=r;++j)++num[s[j]];//��l,r֮�򵥳��ֹ�����a 
			maxlen=r-l+1;//��ʼ��������䳤�� 
			while(r<n){
				--num[s[l]];//��˵�������,���ֹ���a�Ĵ�����1 
				if(num[s[l]] == 0){//����µ�[l,r]û����s[l]���Ҷ˵����� 
					while(++r<n && s[r] != s[l])++num[s[r]];//ά��rʹ����[l,r]����m���� 
					num[s[r]]=1;//ֱ���ҵ���s[l]=s[r],�����+1 
				}
				while(++l<=r && mark[s[l]] != i);//lÿ�ζ�����һ��������ĵ�a
				if(r<n && maxlen>r-l+1)maxlen=r-l+1;//����������䳤�� 
			}
			cout<<maxlen<<endl;
		}
	}
	return 0;
}