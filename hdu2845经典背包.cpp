/*������
��Ҫ���У������ֻ��һ�����֣�ѡ��x��x-1��x+1����ѡ��Ҫ�����ͣ�Ҫ����������������壺
f[i][0]�����õ�i����ʱ�õ�������
f[i][1]���õ�i����ʱ�õ�������
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
int dpx[MAX][2],dpy[MAX][2];//dpx[i][0]���������i���в��õ�j���������ֵ��dpx[i][0]���õ�j���������ֵ. 
int n,m;                    //ͬ��dpy....... 
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