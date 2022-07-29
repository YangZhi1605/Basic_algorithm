#include <bits/stdc++.h> 

 
using namespace std;
const int N =210,INF = 1e9;
int n,m,Q;
int d[N][N];

//��ʵҲ���ĳ���������Ҫ��ѯĳ������֮�����̾����ʱ��ʹ����
// 
void floyd(){
	//����k����Ϊk�У��ڲ���ǳ����dijkstra�������·����˼�����˵�ǣ��ڽӾ�����£�������dijkstra���淨 
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);//����ѭ�����õ�˳��Ҳ���Ի�� 
		}
	}
}

int main(){
	cin >> n >> m >> Q;
	
	//��ʼ������ -- ע������û�г�ʼ��ʲô�����ͼ��ֱ�ӳ�ʼ���ľ��������� 
	//�����Ǿ�����ô�߳�����n 
	for(int i = 1; i <= n;i++) {
		for(int j = 1;j <= n;j++){
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	
	//����ͼ
	while(m--) {
		int a,b,c;
		cin >>a >> b>> c;
		d[a][b] = min(d[a][b],c);//����Ҳ��ֱ��ͳ�Ƶľ����� 
	}
	
	floyd();
	
	while(Q--){
		int a,b;
		cin >> a >> b;
		if(d[a][b] > INF/2) puts("impossible");
		else cout <<d[a][b];
	}
	
	return 0;
	return 0;
}

