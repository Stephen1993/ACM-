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

const int MAX=80+10;
int n,m,dist[MAX][MAX],s,t;
int array[MAX][MAX][MAX],temp[MAX][MAX];
//array记录初始矩阵,temp记录array转化后的一维矩阵

void check(int a,int c){//转化为一维矩阵在此处优化大 
    for(int i=1;i<=m;++i){
        if(temp[0][i] != temp[c][i])return;
    }
    dist[a][c]=1;
}

void MakeRoad(int a,int b){
    for(int i=1;i<=m;++i){
        temp[0][i]=0;
        for(int j=1;j<=m;++j){//转化为一维矩阵在此处优化大 
            temp[0][i]+=array[a][i][j]*temp[b][j];//相当于array[a]*array[b]*[0,1,2,3...m];//[0...m-1]是行矩阵 
        }
    }
    for(int i=1;i<=n;++i){
        if(i == a || i == b)continue;
        check(a,i);
    }
}

void floyd(){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int main(){
    while(cin>>n>>m,n+m){
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=m;++j){
                temp[i][j]=0;
                for(int k=1;k<=m;++k){
                    scanf("%d",&array[i][j][k]);
                    temp[i][j]+=array[i][j][k]*k;//array*[1,...m],[1...m]是一维行矩阵 
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j)dist[i][j]=dist[j][i]=INF;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i == j)continue;
                MakeRoad(i,j);//创建道路 
            }
        }
        floyd();//求每个点到其他点的距离
        cin>>n;
        for(int i=0;i<n;++i){
            scanf("%d%d",&s,&t);
            if(dist[s][t] == INF)printf("Sorry\n");
            else printf("%d\n",dist[s][t]);
        }
    }
    return 0;
} 