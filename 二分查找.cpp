#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=1000;
int s[MAX];

int binary_search(int a[],int left,int right,int b){//二分查找,查找某个数. 
	int mid;
	while(left<=right){
		mid=left+(right-left)/2;
		if(a[mid]>b)right=mid-1;
		else if(a[mid]<b)left=mid+1;
		else return mid;//将这里改为return （mid+1）>n?-1:mid+1和下面改为return right;则是求最接近b的大于b的数. 
	}
	return -1;//return right;
}

int binary_search2(int a[],int left,int right,int b){//二分查找,查找第一个大于等于b的数(小于等于同理). 
    int mid;
	if(left>right)return -1;
	while(left<right){
		mid=left+(right-left)/2;//如果要求第一个小于等于B则mid=left+(right-left+1)/2. 
		if(a[mid]>=b)right=mid;//如果要求第一个小于等于B的数则mid-1,下面的是left=mid. 
		else left=mid+1;
	}
	if(a[right]>=b)return right;
	return -1;
}
int main(){
	for(int i=0;i<MAX;++i){
		s[i]=i+1;
	}
	int n;
	while(cin>>n){
		cout<<binary_search2(s,0,MAX-1,n)<<endl;
	}
	return 0;
}

/*
更新风格后的代码,没怎么写全,其他类似 
int search(int key,int hash[],int n){//求大于等于key的第一个数的位置 
	int left=0,right=n-1;
	while(left<right){
		int mid=left+right>>1;
		if(hash[mid]<key)left=mid+1;
		else right=mid;
	}
	return left;
}

int search(int key,node x[],int n){//查找第一个大于等于key的数 
	int left=0,right=m-1;
	while(left<right){
		int mid=left+right>>1;
		if(x[mid].x>=key)right=mid;
		else left=mid+1;
	}
	return left;
}

int search(int key,int hash[],int n){//求小于等于key的最后一个数的位置 
	int left=0,right=n-1;
	while(left+1<right){
		int mid=left+right>>1;
		if(hash[mid]>key)right=mid-1;
		else left=mid;
	}
	if(s[right]<=key)return right;
	return left;
}
*/
LL search1(LL x){//寻找第一个>=x的数 
	LL left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]<x)left=mid+1;
		else right=mid-1;
	}
	return right+1; 
}

LL search2(LL x){//寻找最后一个<=x的数 
	LL left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]<=x)left=mid+1;
		else right=mid-1;
	}
	return left-1;
}