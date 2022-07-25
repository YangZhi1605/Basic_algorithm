#include <iostream> 
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
string end_ans = "12345678x" ;//����Ŀ��״̬
queue<string> q;//�������
unordered_map<string,int> d;

int bfs(string start){
	//��ʼ�����к�dist���� 
	q.push(start);
	d[start] = 0;
	int dx[] = {1,-1,0,0};//�������� 
	int dy[] = {0,0,1,-1};
	
	while(q.size()) {
		//ȡ��ͷ
		auto t = q.front();
		q.pop();
		
		//��¼����ǰ״̬�ľ��룬���������״̬���ͷ��ؾ���
		int distance = d[t];
		if(t == end_ans) return distance;
		//��ѯx���ַ����е��±꣬Ȼ��ת��Ϊ�����е�����
		int k = t.find('x'); 
		int x = k/3,y = k%3;
		
		//̽��4������
		for(int i = 0;i < 4;i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			//��ǰ����û��Խ��
			if(a>=0 && a < 3 && b >=0 && b < 3) {
				//ת��x
				swap(t[k],t[a*3+b]) ;
				//�����ǰ��״̬�ǵ�һ�α�������¼���룬���
				if(!d.count(t)) {
					d[t] = distance + 1;
					q.push(t);
				}
				//��ԭ״̬
				swap(t[k],t[a*3+b]) ;
			}
		}
	}
	//�޷�ת����Ŀ��״̬������-1
	return -1; 
	
}

int main(){
	string c,start;
	//������ʼ״̬
	for(int i = 0;i < 9;i++) {
		cin >> c;
		start += c;
	}
	
	cout << bfs(start) <<endl;
	
	return 0;
}
