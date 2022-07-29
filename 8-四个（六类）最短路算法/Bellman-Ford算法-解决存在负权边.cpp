#include <bits/stdc++.h> 

using namespace std;
const int N = 510,M =1e4 + 10;
int n,m,k;
int dist[N];
int backup[N];

//存放点和点到点之间的权重
struct Edge{
	int a,b,w;
}edges[M]; 

void bellman_ford(){
	//初始化距离数组为很大很大的值 
	memset(dist,0x3f,sizeof dist) ;
	dist[1] = 0;
	
	//题目要的是"最多经过 k 条边的最短距离"，现在就处理k条边
	for(int i = 0;i < k;i++) {
		//因为每次迭代进来处理一条边，就会影响原本的数据
		//所以操作备份数组 
		memcpy(backup,dist,sizeof dist);
		
		//由现在有的边，来推断相应的点们的最短路径
		for(int i = 0;i < m;i++){
			int a = edges[i].a;
			int b = edges[i].b;
			int w = edges[i].w;
			
			//老规矩，判断是直接到b的距离小,还是先到a在到b的距离小
			//只是因为担心单纯到a的距离可能被修改过，所有使用备份数组中的数据来操作 
				/*
				1 2 1
				2 3 1
				1 3 3
				*/
			//输出出来就看懂了 
//            printf("当前的a是%d,b是%d,对应的最短路径中，dist[b] = %d,backup[a] = %d,backup[a]+w = %d\n",
//			a,b,dist[b],backup[a],backup[a]+w);
			dist[b] = min(dist[b],backup[a]+w);
		}
		
	}
}

int main(){
	//输入 
	scanf("%d %d %d",&n,&m,&k);
	//建图
	for(int i = 0;i < m;i++) {
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		edges[i] = {a,b,w};
	}
	
	//调用解决存在负权边时，找最短路径问题
	bellman_ford();
	//输出结果
	if(dist[n] > 0x3f3f3f3f/2)   puts("impossible");
	else cout << dist[n];
	
	
	return 0;
}
