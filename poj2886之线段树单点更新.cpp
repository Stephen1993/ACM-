#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector> 
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=500000+2;
int sum[MAX<<2];//ĳ��������ʣ�������
char name[MAX][12];
int s[MAX];
int dp[35][2]={
{1,1},{2,2},{4,3},{6,4},{12,6},{24,8},{36,9},{48,10},{60,12},{120,16},{180,18},{240,20},{360,24},{720,30},
{840,32},{1260,36},{1680,40},{2520,48},{5040,60},{7560,64},{10080,72},{15120,80},{20160,84},{25200,90},{27720,96},
{45360,100},{50400,108},{55440,120},{83160,128},{110880,144},{166320,160},{221760,168},{277200,180},{332640,192},{498960,200}
};

/*void Factor(){//����n�ڵ����Լ����ż����� 
    int factornum[20];//��¼�����Ӹ���
    int n=0;
    dp[0][0]=1,dp[0][1]=1;
	for(int i=2;i<MAX;++i){
		int k=0,x=i;
		for(int j=2;j*j<=x;++j){//�������Ӹ��� 
			if(x%j == 0){
				int num=0;
				while(x%j == 0){++num;x=x/j;}
				factornum[k++]=num;
			}
		}
		if(x != 1)factornum[k++]=1;
		int ans=1;
		for(int j=0;j<k;++j){//����i�����Ӹ��� 
			ans*=(factornum[j]+1);
		}
		//�����ᳬʱ,����ֻ�ܴ�� 
		if(ans>dp[n][1]){dp[n+1][0]=i,dp[++n][1]=ans;cout<<dp[n][0]<<' '<<dp[n][1]<<endl;}
	}
	cout<<n<<endl;
}*/

void BuildTree(int n,int left,int right){
	sum[n]=right-left+1;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
}

int Query(int pos,int n,int left,int right){
	--sum[n];//��������˽��˳�һ��
	if(left == right)return left;
	int mid=left+right>>1;
	if(sum[n<<1]>=pos)return Query(pos,n<<1,left,mid);
	else return Query(pos-sum[n<<1],n<<1|1,mid+1,right);
}

int main(){
	//Factor();
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;++i){
			scanf("%s%d",name[i],&s[i]);
		}
		BuildTree(1,1,n);
		int m=34,pos=k,num=n;//mȷ���˳������,posȷ���˳�����λ�����
		int x=k-1;//x��ʾposǰ��ʣ�༸����
		k=1;
		for(int i=0;i<=34;++i)if(n<dp[i][0]){m=i-1;break;}
		Query(pos,1,1,n);
		while(k != dp[m][0]){
			--num;//�ܹ�ʣ����˵ĸ��� 
			++k;//׼���˳������ǵڼ����˳��� 
			if(s[pos]>0)pos=(x+s[pos])%num;
			else pos=((x+s[pos]+1)%num+num)%num;
			if(pos == 0)pos=num;
			x=pos-1;
			pos=Query(pos,1,1,n);//��ѯ���λ����� 
		} 
		printf("%s %d\n",name[pos],dp[m][1]);
	}
	return 0;
} 