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
typedef __int64 LL;
using namespace std;

const int MAX=20000+10;
int s[MAX][3];

LL num(int n,int mid){
    LL sum=0;
    int m;
    for(int i=0;i<n;++i){
        m=min(mid,s[i][1]);
        if(m>=s[i][0])sum+=(m-s[i][0])/s[i][2]+1;
    }
    return sum;
}

int main(){
    int n,left,right,mid;
    LL sum;
    while(~scanf("%d",&n)){
        sum=left=right=0;
        for(int i=0;i<n;++i){
            scanf("%d%d%d",&s[i][0],&s[i][1],&s[i][2]);
            right=max(right,s[i][1]);
            sum+=(s[i][1]-s[i][0])/s[i][2]+1;//sum表示发出去的传单总数 
        }
        if(sum%2 == 0)cout<<"DC Qiang is unhappy."<<endl;
        else{
            while(left<=right){
                mid=(right-left)/2+left;//二分学号,注意防止整数溢出,当然也可以定义__int64类型就不会溢出了 
                sum=num(n,mid)-num(n,left-1);//n个社团发传单给的学生学号为left~mid的总传单数
                if(sum%2)right=mid-1;
                else left=mid+1;
            }
            printf("%d %I64d\n",left,num(n,left)-num(n,left-1));
        }
    }
    return 0;
}