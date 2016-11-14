#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=1000+10;
int *rank,r[MAX],sa[MAX],height[MAX];
int wa[MAX],wb[MAX],wm[MAX];
char s[MAX];

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];//r[a]��ʾ��һ�ؼ���,r[a+l]��ʾ�ڶ��ؼ��� 
}

void makesa(int *r,int *sa,int n,int m){
	int *x=wa,*y=wb,*t;//x��¼����������Ľ��,�൱��rank,y��¼�ڶ��ؼ���
	 
	//��һ�λ�������
	for(int i=0;i<m;++i)wm[i]=0;//�����е��Ӵ�������0 
	for(int i=0;i<n;++i)wm[x[i]=r[i]]++;//�Ӵ�r[i]�ĸ���(������Ӵ�����Ϊ1���Ӵ���r[i]) 
	for(int i=1;i<m;++i)wm[i]+=wm[i-1];//ͳ��<=�Ӵ�i�ĸ���(�Ӵ�����Ϊ1,i��ʾ�����Ӵ���ASCII) 
	//wm[x[i]]��ʾ<=x[i]���Ӵ��ж��ٸ�(������0��ʼ,����--wm[]),i=n-1��ʼ�Ǳ�֤��ͬ���Ӵ�λ���ں���ľ����ں���
	for(int i=n-1;i>=0;--i)sa[--wm[x[i]]]=i;//����Ϊ--wm[x[i]]���Ӵ���suffix(i) 
	
	//�������л�������ֱ��ȫ���Ӵ���������ͬ
	for(int i=0,j=1,p=1;p<n;j=j*2,m=p){//j��ʾҪ�ϲ����Ӵ��ĳ���,m=p��ʾ��Ҫ��������ֵΪp������ 
		for(p=0,i=n-j;i<n;++i)y[p++]=i;//�Եڶ��ؼ�������Խ����Ӵ��Ƚ��еڶ��ؼ�������
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;//��ʣ����Ӵ����еڶ��ؼ�������
		//ͨ���ڶ��ؼ��ֺ͵�һ�ؼ��ֽ��л�������
		for(i=0;i<m;++i)wm[i]=0;
		for(i=0;i<n;++i)wm[x[y[i]]]++;//x��¼�����ϴ�������Ľ��(����,Ҳ�ǵ�һ�ؼ���),�൱��rank
		for(i=1;i<m;++i)wm[i]+=wm[i-1];
		//�ڶ��ؼ���(����)�Ӵ�С,�ڵڶ��ؼ���Ϊi���Ǹ��Ӵ�y[i]�ĵ�һ�ؼ���Ϊx[y[i]],��һ�ؼ���x[y[i]]ǰ����wm[]��������--wm[](������0��ʼ) 
		for(i=n-1;i>=0;--i)sa[--wm[x[y[i]]]]=y[i];//��������Ϊ--wm[]�����Ӵ�y[i]
		//�����µ�x��ȵ��Ӵ���������ͬ,��Ϊ��һ�ε�����xҪ�õ���������y����(����x,y����) 
		for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0;i<n;++i){
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;//����Ӵ��ĵ�һ�ؼ��ֺ͵ڶ��ؼ������������һ����p-1 
		} 
	}
	rank=x;//�������r�Ѿ�����ȫ��rank�� 
}

void calheight(int *r,int *sa,int n){
	for(int i=0,j=0,k=0;i<n;height[rank[i++]]=k)
		for(k?--k:0,j=sa[rank[i]-1];r[i+k] == r[j+k];++k);
}

int main(){
	while(~scanf("%s",s),s[0] != '#'){
		int len=0;
		for(len=0;s[len] != '\0';++len)r[len]=s[len];//ת��������
		r[len]=0;
		makesa(r,sa,len+1,256);//len+1��ʾ���ַ�������+0ȷ���Ӵ��Ƚϲ���Խ��(��Խ��ǰһ���ܱȳ���С)
		calheight(r,sa,len+1);
		int L=INF,R=-INF,sum=0;
		for(int i=1;i<=len/2;++i){//����Ϊi�����Ӵ�
			L=INF,R=-INF;
			for(int j=2;j<=len;++j){//height[1]=0,����j���Դ�2��ʼ 
				if(height[j]>=i){
					L=min(L,sa[j]);
					L=min(L,sa[j-1]);
					R=max(R,sa[j]);
					R=max(R,sa[j-1]);
				}else{
					if(L+i<=R)++sum;
					L=INF,R=-INF;
				}
			}
			if(L+i<=R)++sum;
		}
		cout<<sum<<endl;
	}
	return 0;
}