#include <iostream> 

using namespace std;
int n;
const int N = 10;
int path[N];//��ŵ�ǰdfs��ȥ�󣬿��Դ�ŵ���ֵ
bool st[N];//��¼��ǰ���λ�õ�״̬���Ƿ��ù�

void dfs(int u) {
	//���u�Ѿ��ݹ鵽n����ˣ�������dfs�깤�ˣ���ô�����̽���д洢��λ����Ϣ 
	if(u == n ){
		for(int i = 0; i < n;i++) cout << path[i] <<' ';
		cout << endl;
		return;
	}
	
	//û�е��߽磬���г����̽��1 ~ 3�������Ƿ��ܹ��洢 
	//����ö�ٵ�����Ҫ���е����� 
	for(int i = 1;i <= n;i++) {
		
		if(!st[i]){ //�ж�������û���ù� 
			path[u] = i;//��¼û���ù������֣��ŵ�path�����У���Ϊ��ǰ̽���Ľ�� 
			st[i] = true;//����Ѿ��ù������� 
			
			//�ݹ鵽��һ��
			dfs(u+1) ;
			//�ݹ�����ˣ�Ҳ���ǻ��ݻ����ˣ���Ҫ�ָ��ֳ� 
			st[i] = false;
		}
	}
}

int main(){
	cin >> n;
	dfs(0);
	return 0;
}
