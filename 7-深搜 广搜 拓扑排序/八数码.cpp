#include <iostream> 
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
string end_ans = "12345678x" ;//定义目标状态
queue<string> q;//定义队列
unordered_map<string,int> d;

int bfs(string start){
	//初始化队列和dist数组 
	q.push(start);
	d[start] = 0;
	int dx[] = {1,-1,0,0};//下上右左 
	int dy[] = {0,0,1,-1};
	
	while(q.size()) {
		//取对头
		auto t = q.front();
		q.pop();
		
		//记录到当前状态的距离，如果是最终状态，就返回距离
		int distance = d[t];
		if(t == end_ans) return distance;
		//查询x在字符串中的下标，然后转换为矩阵中的坐标
		int k = t.find('x'); 
		int x = k/3,y = k%3;
		
		//探索4个方向
		for(int i = 0;i < 4;i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			//当前坐标没有越界
			if(a>=0 && a < 3 && b >=0 && b < 3) {
				//转换x
				swap(t[k],t[a*3+b]) ;
				//如果当前的状态是第一次遍历，记录距离，入队
				if(!d.count(t)) {
					d[t] = distance + 1;
					q.push(t);
				}
				//还原状态
				swap(t[k],t[a*3+b]) ;
			}
		}
	}
	//无法转换到目标状态，返回-1
	return -1; 
	
}

int main(){
	string c,start;
	//输入起始状态
	for(int i = 0;i < 9;i++) {
		cin >> c;
		start += c;
	}
	
	cout << bfs(start) <<endl;
	
	return 0;
}
