#include<iostream>
using namespace std;

struct zuchuan{
	int h,m;
}z[102];

struct huanchuan{
	int h,m;
}h[102];

int main(){
	int n,a,b;
	char s;
	while(1){	
	    int sum=0;
	    int num=0;
	    for(int i=0;i<102;++i){
    		z[i].h=z[i].m=h[i].h=h[i].m=-1;
    	}
		while(scanf("%d",&n)!=EOF){
			getchar();
			if(n==-1)exit(0);
			scanf(" %c %d:%d",&s,&a,&b);
			if(n==0)break;
		    if(s=='S'){
			    z[n].h=a;
				z[n].m=b;;
		    }
			if(s=='E'){
				h[n].h=a;
				h[n].m=b;
				if(z[n].h!=-1){
					sum+=(h[n].h-z[n].h)*60+(h[n].m-z[n].m);
					z[n].h=z[n].m=h[n].h=h[n].m=-1;
					num++;
				}
			}
		}
		if(num)
		printf("%d %d\n",num,int((((sum*1.0/num)+0.5)*2)/2));
		else printf("0 0\n");
	}
}