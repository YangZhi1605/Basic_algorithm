#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10,M = 2e5 + 10;
int n,m;
int h[N],e[M],ne[M],idx; //注意，因为是无向图，那么存储指针和结点指的数据，应该开结点数的两倍 
int color[N];//表示每个点的颜色，-1表示未染色， 0表示白色，1表示黑色

/*
主要是搜索，打标记，同时用传入的结点，再搜索，判断是否染色矛盾 
*/


void add(int a,int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}


//参数u存储当前的结点。c存储当前的颜色
bool dfs(int u,int c){
	color[u] = c;//将传入的点染色
	
	//遍历邻接表
	for(int i = h[u];i != -1;i = ne[i]) {
		int j = e[i];
		//如果当前点没有染过色 注意是在当前点没有被染色过的时候，才进去搜索 
		if(color[j] == -1) {
			//用!c切换传入进去染色的标记c 
			if(!dfs(j,!c)) return false;
			//如果当前的这个点已经被染色过了，但是和我传入参数染的结点颜色相同，就矛盾了，返回flase 
		}
		//如果被染过色，需要判断染色是否矛盾 
		else if(color[j] == c) return false;
	}
	
	return true;
}


int main() {
	cin >> n >> m;
	//初始化邻接表
	memset(h,-1,sizeof h) ;
	
	//建图
	while(m--){
		int a,b;
		cin >> a >> b;
		//无向图 
		add(a,b);
		add(b,a);
	} 
	
	//染色 用flag来控制染色是否出现矛盾
	bool flag = true;
	memset(color,-1,sizeof color) ;
	
	for(int i = 1; i <= n;i++) {
		//如果当前这个点没有染过色  注意这个没有被染色的条件 
		if(color[i] ==  -1){
			//在dfs的途中，返回flase就是表示矛盾了
			if(!dfs(i,0)){
				flag = false;//标记
				break; 
			}
		}
	}
	
	if(flag) puts("Yes");//染色顺利，没有矛盾发生，是二分图
	else puts("No") ;
	 
	return 0;
}
