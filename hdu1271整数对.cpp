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
set<int>s;//为了防止插入的数重复且要排序,所以用set. 

int main(){
	int n,a,b,c;
	while(scanf("%d",&n),n){
		/*一个数可以分解为x=a+b*10^k+c*10^(k+1) , k是去掉第k+1位的意思,a是第k+1位前的数,
		  c是第k+1位后的数,b是第k+1位数 ，如12345去掉第3位则a=45,b=3,c=12. 
		  则去掉第k位后剩余的数y=a+c*10^k,==>n=x+y=2*a+b*10^k+11*c*10^k;
		  ==>m=n/10^k=b+11*c;由于b<=9,即使2*a进位使b=10,b/11也是为0,所以m/11=c
		  不过b可能进位变成10. 
       */
       s.clear();
       for(int i=1;i<=n;i=i*10){
       	   c=n/i/11;
       	   b=n/i-11*c;
       	   if((b!=0 || c!=0) && b<10){//b!=0 || c!=0是因为可能去掉的是最后一位,这时b为首位不能为0,一般情况下c不能为0 
			   a=(n-11*c*i-b*i)/2;   //如果b=10则一定b进位了. 
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