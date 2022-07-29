#include <bits/stdc++.h> 

using namespace std;
int n,m;
const int N = 1e5 + 10;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}


void spfa(){
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	//创建一个队列，并将已经确认最短路径的1号点加入队列 
	queue<int> q;
	q.push(1);
	//标记1号点 
	st[1] = true;
	
	//老规矩，当队列不空的时候进行
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		//标记不在队列中的点
		st[t] = false;
		
		for(int i = h[t]; i != -1;i = ne[i]) {
			int j =e[i];
			if(dist[j] > dist[t] + w[i]){
				//找到更小的最短路，更新1号点到j的距离 
				dist[j] = dist[t] + w[i];
				//这里加的这个if，有点迷糊
				//理解是，上面确实是找到最短路了，但是需要判断之前是不是已经找过了
				//假如没有，才能入队，并标记 
				if(!st[j]){
					q.push(j);//入队
					st[j] = true;//标记 
				}
			}
		}
	}
	
}

int main(){
	scanf("%d %d",&n,&m);
	memset(h,-1,sizeof h);
	
	while(m--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
	}
	spfa();
	if(dist[n] == 0x3f3f3f3f) puts("impossible");
	else cout << dist[n];
	
	return 0;
}
