/*����������i%a - i%b,ÿ�μ��ϴ�i��ʼ�����ֵ(i%a - i%b)��ȵ�һ��,
����i�Ͳ���ÿ��+1,����ÿ�μ���һ��,�������n����a,b����С��������
��ֻ��Ҫ����a,b��С���������ȵ��ܺͣ�Ȼ��sum*=n/per + p;//p��ʾǰi����,p=n%per;

���ⷴ˼:�տ�ʼ�Լ����������룬�����뵽a,b����С���������ܴܺ�,����nҲ�ܴ�
����պ�����n<per����n�ܴ�;//per��ʾa,b��С����������������n>per����per�ܴ� 
��ʹһ�ζε���Ҳ���ܳ�ʱ������һֱ�������֣�һֱ����Ѱ���򵥵����ۡ������һֱû�ҵ�
�´������������Ӧ�������ԣ������Ҳ�����ĸ��򵥵ķ��������Լ��뵽�ķ�����������

���������������ʱ�临�ӶȺ�����:O((a/b * min(per,n)/a));//����a>=b 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<math.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
__int64 p;

__int64 Gcd(__int64 a,__int64 b){
    if(b == 0)return a;
    return Gcd(b,a%b);
}

__int64 calculate(__int64 n,__int64 a,__int64 b,__int64 num){
    p=0;
    __int64 la=a,lb=b,sum=0,l;
    for(__int64 i=0;i<n;){
        l=min(la,min(lb,n-i));
        if(i+l>num && i<num)p=sum+abs((int)(i%a - i%b))*(num-i);
        sum+=abs((int)(i%a - i%b))*l;
        i+=l;
        la=(la-l+a-1)%a+1;
        lb=(lb-l+b-1)%b+1;
    }
    return sum;
}

int main(){
    __int64 n,a,b,t;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d%I64d%I64d",&n,&a,&b);
        __int64 gcd=Gcd(a,b),per=a*b/gcd,k=min(per,n);//�����С������ 
        __int64 sum=calculate(k,a,b,n%k);
        if(n>per)sum=(n/per)*sum+p;//p��ʾǰn%k��i%a-i%b�ĺ� 
        printf("%I64d\n",sum);
    }
    return 0;
}