 #include<iostream>
 #include<string.h>
 using namespace std;
 int main()
 {
 	int n;
 	char s[1050];
 	while(cin>>n)
 	{
 		int ans=0;;
	 	for(int i=0;i<n;++i)
	 	{
	 		cin>>s;
	 		int sum=1,num=0,m=0;
	 		for(int i=strlen(s)-2;s[i]!='(';i--)
	 		{
			  num=(s[i]-'0')*sum+num;
			  sum=sum*10;
		    }
		    for(int i=0;s[i]!='(';++i)
		    m=m*num+(s[i]-'0');
		    ans+=m;
	 	}
	 	cout<<ans<<endl;
    }
    return 0;
 }