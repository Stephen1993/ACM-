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
            sum+=(s[i][1]-s[i][0])/s[i][2]+1;//sum��ʾ����ȥ�Ĵ������� 
        }
        if(sum%2 == 0)cout<<"DC Qiang is unhappy."<<endl;
        else{
            while(left<=right){
                mid=(right-left)/2+left;//����ѧ��,ע���ֹ�������,��ȻҲ���Զ���__int64���;Ͳ�������� 
                sum=num(n,mid)-num(n,left-1);//n�����ŷ���������ѧ��ѧ��Ϊleft~mid���ܴ�����
                if(sum%2)right=mid-1;
                else left=mid+1;
            }
            printf("%d %I64d\n",left,num(n,left)-num(n,left-1));
        }
    }
    return 0;
}