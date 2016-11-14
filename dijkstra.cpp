void dijkstra(int s){
	bool biaoji[MAX]={false};
	int dist[MAX];
	for(int i=1;i<=n;++i){
		dist[i]=road[s][i];
	}
	biaoji[s]=true;
	dist[s]=0;
	for(int i=0;i<n;++i){//寻找n次 
		int point=s;
		int min_road=INF;//初始化最短距离 
		for(int j=1;j<=n;++j){
			if(!biaoji[j]&&min_road>dist[j]){//寻找非起点集合的点到起点的最短距离. 
				point=j;
				min_road=dist[j];
			}
		}
		if(min_road==INF)return; 
		if(point==end)return//找到终点,s->end已是最短了 
		biaoji[point]=true;
		for(int i=1;i<=n;++i){//通过找到的点更新点到起点的最短距离. 
			dist[i]=min(dist[i],dist[point]+road[point][i]);
		}
	}
	return;
}
精简之后的：
void dijkstra(int s,int t){
	for(int i=1;i<=n;++i)mark[i]=false;
	mark[s]=true;
	while(1){
		int point=t;
		for(int i=1;i<=n;++i){
			if(!mark[i] && dist[s][i]<dist[s][point])point=i;
		}
		if(point == t)return;
		mark[point]=true;
		for(int i=1;i<=n;++i){
			if(!mark[i])dist[s][i]=min(dist[s][i],dist[s][point]+dist[point][i]);
		}
	}
} 