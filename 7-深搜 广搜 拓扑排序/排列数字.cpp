#include <iostream> 

using namespace std;
int n;
const int N = 10;
int path[N];//存放当前dfs进去后，可以存放的数值
bool st[N];//记录当前这个位置的状态，是否被用过

void dfs(int u) {
	//如果u已经递归到n这层了，是属于dfs完工了，那么就输出探索中存储的位置信息 
	if(u == n ){
		for(int i = 0; i < n;i++) cout << path[i] <<' ';
		cout << endl;
		return;
	}
	
	//没有到边界，进行常规的探索1 ~ 3的数字是否能够存储 
	//这里枚举的是需要排列的数字 
	for(int i = 1;i <= n;i++) {
		
		if(!st[i]){ //判断数字有没有用过 
			path[u] = i;//记录没有用过的数字，放到path数组中，作为当前探索的结果 
			st[i] = true;//标记已经用过的数字 
			
			//递归到下一层
			dfs(u+1) ;
			//递归结束了，也就是回溯回来了，需要恢复现场 
			st[i] = false;
		}
	}
}

int main(){
	cin >> n;
	dfs(0);
	return 0;
}
