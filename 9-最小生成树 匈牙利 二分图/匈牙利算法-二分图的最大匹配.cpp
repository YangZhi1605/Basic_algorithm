#include <bits/stdc++.h> 

using namespace std;

const int N = 510,M = 1e5+10;

int n1,n2,m; // n1表示第一个集合中的点数，n2表示第二个集合中的点数
// 邻接表存储所有边，匈牙利算法中只会用到从第一个集合指向第二个集合的边，所以这里只用存一个方向的边
int h[N],e[M],ne[M],idx; 
int match[N];// 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
bool st[N];// 表示第二个集合中的每个点是否已经被遍历过

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}


//找男朋友的原则 
bool find(int x) {
	//枚举女孩子看上的所有男孩子
	for(int i = h[x]; i != -1;i = ne[i]){
		int j = e[i];
		//如果这个男孩子没有考虑过对象
		if(!st[j]) {
			//标记女孩子x占据了男孩子j
			st[j] =  true; 
			//核心来了
			//如果
			//如果第二个集合中的点j当前是没有匹配第一个集合中
			//或者第二个集合中已经匹配到的第一个集合中点，是可以再找其他其他点的
			//就让当前这第二个集合中的点，被x占据吧 
			if(match[j] == 0 || find(match[j])){
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}


int main(){
	cin >> n1 >> n2 >> m;
	memset(h,-1,sizeof h);
	
	//建图 
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,b);
	}
	
	int ans = 0;//存储的是成功匹配的数量
	
	//从前向后一次遍历左半部包含 n1 个点
	for(int i = 1;i <= n1;i++) {
		//先清空这些女孩的所有匹配关系
		memset(st,false,sizeof st) ;
		
		if(find(i))  ans ++;
	}
	
	cout << ans<< endl;
	
	return 0;
}
