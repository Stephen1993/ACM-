void spfa(int s){//s��ʾ��ʼ��. 
	int dist[MAX];
	bool biaoji[MAX];
	queue<int>enqueue;
	for(int i=1;i<=n;++i){
		dist[i]=INF;//Դ�㵽i��ľ���. 
		biaoji[i]=false;//��ʼ�����еĵ㶼û�����. 
	}
	dist[s]=0;
	enqueue.push(s);//������. 
	biaoji[s]=true;
	while(!enqueue.empty()){
		int point=enqueue.front();
		enqueue.pop();
		biaoji[point]=false;
		for(int i=1;i<=n;++i){//��ʼ�ɳڲ���,Ѱ�Ҿ���point���ǵ�����������ĵ�i 
			if(dist[i]>dist[point]+road[point][i]){ 
				dist[i]=dist[point]+road[point][i];
				if(!biaoji[i]){//�ҵ�i�㲢��i��δ�ڶ���,�����. 
					enqueue.push(i);
					biaoji[i]=true;
				}
			}
		}
	}
}
//�ڽӱ�
int size,head[111];
struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX];

inline void Init(int num){
	memset(head,-1,sizeof(int)*(num+2));
	size=0;
}

inline void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}
for(int i=head[point];i != -1;i=edge[i].next)