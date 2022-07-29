#include <bits/stdc++.h>

using namespace std;
const int N =  2e5 + 10;
int n,m;
int fa[N];//ά�����鼯������
//cnt�洢��ǰ�����˶������ߡ�ans �洢������С�����������бߵ�Ȩ�غ� 
int cnt,ans; 
//kruskal�㷨���ò����ڽӱ�洢��ֻҪ�ѽ���Լ��㵽��ֱ�ӱ߾�洢�����ͺ�
//��ô����ʹ����򵥵Ľṹ���ˣ�ֻ��Ҫ����ȷ���ȽϷ�ʽ��������Ҫ����


/*
kruskal�㷨�ĺ����ǰ�����ͨ������� 
��ͨ��Ĵ�����ô�Ϳ���ʹ�ò��鼯�� 
*/
struct Edge{
	int a,b,w;
}edges[N];
 
bool cmp(Edge &a,Edge &b){
	
	return a.w < b.w; 
}

int find(int x){
	if(fa[x] != x) fa[x] =find(fa[x]);
	return fa[x];
}

void kruskal(){
	//�Դ�����ݵĽṹ�尴��Ȩ�ش�С������������
	sort(edges,edges+m,cmp) ;
	//��ʼ�����鼯 ע���ǶԵ���в��鼯�ĳ�ʼ�� 
	for(int i = 1;i <= n;i++)  fa[i] = i;
	
	//��С����ö�����б� 
	for(int i = 0; i < m;i++) {
		int a = edges[i].a;
		int b = edges[i].b;
		int c = edges[i].w;
		
		//�ҵ�a��b�����ڽ��
		a = find(a);
		b = find(b) ;
		
		//���a �� b����һ����ͨ����
		if(a != b) {
			//��a����b��
			fa[a] = b;
			//ͳ�����ڵ�Ȩ�غ� 
			ans += c;
			//ͳ�Ʋ�����С�������Ľ����Ŀ 
			cnt ++; 
		}
	}
}


int main(){
	//���� 
	cin >> n >> m;
	//��ͼ
	
	for(int i = 0;i < m;i++){
		int a,b,w;
		cin >> a >>b >> w;
		edges[i] = {a,b,w};
	}
	//���÷��� 
	kruskal();
	
	//���
	//n���㣬ֻ�ܸպ���n-1�߲���������С������ 
	if(cnt < n-1) puts("impossible");
	else cout << ans <<endl;
	
	return 0;
}

