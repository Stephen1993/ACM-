#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<math.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
const double PI=acos(-1.0);

int main(){
	int t;
	double r,R,H,V,h;
	cin>>t;
	while(t--){
		cin>>r>>R>>H>>V;
		if(r == R){//Բ����,ֱ����� 
			h=V/PI/r/r;
		}else{//Բ̨,��ȫΪԲ׶�󰴱������ 
			h=r*H/(R-r);//��ȫ���ǲ���Բ׶��
			double v=PI*r*r*h/3;//��ȫ�ǲ���Բ׶�����
			h=pow((v+V)/v,1.0/3)*h-h;//��ˮ�ǲ��ָ� 
		}
		if(h>H)h=H;
		cout<<fixed<<setprecision(6)<<h<<endl;
	}
	return 0;
}
/*****************************************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<math.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
const double PI=acos(-1.0);
const double eps=1e-7;
double r,R,H,V;

double volume(double h){//����Բ̨�����
	double Ro=(r*H-r*h+R*h)/H;//�����������뾶,����Բ׶��֮����뾶����Ϊr���ܵ���R 
	return PI*h*(r*r+Ro*Ro+Ro*r)/3;//��Բ̨��� 
}

double search(double &key,double &h){
	double left=0,right=h;
	while(right-left>eps){
		double mid=(left+right)/2;
		double v=volume(mid);
		if(fabs(v-key)<eps)return mid;
		else if(v<key)left=mid;
		else right=mid;
	}
	return right;//ˮ����������������ӵ�������ΪH 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>r>>R>>H>>V;
		double h=search(V,H);
		cout<<fixed<<setprecision(6)<<h<<endl;
	}
	return 0;
}