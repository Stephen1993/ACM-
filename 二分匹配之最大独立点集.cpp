#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#define INF 99999999
using namespace std;

const int MAX=1555;
vector<int>marry[MAX];
int link[MAX],n,link1[MAX];
bool mark[MAX];

bool find(int v){
    for(int i=0;i<marry[v].size();++i){
        if(!mark[marry[v][i]]){
            mark[marry[v][i]]=true;
            if(link[marry[v][i]] == -1 || find(link[marry[v][i]])){
                link[marry[v][i]]=v;
                return true;
            }
        }
    }
    return false;
}

int hungarian_algorithm(){
    memset(link1,-1,sizeof(int)*(n+1));
    memset(link,-1,sizeof(int)*(n+1));
    int num=0;
    for(int i=0;i<n;++i){//初始化贪心匹配.
        for(int j=0;j<marry[i].size();++j){
            if(link[marry[i][j]] == -1){
                link1[i]=marry[i][j];
                link[marry[i][j]]=i;
                ++num;
                break;
            }
        }
    }
    for(int i=0;i<n;++i){
        if(link1[i] == -1){//初始化匹配不成功则寻找增广路径.
            memset(mark,false,sizeof mark);
            if(find(i)) ++num;
        }
    }
    return num;
}

int main(){
    int a,b,c;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)marry[i].clear();
        for(int i=0;i<n;++i){
            scanf("%d: (%d)",&a,&b);
            for(int j=0;j<b;++j){
                scanf("%d",&c);
                marry[a].push_back(c);
               // marry[c].push_back(a);
            }
        }
        int sum=hungarian_algorithm();
        printf("%d\n",n-sum/2);
    }
    return 0;
}
