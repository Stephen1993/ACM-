/*
ժ�ԣ�KIDx�β��� 
���������ĵ���Ŀ��������ô���֣� 
1�����������ڶ����� 
    n����������Ϊ(xi,yi)������Ϊmi�������� 
����X = ��( xi��mi ) / ��mi 
����Y = ��( yi��mi ) / ��mi 
��������أ���ÿ�����������ͬ���� 
����X = ��xi / n 
����Y = ��yi / n 
2�������ֲ����� 
��������أ��������ȵ����������ģ� 
����X = ( x0 + x1 + x2 ) / 3 
����Y = ( y0 + y1 + y2 ) / 3 
3�������ֲ������� 
    ֻ���ú������ػ������㣬��̫�� 
����������� 
��n���ηֳɶ�������Σ��ֱ�������������Լ�����m����Ϊ�����ֲ����ȣ����Կ������ܶ�Ϊ1����������������� 
��Ϊ���������������� 
���԰���������������İ���ʱ��������������һ������� 
�����������ε����������ڶ����� 
���Կ����������湫ʽ���м��� 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100;
int main(){
	int t,n,a,x1,y1,x2,y2,x3,y3;
	double s,S=0,X=0,Y=0;
	cin>>t;
	while(t--){
		S=X=Y=0;
		cin>>n;
		cin>>x1>>y1>>x2>>y2;
		for(int i=2;i<n;++i){
			cin>>x3>>y3;
			s=0.5*((x1-x3)*(y1-y2)-(x1-x2)*(y1-y3));//�������� 
			X+=s*(x1+x2+x3);//(x1+x2+x3)/3,������������x���꣬����3��������. 
			Y+=s*(y1+y2+y3);
			S+=s;
			x2=x3;
			y2=y3;
		}
		X=X/(3*S);
		Y=Y/(3*S);
		cout<<fixed<<setprecision(2)<<X<<' '<<Y<<endl;
	}
	return 0;
}