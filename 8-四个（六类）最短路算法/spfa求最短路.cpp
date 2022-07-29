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
	//����һ�����У������Ѿ�ȷ�����·����1�ŵ������� 
	queue<int> q;
	q.push(1);
	//���1�ŵ� 
	st[1] = true;
	
	//�Ϲ�أ������в��յ�ʱ�����
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		//��ǲ��ڶ����еĵ�
		st[t] = false;
		
		for(int i = h[t]; i != -1;i = ne[i]) {
			int j =e[i];
			if(dist[j] > dist[t] + w[i]){
				//�ҵ���С�����·������1�ŵ㵽j�ľ��� 
				dist[j] = dist[t] + w[i];
				//����ӵ����if���е��Ժ�
				//����ǣ�����ȷʵ���ҵ����·�ˣ�������Ҫ�ж�֮ǰ�ǲ����Ѿ��ҹ���
				//����û�У�������ӣ������ 
				if(!st[j]){
					q.push(j);//���
					st[j] = true;//��� 
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
