#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int mm=111;
int f[mm][mm];
int sum[mm],g[mm],a[mm];
int n;
int dfs(int l,int r)
{
    if (l==r)return 0;
    if (f[l][r]!=-1)return f[l][r];
    f[l][r]=1e9;
    for (int i=l;i<r;++i)
        f[l][r]=min(f[l][r],dfs(i+1,r)+min(
                    (g[l]-g[i+1])-(sum[i]-sum[l-1])*(n-r),
                    dfs(l,i)+(i-l+1)*(sum[r]-sum[i])));
    return f[l][r];
}
int main()
{
    int i,t,cas=1;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        g[n+1]=sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(i=n;i>=1;i--)
            g[i]=g[i+1]+(n-i)*a[i];
        memset(f,-1,sizeof(f));
        printf("Case #%d: ",cas++);
        printf("%d\n",dfs(1,n));
    }
    return 0;
}