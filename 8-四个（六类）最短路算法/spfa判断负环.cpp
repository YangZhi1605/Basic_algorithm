#include <bits/stdc++.h> 

using namespace std;
const int N = 1e4 + 10;
int n,m;
int h[N],e[N],ne[N],w[N],idx;
// dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
int dist[N],cnt[N];
// 存储每个点是否在队列中
bool st[N];

void add(int a,int b,int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a]; //注意这里统计的是idx这个指针现在指向的位置，刚才测试时错写成ne[b] = h[a]了 
	h[a] = idx ++;
}

bool spfa(){
	// 不需要初始化dist数组
    // 原理：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，
	//由抽屉原理一定有两个点相同，所以存在环。
	queue<int> q;
	
	//把现在的1到n号点都当到队列中，并标记已经入队 
	for(int i = 1;i <= n;i++){
		q.push(i);
		st[i] = true;
	}
	while(q.size()){
		auto t = q.front();
		q.pop();
		st[t] = false;
		
		for(int i = h[t];i != -1;i  = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t]+w[i]){
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t]+1;
				
				//抽屉原理 --> 用于解决环的问题 
				/*
				抽屉原理的一般含义为："如果每个抽屉代表一个集合，每一个苹果就可以代表一个元素，
				假如有n+1个元素放到n个集合中去，其中必定有一个集合里至少有两个元素。
				*/ 
				if(cnt[j] >= n) return true;
				
				//同时处理，如果这个j 没有在队列中，就加入队列
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
	
		}
	}
	
	return false;
	
	
}

int main(){
	cin >>n >>m;
	memset(h,-1,sizeof h);
	
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
	}
	if(spfa()) puts("Yes");
	else puts("No");
	
	return 0;
}


