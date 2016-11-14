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

const int MAX=20;
int s[MAX];
int x[301],y[301];//x用来存各种硬币价值的组合数,y用来存合并表达式时的硬币价值的组合数.

int main(){
    for(int i=1;i<=17;++i){
        s[i]=i*i;
    }
    //for(int i=0;i<=300;++i)x[i]=1,y[i]=0;//初始化第一个表达式的指数为i的变量的系数为1.
    x[0]=1;//表示第0个表达式只有指数为0的变量系数(即组合数)为1.
    for(int i=1;i<=17;++i){
        for(int j=0;j<=300;++j){//第i个表达式之前的合并后的表达式的第1,2,3,...n个变量的指数.
            for(int k=0;k+j<=300;k+=s[i]){//k表示i中第1,2,3....n个的变量的指数,指数每次增加s[i].
                y[k+j]+=x[j];//k+j表示合并表达式后的变量的指数.(第n个变量和第j个变量合并,指数为k+j)
            }               //x是存第i个表达式之前合并后的表达式的指数为j的组合数.
        }
        for(int j=1;j<=300;++j){
            x[j]=y[j],y[j]=0;
        }
    }
    int n;
    while(cin>>n,n){
        cout<<x[n]<<endl;
    }
    return 0;
}
