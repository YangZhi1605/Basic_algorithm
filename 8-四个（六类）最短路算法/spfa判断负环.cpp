#include <bits/stdc++.h> 

using namespace std;
const int N = 1e4 + 10;
int n,m;
int h[N],e[N],ne[N],w[N],idx;
// dist[x]�洢1�ŵ㵽x����̾��룬cnt[x]�洢1��x�����·�о����ĵ���
int dist[N],cnt[N];
// �洢ÿ�����Ƿ��ڶ�����
bool st[N];

void add(int a,int b,int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a]; //ע������ͳ�Ƶ���idx���ָ������ָ���λ�ã��ղŲ���ʱ��д��ne[b] = h[a]�� 
	h[a] = idx ++;
}

bool spfa(){
	// ����Ҫ��ʼ��dist����
    // ԭ�����ĳ�����·������n���㣨�����Լ�������ô�����Լ�֮��һ����n+1���㣬
	//�ɳ���ԭ��һ������������ͬ�����Դ��ڻ���
	queue<int> q;
	
	//�����ڵ�1��n�ŵ㶼���������У�������Ѿ���� 
	for(int i = 1;i <= n;i++){
		q.push(i);
		st[i] = true;
	}
	while(q.size()){
		auto t = q.front();
		q.pop();
		st[t] = false;
		
		for(int i = h[t];i != -1;i  = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t]+w[i]){
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t]+1;
				
				//����ԭ�� --> ���ڽ���������� 
				/*
				����ԭ���һ�㺬��Ϊ��"���ÿ���������һ�����ϣ�ÿһ��ƻ���Ϳ��Դ���һ��Ԫ�أ�
				������n+1��Ԫ�طŵ�n��������ȥ�����бض���һ������������������Ԫ�ء�
				*/ 
				if(cnt[j] >= n) return true;
				
				//ͬʱ����������j û���ڶ����У��ͼ������
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
	
		}
	}
	
	return false;
	
	
}

int main(){
	cin >>n >>m;
	memset(h,-1,sizeof h);
	
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
	}
	if(spfa()) puts("Yes");
	else puts("No");
	
	return 0;
}


