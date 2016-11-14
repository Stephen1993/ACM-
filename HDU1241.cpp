#include<iostream>
using namespace std;
char s[101][101];
int m,n;
int dir[8][2]={0,-1,0,1,-1,0,1,0,1,1,-1,-1,-1,1,1,-1};
void sousuo(int x,int y)
{
	s[x][y]='*';
	if(x>m-1||y>n-1||x<0||y<0)return;
	for(int i=0;i<8;++i)
	 {
 		if(s[x+dir[i][0]][y+dir[i][1]]=='@')sousuo(x+dir[i][0],y+dir[i][1]);
 	 }
 	 return;
}
int main()
{
	while(cin>>m>>n,m&&n)
	{
		getchar();
		int sum=0;
		for(int i=0;i<m;++i)
		  scanf("%s",s[i]);
	    for(int i=0;i<m;++i)
	     for(int j=0;j<n;++j)
	      {
      	     if(s[i][j]=='@')
			   {
   				  sousuo(i,j);
   				  sum++;
   			   }	
      	  }
   	  cout<<sum<<endl;
	}
	return 0;
}