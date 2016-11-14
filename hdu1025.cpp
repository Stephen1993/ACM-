#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 99999999
using namespace std;

const int MAX=500001;
int p[MAX],sum[MAX];

int main(){
	int n,num=1,mid,left,right,a,b,len;
	while(cin>>n){
		for(int i=0;i<n;++i){
			scanf("%d%d",&a,&b);
			p[a]=b;
		}
		len=1;
		sum[1]=p[1];
		for(int i=1;i<=n;++i){
			left=1,right=len;
			while(left<=right){
				mid=left+(right-left)/2;
				if(sum[mid]<p[i])left=mid+1;//�ȱȽ�sum[mid]<p[i]�ͱȽ�sum[mid]>p[i]�õ������һ��
				else right=mid-1;          //�������ں��߿��ܵõ��Ĳ����ϸ񵥵�����,ǰ�ߵõ������ϸ񵥵����� 
			}
			sum[left]=p[i];
			len=left>len?left:len;
		}
		cout<<"Case "<<num++<<":\n";
		if(len<=1)
		cout<<"My king, at most "<<len<<" road can be built.\n"<<endl;
		else
		cout<<"My king, at most "<<len<<" roads can be built.\n"<<endl;
	}
	return 0;
}