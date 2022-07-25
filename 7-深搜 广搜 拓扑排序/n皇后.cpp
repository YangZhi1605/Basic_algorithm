#include <iostream>

using namespace std;
const int N = 10;
int n;
char g[N][N];
bool col[N],dg[N],udg[N];

void dfs(int u){
	if(u == n){//找到一组方案了 
		for(int i = 0;i < n;i++) puts(g[i]);
		cout <<endl;
		return;
	} 
	
	//搜索最重要的是确实搜索方式
	//这里是n*n的方阵
	//假如传入的参数u是确定当前枚举的行数，那么现在枚举的就是列
	//由行+列确定方格坐标，那么一元线性方程组就可以拿捏出来了。y  = (+-)x + b 
	//
	for(int i = 0;i < n;i++){
		if(!col[i] && !dg[u+i] && !udg[-u+i+n]) {
			g[u][i] = 'Q' ;//标记u行i列可以放
			col[i] = dg[u+i] = udg[-u+i+n] = true;
			dfs(u+1);
			//还原现场 
			col[i] = dg[u+i] = udg[-u+i+n] = false;
			g[u][i] = '.';
		}
	}
}


int main(){
	cin >> n;
	//初始化地图 
	for(int i = 0; i < n;i++)
		for(int j = 0; j < n;j++) g[i][j] = '.';
	
	dfs(0);
	
	return 0;
}

