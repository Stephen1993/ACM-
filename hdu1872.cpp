#include<iostream>
#include<cstdlib>
using namespace std;
struct noto{
	char name[60];
	int grade;
	int k;
}s[303],s1[303];
int cmp(const void*a,const void*b){
	struct noto *c=(noto *)a;
	struct noto *d=(noto *)b;
	if(c->grade!=d->grade)return d->grade-c->grade;
	return c->k-d->k;
}
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;++i){
			cin>>s[i].name>>s[i].grade;
			s[i].k=i;
		}
		for(int i=0;i<n;++i){
			cin>>s1[i].name>>s1[i].grade;
			s1[i].k=i;
		}
		qsort(s,n,sizeof(s[0]),cmp);
		bool flag=true,temp=true;
		for(int i=0;i<n;++i){
			if(s[i].grade!=s1[i].grade)temp=false;
			if(strcmp(s[i].name,s1[i].name))flag=false;
		}
		if(flag&&temp){
			cout<<"Right"<<endl;
		}
		else if(!flag&&temp){
			cout<<"Not Stable"<<endl;
			for(int i=0;i<n;++i){
				cout<<s[i].name<<' '<<s[i].grade<<endl;
			}
		}
		else{
			cout<<"Error"<<endl;
			for(int i=0;i<n;++i){
				cout<<s[i].name<<' '<<s[i].grade<<endl;
			}
		}
	}
	return 0;
}