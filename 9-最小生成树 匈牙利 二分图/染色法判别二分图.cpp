#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10,M = 2e5 + 10;
int n,m;
int h[N],e[M],ne[M],idx; //ע�⣬��Ϊ������ͼ����ô�洢ָ��ͽ��ָ�����ݣ�Ӧ�ÿ������������ 
int color[N];//��ʾÿ�������ɫ��-1��ʾδȾɫ�� 0��ʾ��ɫ��1��ʾ��ɫ

/*
��Ҫ�����������ǣ�ͬʱ�ô���Ľ�㣬���������ж��Ƿ�Ⱦɫì�� 
*/


void add(int a,int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}


//����u�洢��ǰ�Ľ�㡣c�洢��ǰ����ɫ
bool dfs(int u,int c){
	color[u] = c;//������ĵ�Ⱦɫ
	
	//�����ڽӱ�
	for(int i = h[u];i != -1;i = ne[i]) {
		int j = e[i];
		//�����ǰ��û��Ⱦ��ɫ ע�����ڵ�ǰ��û�б�Ⱦɫ����ʱ�򣬲Ž�ȥ���� 
		if(color[j] == -1) {
			//��!c�л������ȥȾɫ�ı��c 
			if(!dfs(j,!c)) return false;
			//�����ǰ��������Ѿ���Ⱦɫ���ˣ����Ǻ��Ҵ������Ⱦ�Ľ����ɫ��ͬ����ì���ˣ�����flase 
		}
		//�����Ⱦ��ɫ����Ҫ�ж�Ⱦɫ�Ƿ�ì�� 
		else if(color[j] == c) return false;
	}
	
	return true;
}


int main() {
	cin >> n >> m;
	//��ʼ���ڽӱ�
	memset(h,-1,sizeof h) ;
	
	//��ͼ
	while(m--){
		int a,b;
		cin >> a >> b;
		//����ͼ 
		add(a,b);
		add(b,a);
	} 
	
	//Ⱦɫ ��flag������Ⱦɫ�Ƿ����ì��
	bool flag = true;
	memset(color,-1,sizeof color) ;
	
	for(int i = 1; i <= n;i++) {
		//�����ǰ�����û��Ⱦ��ɫ  ע�����û�б�Ⱦɫ������ 
		if(color[i] ==  -1){
			//��dfs��;�У�����flase���Ǳ�ʾì����
			if(!dfs(i,0)){
				flag = false;//���
				break; 
			}
		}
	}
	
	if(flag) puts("Yes");//Ⱦɫ˳����û��ì�ܷ������Ƕ���ͼ
	else puts("No") ;
	 
	return 0;
}
