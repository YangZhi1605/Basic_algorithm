#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n,m;
int h[N],e[N],ne[N],idx;
int q[N],cnt[N];

void add(int a,int b){
	e[idx]  = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}


bool tsort(){
	int hh = 0;//��ͷ
	int tt = -1;//��β
	
	//�����Ϊ0�ĵ�ȫ�����
	//ע����Ŀ�и��ķ�Χ��1 �� n 
	for(int i = 1;i <= n;i++) 
		if(!cnt[i]) q[++ tt] = i;
		
	while(hh <= tt){
		//ȡ��ͷ
		int t = q[hh++] ;
		//��ȡ���Ķ�ͷ������չ
		for(int i = h[t];i != -1;i = ne[i]) {
			int j = e[i];
			cnt[j] --;//������j��һ����� 
			if(!cnt[j]) q[++ tt] = j; //�������֮�����Ϊ0�ˣ���ʾ��һ�������õ������򣬷ŵ�����q�� 
		}
	}
	
	return tt == n-1;//��βָ����������һ�����ݵ�λ�ã� ��ʾ����������γ���һ���������� 
}

int main(){
	cin >> n >> m;
	
	memset(h,-1,sizeof h);
	
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		//��ʾ�ӵ�a����b������� 
		add(a,b);
		//��Ϊ��b�ǽ��ڵ�a����ģ�����b�������Ҫ���� 
		cnt[b] ++;
	}
	if(tsort()) {
		//���������n������������� 
		for(int i = 0;i < n;i++) cout << q[i] <<' ';
		puts("");
	}else puts("-1");
	
	return 0;
}
