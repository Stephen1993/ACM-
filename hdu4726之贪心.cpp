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

const int MAX=1000000+10;
char a[MAX],b[MAX];
int numa[10],numb[10];

int main(){
    int t,i,j,k,num=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        memset(numa,0,sizeof numa);
        memset(numb,0,sizeof numb);
        for(i=0;i<lena;++i)++numa[a[i]-'0'];
        for(i=0;i<lenb;++i)++numb[b[i]-'0'];
        printf("Case #%d: ",++num);
        for(i=9;i>=0;--i){//判断首位最大值
            for(j=1;j<10;++j){
                if((i-j+10)%10 == 0)continue;
                if(numa[j] && numb[(i-j+10)%10]){--numa[j],--numb[(i-j+10)%10];break;}
            }
            if(j != 10){printf("%d",i);break;}
        }
        if(i == 0){cout<<endl;continue;}
        if(i == -1){cout<<0<<endl;continue;}
        for(k=1;k<lena;++k){//a,b长度相等才能这样算
            for(i=9;i>=0;--i){
                for(j=0;j<10;++j){
                    if(numa[j] && numb[(i-j+10)%10]){--numa[j],--numb[(i-j+10)%10];break;}
                }
                if(j != 10){printf("%d",i);break;}
            }
        }
        cout<<endl;
    }
    return 0;
}