/*
��ϸ����: 
http://hi.baidu.com/faithyzy/item/c8c8142502418bd2a517b6ee
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
const int MAX=1001;
int x[MAX],y[MAX];
int main(){
	int n;
	while(cin>>n,n){
		for(int i=0;i<n;++i){
			scanf("%d",&x[i]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&y[i]);
		}
		sort(x,x+n);
		sort(y,y+n);
		int num=0;
		for(int i=0,j=0,a=n-1,b=n-1;i<=a;){
			if(x[i]>y[j]){//������������ڹ����������� 
				num++;
				i++;
				j++;
			}
			else if(x[i]<y[j]){//�������������ڹ�����������
			    num--;
				i++;
				b--;//������������͹���������� 
			}
			else{//����������͹�����������ͬ�� 
				if(x[a]>y[b]){//����������ڹ��������� 
					num++;
					a--;
					b--;
				}
				else{//�����������ڻ�����ڹ���������
				    if(x[i]!=y[b])num--;
					i++;
					b--;
				}
			}
		}
		cout<<num*200<<endl;
	}
	return 0;
}