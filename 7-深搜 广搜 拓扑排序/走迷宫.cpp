#include <iostream> 
#include <queue> 
#include <vector>
#include <cstring>
#include <algorithm>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 110;
int g[N][N],d[N][N]; //g是存放01矩阵的数组，d是存放距离的数组 
PII pre_pos[N][N]; //当需要输出的路径的时候，使用这个数组 
int n,m;
queue<PII> q;
vector<PII> ans;

int bfs(){
	//初始化距离数组 
	memset(d,-1,sizeof d); 
	d[0][0] = 0;//表示(0,0) 这个点已经走过了
	q.push({0,0}) ;
	
	int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
	
	//在队列不为空的时候进行取队头，拓展队头的
	while(q.size()) {
		//取队头
		auto hh = q.front();
		//去除队头
		q.pop();
		
		//拓展本题题目背景中的四个方向
		for(int i = 0;i < 4;i++) {
			int xx = hh.x + dx[i];
			int yy = hh.y + dy[i];
			
			//如果拓展处理的坐标合法，不是障碍物，而且没有被拓展过,就探索当前的点 
			if(xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == 0&&d[xx][yy] == -1){
				d[xx][yy] = d[hh.x][hh.y] + 1;//探索当前位置 				
				pre_pos[xx][yy] = hh;//当需要输出路径的时候，记录当前这个点是从哪儿转移过来的 
				q.push({xx,yy}); //将探索结果入队 
			}
		}
	}
		
		//输出路径，只是是倒着的，可以放到一个vector<PII> 中，reverse一下，再输出 
		int edx = n-1,edy = m-1;
		while(edx || edy){
			ans.push_back({edx,edy});
			cout << edx <<' '<< edy << endl;
			auto pre = pre_pos[edx][edy];//取出pre_pos数组中存储的，根据当前位置，推算出上一个点的位置
			//更新位置，继续迭代 
			edx = pre.x;
			edy = pre.y; 
		}
		//输出探索到终点的最小层数，或者说步数
		return d[n-1][m-1]; 
}

int main(){
	cin >> n >> m;
	//输入01矩阵 
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) cin >> g[i][j];
	} 
	
	cout << bfs() << endl;
	
	reverse(ans.begin(),ans.end());
	for(auto it:ans){
		cout << it.x <<' '<< it.y<<endl;
	}
	
	return 0;
}
