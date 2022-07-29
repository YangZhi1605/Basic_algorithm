#include <bits/stdc++.h> 

 
using namespace std;
const int N =210,INF = 1e9;
int n,m,Q;
int d[N][N];

//其实也看的出来，当想要查询某两个点之间的最短距离的时候，使用它
// 
void floyd(){
	//外层的k是因为k行，内层就是常规的dijkstra更新最短路径的思想或者说是，邻接矩阵更新，但不是dijkstra的玩法 
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);//这里循环放置的顺序，也是迷惑点 
		}
	}
}

int main(){
	cin >> n >> m >> Q;
	
	//初始化矩阵 -- 注意这里没有初始化什么矩阵地图，直接初始化的距离数组了 
	//这里是矩阵，那么边长都是n 
	for(int i = 1; i <= n;i++) {
		for(int j = 1;j <= n;j++){
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	
	//创建图
	while(m--) {
		int a,b,c;
		cin >>a >> b>> c;
		d[a][b] = min(d[a][b],c);//这里也是直接统计的距离了 
	}
	
	floyd();
	
	while(Q--){
		int a,b;
		cin >> a >> b;
		if(d[a][b] > INF/2) puts("impossible");
		else cout <<d[a][b];
	}
	
	return 0;
	return 0;
}

