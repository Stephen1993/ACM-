#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#include<set>
#define INF 99999999
using namespace std;

const int MAX=1000;
//vector<int>s;
set<int>s;//Ϊ�˷�ֹ��������ظ���Ҫ����,������set. 

int main(){
	int n,a,b,c;
	while(scanf("%d",&n),n){
		/*һ�������Էֽ�Ϊx=a+b*10^k+c*10^(k+1) , k��ȥ����k+1λ����˼,a�ǵ�k+1λǰ����,
		  c�ǵ�k+1λ�����,b�ǵ�k+1λ�� ����12345ȥ����3λ��a=45,b=3,c=12. 
		  ��ȥ����kλ��ʣ�����y=a+c*10^k,==>n=x+y=2*a+b*10^k+11*c*10^k;
		  ==>m=n/10^k=b+11*c;����b<=9,��ʹ2*a��λʹb=10,b/11Ҳ��Ϊ0,����m/11=c
		  ����b���ܽ�λ���10. 
       */
       s.clear();
       for(int i=1;i<=n;i=i*10){
       	   c=n/i/11;
       	   b=n/i-11*c;
       	   if((b!=0 || c!=0) && b<10){//b!=0 || c!=0����Ϊ����ȥ���������һλ,��ʱbΪ��λ����Ϊ0,һ�������c����Ϊ0 
			   a=(n-11*c*i-b*i)/2;   //���b=10��һ��b��λ��. 
			   if(2*a+b*i+11*c*i==n)
   	       	   s.insert(a+b*i+c*i*10);
   	       }
   	       b--;
   	       if((b!=0 || c!=0) && b>=0){
   	       	   a=(n-11*c*i-b*i)/2;
   	       	   if(2*a+b*i+11*c*i==n)
       	   	   s.insert(a+b*i+c*i*10);
       	   }
       }
       //sort(s.begin(),s.end());
       if(s.size()==0)cout<<"No solution.";
       else{
       	    set<int>::iterator p=s.begin();
       	    cout<<*p;
 	        for(++p;p!=s.end();++p){
       	        cout<<' '<<*p;
            }
       }
       cout<<endl;
	}
	return 0;
}