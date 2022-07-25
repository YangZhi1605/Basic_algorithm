#include <iostream> 
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int n,m;
int h[N],e[N],ne[N],idx;
int q[N],d[N];

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}


int bfs(){
	int hh = 0;
	int tt = 0;
	memset(d,-1,sizeof d); //注意这里初始化的距离数组d 
	//入队 
	q[0] = 1;
	//标记
	d[1] = 0;
	//当队列不空的时候 
	while(hh <= tt) {
		//取队头 
		int t = q[hh++];
		//拓展队头
		for(int i  =h[t];i != -1;i = ne[i]) {
			int j = e[i];
			if(d[j] == -1){ //注意这里是和初始化值-1比较，仍然是-1表示没有探索过 
				//标记这点是从队头走过来的 
				d[j] = d[t] + 1;
				//将拓展出来的点入队 
				q[++tt] = j;
			}
		}
	}
	
	return d[n];	
}




int main(){
	cin >> n >>m;
	
	memset(h,-1,sizeof h);//这里初始化的是邻接表 
	
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >>b;
		add(a,b);
	}
	
	cout << bfs()<<endl;
	return 0;
	
}
