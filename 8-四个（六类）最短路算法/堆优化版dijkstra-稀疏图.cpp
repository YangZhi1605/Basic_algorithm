#include <iostream> 
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
int n,m;
//ϡ��ͼ�͵ÿ����ڽӱ���
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}


void dijkstra(){
	//��ʼ����������
	memset(dist,0x3f,sizeof dist) ;
	dist[1] = 0;
	
	//�ѵ�Ӧ���Ǳ���ô����С���ѣ���Ϊ�����Ϳ��Ѳ��
	
	/*
	
	Type �����������ͣ�Container �����������ͣ�Container������������ʵ�ֵ�����������vector,deque�ȵȣ�
	�������� list��STL����Ĭ���õ���vector����Functional ���ǱȽϵķ�ʽ
	priority_queue<Type, Container, Functional>
	*/ 
	
	//ʹ��STL��������С����
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	//�Ե�ǰ���Զ��ԣ�first�����Ǿ��룬second�����ǽ���� 
	heap.push({0,1}) ; 
	
	//�����в�Ϊ�յ�ʱ�򣬽��в���
	while(heap.size()) {
		//ȡ����ǰ�ľ�����Сֵ����Ҫ��Сֵ������С���Ѷ��ԣ����ǶѶ�
		auto t = heap.top();
		heap.pop();
		
		int dis = t.first;
		int var = t.second;
		
		//�����ǰȾ̽���Ľ���Ѿ����ŵ�st����ͳ�ƹ����·���ˣ���ôֱ������ 
		if(st[var]) continue;
		//����ͳ�Ƶ�ǰ���
		st[var]  = true;
		
		//�õ�ǰͳ�Ƶ������㣬��̽���������
		for(int i = h[var];i != -1;i = ne[i]) {
			int node = e[i];
			
			//�Ƚ�ֱ���ߵ�j�ľ�������ߵ����var���ڸ���w[i]�ľ����i�ߵ�j���ܺͣ�˭����������С�� 
			if(dist[node] > dis + w[i]){
				dist[node] = dis + w[i];
				//�����³��������ݲ��뵽����
				heap.push({dist[node],node}) ;
				//�ڶ����У�ѭ��������� 
			}
		} 
	}
}

int main(){
	scanf("%d %d",&n,&m);
	//��ʼ���ڽӱ�
	memset(h,-1,sizeof h) ;
	
	while(m--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c) ;
	}
	
	dijkstra();
	
	if(dist[n] == 0x3f3f3f3f) puts("-1");
	else printf("%d",dist[n]);
	
	return 0;
}

