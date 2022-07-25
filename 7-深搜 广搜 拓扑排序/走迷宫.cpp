#include <iostream> 
#include <queue> 
#include <vector>
#include <cstring>
#include <algorithm>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 110;
int g[N][N],d[N][N]; //g�Ǵ��01��������飬d�Ǵ�ž�������� 
PII pre_pos[N][N]; //����Ҫ�����·����ʱ��ʹ��������� 
int n,m;
queue<PII> q;
vector<PII> ans;

int bfs(){
	//��ʼ���������� 
	memset(d,-1,sizeof d); 
	d[0][0] = 0;//��ʾ(0,0) ������Ѿ��߹���
	q.push({0,0}) ;
	
	int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
	
	//�ڶ��в�Ϊ�յ�ʱ�����ȡ��ͷ����չ��ͷ��
	while(q.size()) {
		//ȡ��ͷ
		auto hh = q.front();
		//ȥ����ͷ
		q.pop();
		
		//��չ������Ŀ�����е��ĸ�����
		for(int i = 0;i < 4;i++) {
			int xx = hh.x + dx[i];
			int yy = hh.y + dy[i];
			
			//�����չ���������Ϸ��������ϰ������û�б���չ��,��̽����ǰ�ĵ� 
			if(xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == 0&&d[xx][yy] == -1){
				d[xx][yy] = d[hh.x][hh.y] + 1;//̽����ǰλ�� 				
				pre_pos[xx][yy] = hh;//����Ҫ���·����ʱ�򣬼�¼��ǰ������Ǵ��Ķ�ת�ƹ����� 
				q.push({xx,yy}); //��̽�������� 
			}
		}
	}
		
		//���·����ֻ���ǵ��ŵģ����Էŵ�һ��vector<PII> �У�reverseһ�£������ 
		int edx = n-1,edy = m-1;
		while(edx || edy){
			ans.push_back({edx,edy});
			cout << edx <<' '<< edy << endl;
			auto pre = pre_pos[edx][edy];//ȡ��pre_pos�����д洢�ģ����ݵ�ǰλ�ã��������һ�����λ��
			//����λ�ã��������� 
			edx = pre.x;
			edy = pre.y; 
		}
		//���̽�����յ����С����������˵����
		return d[n-1][m-1]; 
}

int main(){
	cin >> n >> m;
	//����01���� 
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) cin >> g[i][j];
	} 
	
	cout << bfs() << endl;
	
	reverse(ans.begin(),ans.end());
	for(auto it:ans){
		cout << it.x <<' '<< it.y<<endl;
	}
	
	return 0;
}
