#include <bits/stdc++.h> 

using namespace std;

const int N = 510,M = 1e5+10;

int n1,n2,m; // n1��ʾ��һ�������еĵ�����n2��ʾ�ڶ��������еĵ���
// �ڽӱ�洢���бߣ��������㷨��ֻ���õ��ӵ�һ������ָ��ڶ������ϵıߣ���������ֻ�ô�һ������ı�
int h[N],e[M],ne[M],idx; 
int match[N];// �洢�ڶ��������е�ÿ���㵱ǰƥ��ĵ�һ�������еĵ����ĸ�
bool st[N];// ��ʾ�ڶ��������е�ÿ�����Ƿ��Ѿ���������

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}


//�������ѵ�ԭ�� 
bool find(int x) {
	//ö��Ů���ӿ��ϵ������к���
	for(int i = h[x]; i != -1;i = ne[i]){
		int j = e[i];
		//�������к���û�п��ǹ�����
		if(!st[j]) {
			//���Ů����xռ�����к���j
			st[j] =  true; 
			//��������
			//���
			//����ڶ��������еĵ�j��ǰ��û��ƥ���һ��������
			//���ߵڶ����������Ѿ�ƥ�䵽�ĵ�һ�������е㣬�ǿ������������������
			//���õ�ǰ��ڶ��������еĵ㣬��xռ�ݰ� 
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
	
	//��ͼ 
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,b);
	}
	
	int ans = 0;//�洢���ǳɹ�ƥ�������
	
	//��ǰ���һ�α�����벿���� n1 ����
	for(int i = 1;i <= n1;i++) {
		//�������ЩŮ��������ƥ���ϵ
		memset(st,false,sizeof st) ;
		
		if(find(i))  ans ++;
	}
	
	cout << ans<< endl;
	
	return 0;
}
