#include<iostream>
#include<cstring>
using namespace std;
struct point{
	char number[10];
	char name[10];
	int mark;
}student[100002];
bool cmp1(point a,point b){
	return strcmp(a.number,b.number)<0?true:false;
}
bool cmp2(point a,point b){
	if(strcmp(a.name,b.name))return strcmp(a.name,b.name)<0?true:false;
	return strcmp(a.number,b.number)<0?true:false;
}
bool cmp3(point a,point b){
	if(a.mark!=b.mark)return a.mark<b.mark;
	return strcmp(a.number,b.number)<0?true:false;
}
int main(){
	int n,m,num=0;
	while(scanf("%d%d",&n,&m),n){
		for(int i=0;i<n;++i){
			scanf("%s%s%d",student[i].number,student[i].name,&student[i].mark);
		}
		if(m==1){
			sort(student,student+n,cmp1);
		}
		else if(m==2){
			sort(student,student+n,cmp2);
		}
		else if(m==3){
			sort(student,student+n,cmp3);
		}
		cout<<"Case "<<++num<<':'<<endl;
		for(int i=0;i<n;++i){
			printf("%s %s %d\n",student[i].number,student[i].name,student[i].mark);
		}
	}
	return 0;
}