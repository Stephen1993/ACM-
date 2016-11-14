#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<time.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10000+10;
const int mod=1000000000+7;
int s[MAX],temp[MAX],id[MAX];

void Merge(int *a,int i,int mid,int j,int n,int *b){
	int k=0,t=i;
	while(i<=mid && j<=n){
		if(a[i]<a[j])id[t+k]=i,b[k++]=a[i++];
		else id[t+k]=j,b[k++]=a[j++];
	}
	while(i<=mid)id[t+k]=i,b[k++]=a[i++];
	while(j<=n)id[t+k]=j,b[k++]=a[j++];
	k=0;
	while(t<=n)a[t++]=b[k++];
}

void Sort(int *a,int i,int j,int *b){
	if(i == j)return;
	int mid=i+j>>1;
	Sort(a,i,mid,b);//��a����a[i]~a[mid]��������
	Sort(a,mid+1,j,b);//��a����a[mid+1]~a[j]��������
	Merge(a,i,mid,mid+1,j,b);//�ϲ�����a��i~mid��mid+1~j����
}

int main(){
	int n;
	srand((unsigned)time(NULL));
	while(cin>>n){
	    id[0]=0;
		cout<<"����ǰ������:";
		for(int i=0;i<n;++i){
			s[i]=rand()%mod;//��s�����������ֵ
			cout<<" "<<s[i];
		}
		Sort(s,0,n-1,temp);//��s����s[0]~s[n-1]��������
		cout<<"\n����������:";
		for(int i=0;i<n;++i)cout<<" "<<s[i];
		cout<<endl;
	}
	return 0;
}
