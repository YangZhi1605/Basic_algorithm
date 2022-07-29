#include <iostream> 
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
const int N = 510;

int n,m;//ͼ�еĵ�ͱ�
int g[N][N];//�ڽӾ��� 
int dist[N];//��1�ŵ㵽ͼ��ÿһ����ľ���
bool st[N];//��ʾÿһ��������·���ǲ����Ѿ�ȷ����


void dijkstra(){
	//�����������dist,�Ȱ����еĵ���Ϊ������ 
	memset(dist,0x3f,sizeof dist);
	//��Ϊ��Ŀ���Ǵ�1�ŵ㿪ʼ�ߣ��ͱ�ʾΪ
	dist[1] = 0;
	
	//n-1��ѭ�� ����Ϊʲôn-1��ѭ�������е��Ժ��� 
	for(int i = 0;i < n-1;i++){
		int t = -1;//t��¼����ȫ����Сֵ
		//����n���㣬Ŀ���Ǹ��³���ǰѭ���µ�ȫ����С
		for(int j = 1;j <= n;j++) {
			//����ÿ���������ִ������
			//1����ǰ��jû�б�st�����¼��״̬��ͬʱ 
			//2.1��Ҫô�����¼��Сֵ��t��Ȼ��-1��ֱ��û�б�����
			//2.2��Ҫô��¼��Сֵ��t�Ѿ�����ֵ���ˣ��������ڳ�����һ�����̵ľ���·��
			if(!st[j] && (t == -1 || dist[t] > dist[j]) ){
				t = j;
			}
		}
		
		//�������j �ŵ���ʾ�Ѿ��ҵ����·��������st��
		st[t] = true;
		//ʹ��ȫ����С
		//��Ŀǰ�����·��de "��t" ȥ���³�����1~n�ܻ�õ����·�� 
		for(int k = 1; k <= n;k++ ){
			dist[k] = min(dist[k],dist[t]+g[t][k]);
		}
	}
}

int main() {
	
	//�����ͱ�
	cin >> n >> m;
	//��ʼ���ڽӾ���
	memset(g,0x3f,sizeof g) ;
	//����m����
	while(m--) {
		int a,b,c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b],c);
	}
	//����dijkstra
	dijkstra();
	
	if(dist[n] == 0x3f3f3f3f) puts("-1");
	else cout << dist[n];
	
	
	
	return 0;
}

 

