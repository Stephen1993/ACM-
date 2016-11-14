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

const int MAX=20+10;
const int mod=1000;
int s[MAX][MAX],sum[MAX][MAX],array[MAX][MAX];
int n,m;

void MatrixMult(int a[MAX][MAX],int b[MAX][MAX]){
    int c[MAX][MAX]={0};
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)a[i][j]=c[i][j];
    }
}

int Matrix(int a,int b,int k){//矩阵快速幂 
    for(int i=0;i<n;++i){//初始化矩阵sum,使sum*b=b(b是矩阵) 
        for(int j=0;j<n;++j){
            if(i == j)sum[i][j]=1;
            else sum[i][j]=0;
        }
    }
    for(int i=0;i<n;++i){//将最初矩阵s复制给array 
        for(int j=0;j<n;++j)array[i][j]=s[i][j];
    }
    while(k){
        if(k&1)MatrixMult(sum,array);
        MatrixMult(array,array);
        k>>=1;
    }
    return sum[a][b];
}

int main(){
    int a,b,t,k;
    while(cin>>n>>m,n+m){
        memset(s,0,sizeof s);
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            s[a][b]=1;
        }
        cin>>t;
        while(t--){
            scanf("%d%d%d",&a,&b,&k);
            printf("%d\n",Matrix(a,b,k));
        }
    }
    return 0;
}