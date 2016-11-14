#include<iostream>
using namespace std;
int prime[26]={
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
};
int main(){
    char a[100],b[100];
    while(cin>>a>>b,strcmp(a,"0")||strcmp(b,"0")){
    	int sum[30]={0},A[30]={0},B[30]={0};
    	int k=0,i,j,la=0,lb=0;
    	for(i=0;i<strlen(a);++i){
	    	if(a[i]!=',')A[la]=A[la]*10+a[i]-'0';
	    	else la++;
	    }
    	for(i=0;i<strlen(b);++i){
	    	if(b[i]!=',')B[lb]=B[lb]*10+b[i]-'0';
	    	else lb++;
	    }
    	for(i=la,j=lb;i>=0&&j>=0;--i,--j){
	    		sum[k]+=A[i]+B[j];
	    		sum[k+1]=sum[k]/prime[k];
	    		sum[k]=sum[k]%prime[k];
	    		k++;
	    }
	    while(i>=0){
    		sum[k]+=A[i];
    		sum[k+1]=sum[k]/prime[k];
    		sum[k]=sum[k]%prime[k];
    		k++;
	    	i--;
    	}
    	while(j>=0){
	    	sum[k]+=B[j];
	    	sum[k+1]=sum[k]/prime[k];
	    	sum[k]=sum[k]%prime[k];
    		k++;
    		j--;
	    }
       if(sum[k]>0)k++;
       cout<<sum[k-1];
       for(i=k-2;i>=0;--i){
       	cout<<','<<sum[i];
       }
       cout<<endl;
    }
    return 0;
}