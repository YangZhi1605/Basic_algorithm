#include <bits/stdc++.h>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];//dist[t]表示当前这个点，和已经连好的最小生成树中，距离最近的点
bool st[N];

int prim(){
	//初始化距离数组 
	memset(dist,0x3f,sizeof dist);
	//sum中存放的是最小生成树的树边权重之和
	int sum = 0;
	
	for(int i = 0;i < n;i++) {
		int t = -1; //记录全局最小的结点编号
		
		//注意下面三层结构和dijkstra一样，都是彼此独立的结构，没有嵌套
		//都是必须的功能模块 
		
		//寻找满足最短路径的t 
		for(int j = 1; j <= n;j++) {
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t= j;
		}
		//判断t是否符合要求 
		//如果当前的点已经不是第一个点，以及距离最小的点为正无穷 
		//则说明当前距离最近的点，确实都是正无穷了，即当前的图，不连通 
		if(i && dist[t] == INF) return INF;
		if(i) sum += dist[t];	
		
		//用t去更新出其他点
		//注意这里是g[t][j]
		//对于dijskstra而言，是dist[t] + g[t][j]
		//因为对于dijkstra而言，dist数组维护的是1号点到t的最短路径
		//最小生成树中维护的是j到现在集合中其他点的最短路 
		for(int j = 1;j <= n;j++) {	
			dist[j] = min(dist[j],g[t][j]);
		}
			
		st[t] = true;//标记t已经用过了 
		
	}
	
	return sum; 
	
}

int main(){
	cin >> n >> m;
	memset(g,0x3f,sizeof g);
	
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		//因为是无向图，所以需要从a到b的，以及从b到a的
		g[a][b] = g[b][a]  = min(g[a][b],c);
	}
	
	int ans = prim();
	if(ans == INF) puts("impossible");
	else cout << ans << endl;
	
	return 0;
}
