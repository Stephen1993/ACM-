/*做法：
不要看列，假设就只有一行数字，选了x则x-1，x+1不能选，要求最大和，要求这个，有两个定义：
f[i][0]：不拿第i个数时得到的最大和
f[i][1]：拿第i个数时得到的最大和
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=200001;
int dpx[MAX][2],dpy[MAX][2];//dpx[i][0]用来保存第i行中不拿第j个数的最大值，dpx[i][0]是拿第j个数的最大值. 
int n,m;                    //同理dpy....... 
int main(){
	int k;
	while(cin>>n>>m){
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&k);
				if(j==0){
					dpx[j][0]=0;
					dpx[j][1]=k;
				}
				else{
					dpx[j][0]=max(dpx[j-1][0],dpx[j-1][1]);
					dpx[j][1]=dpx[j-1][0]+k;
				}
			}
		    if(i==0){
    			dpy[i][0]=0;
    			dpy[i][1]=max(dpx[m-1][0],dpx[m-1][1]);
    		}
    		else{
		    	dpy[i][0]=max(dpy[i-1][0],dpy[i-1][1]);
		    	dpy[i][1]=dpy[i-1][0]+max(dpx[m-1][0],dpx[m-1][1]);
		    }
		}
		cout<<max(dpy[n-1][0],dpy[n-1][1])<<endl;
	}
	return 0;
}