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

const int MAX=10;

int main(){
    __int64 n;
        while(cin>>n){
        if(n%2 == 0 || n == 1){cout<<"2^? mod "<<n<<" = 1"<<endl;continue;}
        __int64 num=2,i=0;
        while(1){
            ++i;
            if(num%n == 1){cout<<"2^"<<i<<" mod "<<n<<" = 1"<<endl;break;}
            num=(num%n)*2;
        }
    }
    return 0;
}
