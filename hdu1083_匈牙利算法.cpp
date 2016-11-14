#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h>
using namespace std;
const int MAX=333;
int map[MAX][MAX],v[MAX],link[MAX];//map[i][j]��ʾi��j����ƥ�䣬v[i]���i����ƥ�䲢���ѱ�ƥ���,link[i]��ʾi��link[i]ƥ�䡣 
int p,n;
bool find(int x){
    for(int i=1;i<=n;++i){
        if(!v[i]&&map[x][i]){
            v[i]=1;
            if(!link[i] || find(link[i])){
                link[i]=x;
                return true;
            }
        }
    }
    return false;
}
int course(){
    int sum=0;
    for(int i=1;i<=p;++i){
        memset(v,0,sizeof v);
        if(find(i))sum++;
    }
    return sum;
}
int main(){
    int t,m,a;
    cin>>t;
    while(t--){
        memset(link,0,sizeof link);
        memset(map,0,sizeof map);
        cin>>p>>n;
        for(int i=1;i<=p;++i){
            scanf("%d",&m);
            for(int j=0;j<m;++j){
                scanf("%d",&a);
                map[i][a]=1;
            }
        }
        if(course()==p){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
} 