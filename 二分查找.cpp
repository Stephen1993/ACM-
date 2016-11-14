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

int binary_search(int a[],int left,int right,int b){//���ֲ���,����ĳ����. 
	int mid;
	while(left<=right){
		mid=left+(right-left)/2;
		if(a[mid]>b)right=mid-1;
		else if(a[mid]<b)left=mid+1;
		else return mid;//�������Ϊreturn ��mid+1��>n?-1:mid+1�������Ϊreturn right;��������ӽ�b�Ĵ���b����. 
	}
	return -1;//return right;
}

int binary_search2(int a[],int left,int right,int b){//���ֲ���,���ҵ�һ�����ڵ���b����(С�ڵ���ͬ��). 
    int mid;
	if(left>right)return -1;
	while(left<right){
		mid=left+(right-left)/2;//���Ҫ���һ��С�ڵ���B��mid=left+(right-left+1)/2. 
		if(a[mid]>=b)right=mid;//���Ҫ���һ��С�ڵ���B������mid-1,�������left=mid. 
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
���·���Ĵ���,û��ôдȫ,�������� 
int search(int key,int hash[],int n){//����ڵ���key�ĵ�һ������λ�� 
	int left=0,right=n-1;
	while(left<right){
		int mid=left+right>>1;
		if(hash[mid]<key)left=mid+1;
		else right=mid;
	}
	return left;
}

int search(int key,node x[],int n){//���ҵ�һ�����ڵ���key���� 
	int left=0,right=m-1;
	while(left<right){
		int mid=left+right>>1;
		if(x[mid].x>=key)right=mid;
		else left=mid+1;
	}
	return left;
}

int search(int key,int hash[],int n){//��С�ڵ���key�����һ������λ�� 
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
LL search1(LL x){//Ѱ�ҵ�һ��>=x���� 
	LL left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]<x)left=mid+1;
		else right=mid-1;
	}
	return right+1; 
}

LL search2(LL x){//Ѱ�����һ��<=x���� 
	LL left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]<=x)left=mid+1;
		else right=mid-1;
	}
	return left-1;
}