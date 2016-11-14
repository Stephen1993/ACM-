#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 2000000000
typedef long long LL;
using namespace std;

const int MAX=2*100000+10;
int a[MAX],b[MAX];
//pos记录a这个值对应b哪个位置,suma记录a对应 b的那个位置有多少个,sumb记录b的某个位置数有多少个
int pos[MAX],suma[MAX],sumb[MAX];
bool mark[MAX],flag[MAX];

int search(int l,int r,int x){
    while(l<=r){
        int mid=l+r>>1;
        if(x == b[mid])return mid;
        if(x < b[mid])r=mid-1;
        else l=mid+1;
    }
    return 0;
}

int main(){
    int n,m,p,M;
    while(~scanf("%d%d%d",&n,&m,&p)){
        M=m;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=m;++i)scanf("%d",&b[i]);
        sort(b+1,b+m+1);
        b[m+1]=INF,m=1,sumb[1]=1;
        for(int i=2;b[i] != INF;++i){
            if(b[i] != b[i-1])b[++m]=b[i],sumb[m]=1;
            else ++sumb[m];
        }
        memset(mark,false,sizeof mark);
        memset(flag,false,sizeof flag);
        int ans=0;
        for(int i=1,x=1,y=1;i<=n;x=y=++i){
            if(mark[x])continue;
            for(;y<=n;y=y+p){
            	mark[y]=true;
                int k=search(1,m,a[y]);
                pos[y]=k;
                if(k == 0){ans=0;while(x<=y){suma[pos[x]]=0,x+=p;}}
                else{
                    ++suma[pos[y]];
                    if(suma[pos[y]]>sumb[pos[y]]){
                        while(pos[x] != pos[y]){
                            if(suma[pos[x]] == sumb[pos[x]])--ans;
                            --suma[pos[x]];
                            x+=p;
                        };
                        --suma[pos[y]];
                        x+=p;
                    }else if(suma[pos[y]] == sumb[pos[y]])++ans;
                    if(ans == m && x+(M-1)*p == y)flag[x]=true;
                    if(x+(M-1)*p<y){
                        if(suma[pos[x]] == sumb[pos[x]])--ans;
                        --suma[pos[x]];
                        x+=p;
                    }
                }
            }
            ans=0;
            while(x<y){suma[pos[x]]=0,x+=p;}
        }
        ans=0;
        for(int i=1;i<=n;++i)if(flag[i])++ans;
        cout<<ans<<endl;
        for(int i=1;i<=n;++i)if(flag[i])cout<<i<<endl;
    }
    return 0;
} 