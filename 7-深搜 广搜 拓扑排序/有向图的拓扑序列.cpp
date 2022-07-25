#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n,m;
int h[N],e[N],ne[N],idx;
int q[N],cnt[N];

void add(int a,int b){
	e[idx]  = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}


bool tsort(){
	int hh = 0;//队头
	int tt = -1;//队尾
	
	//把入度为0的点全部入队
	//注意题目中给的范围是1 到 n 
	for(int i = 1;i <= n;i++) 
		if(!cnt[i]) q[++ tt] = i;
		
	while(hh <= tt){
		//取队头
		int t = q[hh++] ;
		//将取到的队头拿来拓展
		for(int i = h[t];i != -1;i = ne[i]) {
			int j = e[i];
			cnt[j] --;//剥离结点j的一个入度 
			if(!cnt[j]) q[++ tt] = j; //如果剥离之后，入度为0了，表示是一个可以用的拓扑序，放到队列q中 
		}
	}
	
	return tt == n-1;//当尾指针迭代到最后一个数据的位置， 表示输入的数据形成了一个拓扑序列 
}

int main(){
	cin >> n >> m;
	
	memset(h,-1,sizeof h);
	
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		//表示从点a到点b的有向边 
		add(a,b);
		//因为点b是接在点a后面的，所有b的入度需要增加 
		cnt[b] ++;
	}
	if(tsort()) {
		//这里是输出n个点的拓扑排序 
		for(int i = 0;i < n;i++) cout << q[i] <<' ';
		puts("");
	}else puts("-1");
	
	return 0;
}
