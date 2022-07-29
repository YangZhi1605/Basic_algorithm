#include <iostream> 
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
const int N = 510;

int n,m;//图中的点和边
int g[N][N];//邻接矩阵 
int dist[N];//从1号点到图中每一个点的距离
bool st[N];//表示每一个点的最短路径是不是已经确定了


void dijkstra(){
	//处理距离数组dist,先把所有的点置为正无穷 
	memset(dist,0x3f,sizeof dist);
	//因为题目中是从1号点开始走，就表示为
	dist[1] = 0;
	
	//n-1次循环 这里为什么n-1次循环，是有点迷糊的 
	for(int i = 0;i < n-1;i++){
		int t = -1;//t记录的是全局最小值
		//处理n个点，目的是更新出当前循环下的全局最小
		for(int j = 1;j <= n;j++) {
			//对于每个点有三种处理情况
			//1、当前的j没有被st数组记录过状态，同时 
			//2.1、要么用与记录最小值的t仍然是-1，直接没有被动过
			//2.2、要么记录最小值的t已经被赋值过了，但是现在出现了一个更短的距离路径
			if(!st[j] && (t == -1 || dist[t] > dist[j]) ){
				t = j;
			}
		}
		
		//把这个点j 放到表示已经找到最短路径的数组st中
		st[t] = true;
		//使用全局最小
		//用目前的最短路径de "点t" 去更新出其他1~n能获得的最短路径 
		for(int k = 1; k <= n;k++ ){
			dist[k] = min(dist[k],dist[t]+g[t][k]);
		}
	}
}

int main() {
	
	//输入点和边
	cin >> n >> m;
	//初始化邻接矩阵
	memset(g,0x3f,sizeof g) ;
	//建立m条边
	while(m--) {
		int a,b,c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b],c);
	}
	//调用dijkstra
	dijkstra();
	
	if(dist[n] == 0x3f3f3f3f) puts("-1");
	else cout << dist[n];
	
	
	
	return 0;
}

 

