#include <iostream> 
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
int n,m;
//稀疏图就得考虑邻接表了
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}


void dijkstra(){
	//初始化距离数组
	memset(dist,0x3f,sizeof dist) ;
	dist[1] = 0;
	
	//难点应该是背怎么创建小根堆，因为其他和宽搜差不多
	
	/*
	
	Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，
	但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式
	priority_queue<Type, Container, Functional>
	*/ 
	
	//使用STL容器建立小根堆
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	//对当前数对而言，first属性是距离，second属性是结点编号 
	heap.push({0,1}) ; 
	
	//当队列不为空的时候，进行操作
	while(heap.size()) {
		//取出当前的距离最小值，想要最小值，对于小根堆而言，就是堆顶
		auto t = heap.top();
		heap.pop();
		
		int dis = t.first;
		int var = t.second;
		
		//如果当前染探索的结点已经被放到st数组统计过最短路径了，那么直接跳过 
		if(st[var]) continue;
		//否则统计当前结点
		st[var]  = true;
		
		//用当前统计的这个结点，来探索其他结点
		for(int i = h[var];i != -1;i = ne[i]) {
			int node = e[i];
			
			//比较直接走到j的距离和先走到结点var，在根据w[i]的距离从i走到j的总和，谁到，保留最小的 
			if(dist[node] > dis + w[i]){
				dist[node] = dis + w[i];
				//将更新出来的数据插入到堆中
				heap.push({dist[node],node}) ;
				//在队列中，循环这个过程 
			}
		} 
	}
}

int main(){
	scanf("%d %d",&n,&m);
	//初始化邻接表
	memset(h,-1,sizeof h) ;
	
	while(m--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c) ;
	}
	
	dijkstra();
	
	if(dist[n] == 0x3f3f3f3f) puts("-1");
	else printf("%d",dist[n]);
	
	return 0;
}

