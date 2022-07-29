#include <bits/stdc++.h> 

using namespace std;
const int N = 510,M =1e4 + 10;
int n,m,k;
int dist[N];
int backup[N];

//��ŵ�͵㵽��֮���Ȩ��
struct Edge{
	int a,b,w;
}edges[M]; 

void bellman_ford(){
	//��ʼ����������Ϊ�ܴ�ܴ��ֵ 
	memset(dist,0x3f,sizeof dist) ;
	dist[1] = 0;
	
	//��ĿҪ����"��ྭ�� k ���ߵ���̾���"�����ھʹ���k����
	for(int i = 0;i < k;i++) {
		//��Ϊÿ�ε�����������һ���ߣ��ͻ�Ӱ��ԭ��������
		//���Բ����������� 
		memcpy(backup,dist,sizeof dist);
		
		//�������еıߣ����ƶ���Ӧ�ĵ��ǵ����·��
		for(int i = 0;i < m;i++){
			int a = edges[i].a;
			int b = edges[i].b;
			int w = edges[i].w;
			
			//�Ϲ�أ��ж���ֱ�ӵ�b�ľ���С,�����ȵ�a�ڵ�b�ľ���С
			//ֻ����Ϊ���ĵ�����a�ľ�����ܱ��޸Ĺ�������ʹ�ñ��������е����������� 
				/*
				1 2 1
				2 3 1
				1 3 3
				*/
			//��������Ϳ����� 
//            printf("��ǰ��a��%d,b��%d,��Ӧ�����·���У�dist[b] = %d,backup[a] = %d,backup[a]+w = %d\n",
//			a,b,dist[b],backup[a],backup[a]+w);
			dist[b] = min(dist[b],backup[a]+w);
		}
		
	}
}

int main(){
	//���� 
	scanf("%d %d %d",&n,&m,&k);
	//��ͼ
	for(int i = 0;i < m;i++) {
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		edges[i] = {a,b,w};
	}
	
	//���ý�����ڸ�Ȩ��ʱ�������·������
	bellman_ford();
	//������
	if(dist[n] > 0x3f3f3f3f/2)   puts("impossible");
	else cout << dist[n];
	
	
	return 0;
}
