#include<iostream>
#include<stack>
#include<iomanip>
using namespace std;
int main(){
	double a;
	char b;
	while(cin>>a){
		b=getchar();
		if(a==0&&b=='\n')break;
		stack<double>s;
		stack<char>t;
		s.push(a);
		while(b!='\n'){
			b=getchar();
			cin>>a;
			if(t.size()==0){t.push(b),s.push(a);}
			else{
				char top=t.top();
				if((top=='+'||top=='-')&&(b=='*'||b=='/')){
					double sum;
					if(b=='*')sum=s.top()*a;
					else sum=s.top()/a;
					s.pop();
					s.push(sum);
				}
				else{
					double sum=s.top();
					s.pop();
					if(top=='*')sum=s.top()*sum;
					else if(top=='/')sum=s.top()/sum;
					else if(top=='+')sum=s.top()+sum;
					else sum=s.top()-sum;
					s.pop();
					s.push(sum);
					s.push(a);
					t.pop();
					t.push(b);
				}
			}
			b=getchar();
		}
		char top=t.top();
		double sum=s.top();
		s.pop();
		if(top=='*')sum=s.top()*sum;
		else if(top=='/')sum=s.top()/sum;
		else if(top=='+')sum=s.top()+sum;
		else sum=s.top()-sum;
		cout<<fixed<<setprecision(2)<<sum<<endl;
	}
	return 0;
}