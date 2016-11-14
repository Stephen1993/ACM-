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

const int MAX=1001;
bool mark[MAX];
int* *s=NULL;

void define_array(){//定义数组 
	s=new int*[MAX];//定义二维数组第1维德大小 
	for(int i=0;i<MAX;++i)s[i]=new int[2];//定义第二维的大小 
}

bool cmp(int *a,int *b){//对二维数组进行排序 
	if(a[1] == b[1])return a[0]>b[0];
	return a[1]>b[1];
}

int main(){
	define_array();
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>s[i][0];
		for(int i=0;i<n;++i)cin>>s[i][1];
		sort(s,s+n,cmp);
		memset(mark,false,sizeof mark);
		int sum=0,j;
		//思路:每次都选择分数最大的,判断这门功课从它限制的那天开始(限制3天则从第三天开始)往前推看能不能在最晚的一天完成 
		for(int i=0;i<n;++i){
			for(j=s[i][0];j>0;--j){
				if(!mark[j]){mark[j]=true;break;}//该功课可以完成 
			}
			if(j == 0)sum+=s[i][1];
		}
		cout<<sum<<endl;
	}
	return 0;
}