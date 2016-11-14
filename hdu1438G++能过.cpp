#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	__int64 lock[32]={0},a[32]={0},b[32]={0},num_1_4[32]={0};
	lock[3]=8;
	num_1_4[3]=4;
	cout<<"N=2: "<<lock[2]<<endl;
	cout<<"N=3: "<<lock[3]<<endl;
	for(int i=4;i<32;++i)
	{
		a[i]=(__int64)pow(2,i)-4;
		b[i]=(__int64)pow(4,i-2)*2-(__int64)pow(2,i-2)*2-num_1_4[i-1];
		num_1_4[i]=lock[i-1]*2+b[i];
		lock[i]=lock[i-1]*4+a[i]+b[i];
		cout<<"N="<<i<<": "<<lock[i]<<endl;
	}
	return 0;
}