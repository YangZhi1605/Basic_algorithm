#include <bits/stdc++.h>

using namespace std;
const int N =  2e5 + 10;
int n,m;
int fa[N];//维护并查集的数组
//cnt存储当前加入了多少条边。ans 存储的是最小生成树中所有边的权重和 
int cnt,ans; 
//kruskal算法可用不用邻接表存储，只要把结点以及点到点直接边距存储下来就好
//那么可以使用最简单的结构体了，只是要重新确定比较方式，待会需要排序


/*
kruskal算法的核心是按照连通块来理解 
连通块的处理，那么就可以使用并查集了 
*/
struct Edge{
	int a,b,w;
}edges[N];
 
bool cmp(Edge &a,Edge &b){
	
	return a.w < b.w; 
}

int find(int x){
	if(fa[x] != x) fa[x] =find(fa[x]);
	return fa[x];
}

void kruskal(){
	//对存放数据的结构体按照权重从小到大重新排序
	sort(edges,edges+m,cmp) ;
	//初始化并查集 注意是对点进行并查集的初始化 
	for(int i = 1;i <= n;i++)  fa[i] = i;
	
	//从小到大枚举所有边 
	for(int i = 0; i < m;i++) {
		int a = edges[i].a;
		int b = edges[i].b;
		int c = edges[i].w;
		
		//找到a和b的祖宗结点
		a = find(a);
		b = find(b) ;
		
		//如果a 和 b不在一个连通块上
		if(a != b) {
			//将a连在b上
			fa[a] = b;
			//统计现在的权重和 
			ans += c;
			//统计参与最小生成树的结点数目 
			cnt ++; 
		}
	}
}


int main(){
	//输入 
	cin >> n >> m;
	//建图
	
	for(int i = 0;i < m;i++){
		int a,b,w;
		cin >> a >>b >> w;
		edges[i] = {a,b,w};
	}
	//调用方法 
	kruskal();
	
	//输出
	//n个点，只能刚好有n-1边才能生成最小生成树 
	if(cnt < n-1) puts("impossible");
	else cout << ans <<endl;
	
	return 0;
}

