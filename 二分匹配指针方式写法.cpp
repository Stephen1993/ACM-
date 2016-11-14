/*
����ͼ���ƥ��ģ���⣬hduҲ�д��⣬
�������Ҽǵ���fzu�ϵ��ǲ��������ڽӾ���������������ʱ���ύ�ǳ�ʱ�ˣ�����ѧϰ���ڽӱ����ڽӱ�����ʾͼ���ڱ�����ʱ����Ժܿ졣

��������ģ�����Ҽ��˶Σ��Ǹ������г�ʼ��̰��ƥ�䣬Ҳ�������Ż����ٵģ��ܶ����ͼƥ�������ͼ����Ǻܶ�㣬�ܶ�ߵĻ������ڽӱ��ͼ���ٳ�ʼ��̰��ƥ��Ļ��Ϳ��Ա��ⳬʱ��

�ڽӱ�ı�ʾ�����������д��������vector��д�����аٶȰɣ�����Ŀ����ʣ����ÿ���˱���ᡣ
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define MM(a,b) memset(a,b,sizeof(a));
typedef long long lld;
typedef unsigned long long u64;
#define maxn 1010

void up_min(int &x,int y){if((x>y)||(x==-1))x=y;}
int n, top;
struct Edge{
    int v;
    Edge *next;
}*adj[maxn+maxn], edge[maxn*maxn];
void Addedge(int u,int v){
    Edge *p= &edge[++top];
    p->v= v;
    p->next= adj[u];
    adj[u]= p;
}

int mate[maxn+maxn];
bool vis[maxn+maxn];
bool Find(int u){
    for(Edge *p=adj[u];p;p=p->next){
        int v= p->v;
        if( !vis[v] ){
            vis[v]=1;
            if( mate[v]== -1 || Find( mate[v] ) ){
                mate[v]= u;
                return 1;
            }
        }
    }
    return 0;
}
int MMG(){
    int i,ans=0;
    MM(mate,-1);
    for(i=0;i<n;++i){
        for(Edge *p= adj[i];p;p= p->next){
            if( mate[ p->v ]== -1 ){
                mate[i]= p->v;
                mate[ p->v ]= i;
                ++ans;
                break;
            }
        }
    }
    for(i=0;i<n;++i){
        if( mate[i]== -1 ){
            MM(vis,0);
            if( Find(i) ) ++ans;
        }
    }
    return ans;
}
int main()
{
    while(cin>>n){
        int i,u,v,t;
        top= 0;
        MM(adj,0);
        for(i=0;i<n;++i){
            scanf("%d: (%d)",&u,&t);
            while(t--){
                scanf("%d",&v);
                Addedge(u,v+n);
                Addedge(v+n,u);
            }
        }
        int ans= MMG();
        printf("%d\n", n- ans/2);
    }
}
