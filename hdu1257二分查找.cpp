#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#define INF 99999999
using namespace std;

const int MAX=15555;
int s[MAX];

int search(int s[],int left,int right,int n){
	int mid;
	while(left<right){
		mid=left+(right-left)/2;
		if(s[mid]>=n){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	if(right>-1 && s[right] >= n)return right;
	return -1;
}

int main(){
	int a,sum,n;
	while(cin>>n){
		sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			int j=search(s,0,sum-1,a);
			if(j == -1)s[sum++]=a;
		    else s[j]=a;
		    sort(s,s+sum);
		}
		cout<<sum<<endl;
	}
	return 0;
}