#include <iostream>

using namespace std;
const int N = 10;
int n;
char g[N][N];
bool col[N],dg[N],udg[N];

void dfs(int u){
	if(u == n){//�ҵ�һ�鷽���� 
		for(int i = 0;i < n;i++) puts(g[i]);
		cout <<endl;
		return;
	} 
	
	//��������Ҫ����ȷʵ������ʽ
	//������n*n�ķ���
	//���紫��Ĳ���u��ȷ����ǰö�ٵ���������ô����ö�ٵľ�����
	//����+��ȷ���������꣬��ôһԪ���Է�����Ϳ�����������ˡ�y  = (+-)x + b 
	//
	for(int i = 0;i < n;i++){
		if(!col[i] && !dg[u+i] && !udg[-u+i+n]) {
			g[u][i] = 'Q' ;//���u��i�п��Է�
			col[i] = dg[u+i] = udg[-u+i+n] = true;
			dfs(u+1);
			//��ԭ�ֳ� 
			col[i] = dg[u+i] = udg[-u+i+n] = false;
			g[u][i] = '.';
		}
	}
}


int main(){
	cin >> n;
	//��ʼ����ͼ 
	for(int i = 0; i < n;i++)
		for(int j = 0; j < n;j++) g[i][j] = '.';
	
	dfs(0);
	
	return 0;
}

