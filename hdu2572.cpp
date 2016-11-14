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

const int MAX=100+10;
char a[MAX],b[15],c[15];
int s,t,len;

bool Strcmp(int i,int j,int x,int y){
    while(i<=j){
        if(a[x]<a[i])return true;
        if(a[x]>a[i])return false;
        ++i,++x;
    }
    return false;
}

void PP(int B,int lenb,int C,int lenc){
	if(B<C && B+lenb<=C+lenc){
		if(C+lenc-B<len)s=B,t=C+lenc-1,len=C+lenc-B;
		else if(C+lenc-B == len && Strcmp(s,t,B,C+lenc-1))s=B,t=C+lenc-1;
	}
	if(B>=C && B+lenb<=C+lenc){
		if(lenc<len)s=C,t=C+lenc-1,len=lenc;
		else if(lenc == len && Strcmp(s,t,C,C+lenc-1))s=C,t=C+lenc-1;
	}
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        int lena=strlen(a),lenb=strlen(b),lenc=strlen(c);
		int B=-1,C=-1,flagb=0,flagc=0;//B,C�ֱ������һ��a���г���b,c����ʼλ�� 
        s=-1,t=-1,len=INF;//s,t��ʾ��̰����ִ�b,c����ʼλ�ú���ֹλ�� 
        for(int i=0;i<lena;++i){
            flagb=flagc=0;
			if(a[i] == b[0]){
            	int k=0;
            	while(k<lenb && a[i+k] == b[k])++k;
            	if(k == lenb){
	            	flagb=1;
	            	if(C != -1)PP(C,lenc,i,lenb);//B���µĳ���λ��,�ж��Ƿ���Ը��¸��̵��ִ� 
	            }
            }
            if(a[i] == c[0]){
            	int k=0;
            	while(k<lenc && a[i+k] == c[k])++k;
            	if(k == lenc){
	            	flagc=1;
	            	if(B != -1)PP(B,lenb,i,lenc);//C���µĳ���λ��,�ж��Ƿ���Ը��¸��̵��ִ� 
	            }
            }
            if(flagb){
            	if(C != -1)PP(i,lenb,C,lenc);//�ñ��θ��µ�Bλ��ȥ���¸����ִ� 
            	if(flagc)PP(i,lenb,i,lenc);//�ñ��θ��µ�B��Cȥ���¸����ִ� 
            }
            if(flagc){
            	if(B != -1)PP(i,lenc,B,lenb);//�ñ��θ��µ�Cλ��ȥ���¸����ִ� 
            	if(flagb)PP(i,lenc,i,lenb);//�ñ��θ��µ�C��Bȥ���¸����ִ� 
            }
            if(flagb)B=i;//���³��ֵ�Bλ�� 
            if(flagc)C=i;//���³��ֵ�Cλ�� 
        }
        if(s != -1){
            for(int i=s;i<=t;++i)cout<<a[i];
            cout<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}