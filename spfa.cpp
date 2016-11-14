void spfa(int s){//s表示起始点. 
	int dist[MAX];
	bool biaoji[MAX];
	queue<int>enqueue;
	for(int i=1;i<=n;++i){
		dist[i]=INF;//源点到i点的距离. 
		biaoji[i]=false;//初始化所有的点都没有入队. 
	}
	dist[s]=0;
	enqueue.push(s);//起点入队. 
	biaoji[s]=true;
	while(!enqueue.empty()){
		int point=enqueue.front();
		enqueue.pop();
		biaoji[point]=false;
		for(int i=1;i<=n;++i){//开始松弛操作,寻找经过point点是到起点距离更近的点i 
			if(dist[i]>dist[point]+road[point][i]){ 
				dist[i]=dist[point]+road[point][i];
				if(!biaoji[i]){//找到i点并且i点未在队里,则入队. 
					enqueue.push(i);
					biaoji[i]=true;
				}
			}
		}
	}
}
//邻接表
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