#include <bits/stdc++.h>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];//dist[t]��ʾ��ǰ����㣬���Ѿ����õ���С�������У���������ĵ�
bool st[N];

int prim(){
	//��ʼ���������� 
	memset(dist,0x3f,sizeof dist);
	//sum�д�ŵ�����С������������Ȩ��֮��
	int sum = 0;
	
	for(int i = 0;i < n;i++) {
		int t = -1; //��¼ȫ����С�Ľ����
		
		//ע����������ṹ��dijkstraһ�������Ǳ˴˶����Ľṹ��û��Ƕ��
		//���Ǳ���Ĺ���ģ�� 
		
		//Ѱ���������·����t 
		for(int j = 1; j <= n;j++) {
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t= j;
		}
		//�ж�t�Ƿ����Ҫ�� 
		//�����ǰ�ĵ��Ѿ����ǵ�һ���㣬�Լ�������С�ĵ�Ϊ������ 
		//��˵����ǰ��������ĵ㣬ȷʵ�����������ˣ�����ǰ��ͼ������ͨ 
		if(i && dist[t] == INF) return INF;
		if(i) sum += dist[t];	
		
		//��tȥ���³�������
		//ע��������g[t][j]
		//����dijskstra���ԣ���dist[t] + g[t][j]
		//��Ϊ����dijkstra���ԣ�dist����ά������1�ŵ㵽t�����·��
		//��С��������ά������j�����ڼ���������������· 
		for(int j = 1;j <= n;j++) {	
			dist[j] = min(dist[j],g[t][j]);
		}
			
		st[t] = true;//���t�Ѿ��ù��� 
		
	}
	
	return sum; 
	
}

int main(){
	cin >> n >> m;
	memset(g,0x3f,sizeof g);
	
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		//��Ϊ������ͼ��������Ҫ��a��b�ģ��Լ���b��a��
		g[a][b] = g[b][a]  = min(g[a][b],c);
	}
	
	int ans = prim();
	if(ans == INF) puts("impossible");
	else cout << ans << endl;
	
	return 0;
}
