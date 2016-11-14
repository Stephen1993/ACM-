#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=5;
typedef struct{
	int hour;
	int minute;
	double angle;
}noto;
noto s[MAX];
int main(){
	int n;
	cin>>n;
	while(n--){
		for(int i=0;i<5;++i){
			scanf("%d:%d",&s[i].hour,&s[i].minute);
			int m=s[i].hour>12?s[i].hour-12:s[i].hour;
			s[i].angle=fabs(s[i].minute*6-m*30-s[i].minute*0.5);
			if(s[i].angle>180)s[i].angle=360-s[i].angle;
		}
		int k;
		for(int i=0;i<3;++i){
			k=i;
			for(int j=0;j<5;++j){
				if(s[k].angle>=s[j].angle){
					if(s[k].angle==s[j].angle){
						if(s[k].hour>=s[j].hour){
							if(s[k].hour==s[j].hour){
								if(s[k].minute>s[k].minute)k=j;
							}
							else k=j;
						}
					}
					else k=j;
				}
			}
			s[k].angle=INF;
		}
		cout<<setfill('0')<<setw(2)<<s[k].hour<<':'<<setfill('0')<<setw(2)<<s[k].minute<<endl;
	}
	return 0;
}
 