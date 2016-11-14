/*
采用线段树,对线段区间进行0,1标记表示该区间是否包含在s内 

U T S ← S ∪ T 即将[l,r]标记为1 
I T S ← S ∩ T 即将-oo~l和r~+oo标记为0,因为是并集,所以并集后的集合s一定在[l,r]内,则在l,r内的集合被标记是什么状态就是什么状态(表示是否属于s),[l,r]外的集合不属于s所以标记为0 
D T S ← S - T  即将[l,r]标记为0,则在[l,r]内被s包含的集合也会标记为0表示不再属于s 
C T S ← T - S  即先将-oo~l,r~+oo标记为0,这部分不属于[l,r]则一定不属于s,然后将[l,r]的标记0/1互换,因为属于s的不再属于s,不属于s的将属于s 
S T S ← S ⊕ T  即属于s的不变,[l,r]中不属于s的(区间)0标记为1,属于s的(区间)1标记为0,所以[l,r]的标记0/1互换 

最后对区间l,r标记时标记将l*2,r*2标记,如果是闭区间则对l*2+1,或r*2-1进行标记,则输出的时候只需判断奇偶就能判断开闭区间 
是否覆盖0,1是否转换0,1的0,1转换都可以用异或去转换 
*/
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

const int MAX=65535*2+2;
int cover[MAX<<2],Xor[MAX<<2];//cover表示区间的0,1状态,Xor表示该区间转换的状态 
int mark[MAX];

void UpXor(int n){
	if(cover[n] != -1)cover[n]^=1;//表示整个区间可以同时转换
	else Xor[n]^=1; 
}

void Upchild(int n){
	if(cover[n] != -1){//表示该节点标记了但是孩子未标记 
		cover[n<<1]=cover[n<<1|1]=cover[n];
		Xor[n<<1]=Xor[n<<1|1]=0;//区间全被覆盖则原来的转换无任何作用了 
		cover[n]=-1;
	}
	if(Xor[n]){//表示该点转换了但是孩子未转换 
		UpXor(n<<1);
		UpXor(n<<1|1);
		Xor[n]=0;
	}
}

void Update(int L,int R,char ch,int n,int left,int right){
	if(L<=left && right<=R){
		if(ch == 'U')cover[n]=1,Xor[n]=0;
		if(ch == 'D')cover[n]=Xor[n]=0;
		if(ch == 'S' || ch == 'C')UpXor(n);
		return;
	}
	Upchild(n);//是否该节点标记或转换过而孩子未标记或转换 
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,ch,n<<1,left,mid);
	else if(ch == 'I' || ch == 'C')cover[n<<1]=Xor[n<<1]=0;//将-oo~l中的-oo~mid标记为0
	if(R>mid)Update(L,R,ch,n<<1|1,mid+1,right);
	else if(ch == 'I' || ch == 'C')cover[n<<1|1]=Xor[n<<1|1]=0;//将r~+oo中的mid+1~+oo标记为0 
}

void Query(int n,int left,int right){
	if(cover[n] == 1){
		for(int i=left;i<=right;++i)mark[i]=true;
		return;
	}
	if(cover[n] == 0)return;
	if(left == right)return;
	Upchild(n);
	int mid=left+right>>1;
	Query(n<<1,left,mid);
	Query(n<<1|1,mid+1,right);
}

int main(){
	int l,r;
	char a,b,c;
	while(scanf("%c %c%d,%d%c",&a,&b,&l,&r,&c)!=EOF){
		l<<=1,r<<=1;
		if(b == '(')++l;
		if(c == ')')--r;
		if(l>r){//比如输入区间为I (1,1)或C (1,1) 
			if(a == 'I' || a == 'C')cover[1]=Xor[1]=0;//将-oo~l,r~+oo标记为0 
		}else Update(l,r,a,1,0,MAX);
		getchar();
	}
	bool flag=false;
	int s=-1,t=-1;
	Query(1,0,MAX);
	for(int i=0;i<MAX;++i){
		if(mark[i])s=(s==-1?i:s),t=i;
		else if(s != -1){
			if(flag)printf(" ");
			flag=true;
			printf("%c%d,%d%c",s&1?'(':'[',s>>1,(t+1)>>1,t&1?')':']');
			s=-1;
		}
	}
	if(!flag)printf("empty set");
	printf("\n");
	return 0;
}