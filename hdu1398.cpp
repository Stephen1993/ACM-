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
int x[301],y[301];//x���������Ӳ�Ҽ�ֵ�������,y������ϲ����ʽʱ��Ӳ�Ҽ�ֵ�������.

int main(){
    for(int i=1;i<=17;++i){
        s[i]=i*i;
    }
    //for(int i=0;i<=300;++i)x[i]=1,y[i]=0;//��ʼ����һ�����ʽ��ָ��Ϊi�ı�����ϵ��Ϊ1.
    x[0]=1;//��ʾ��0�����ʽֻ��ָ��Ϊ0�ı���ϵ��(�������)Ϊ1.
    for(int i=1;i<=17;++i){
        for(int j=0;j<=300;++j){//��i�����ʽ֮ǰ�ĺϲ���ı��ʽ�ĵ�1,2,3,...n��������ָ��.
            for(int k=0;k+j<=300;k+=s[i]){//k��ʾi�е�1,2,3....n���ı�����ָ��,ָ��ÿ������s[i].
                y[k+j]+=x[j];//k+j��ʾ�ϲ����ʽ��ı�����ָ��.(��n�������͵�j�������ϲ�,ָ��Ϊk+j)
            }               //x�Ǵ��i�����ʽ֮ǰ�ϲ���ı��ʽ��ָ��Ϊj�������.
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
