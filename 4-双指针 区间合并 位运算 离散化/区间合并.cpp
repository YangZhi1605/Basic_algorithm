#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> PII;
int n;//n������
vector<PII> segs;

//�����Ȱ���˵�������ά��һ�����䣬�����һ�������������������ıȽϣ��洢��������ȥ��
void merge(vector<PII> &segs){ //��Ϊʹ�õ��Ƿ��������ȡ��ַ����һ������ʡ�ԡ���Ȼ�����޸Ľ���ˣ���ʵҲ���Բ�д�ɷ��� 
	vector<PII> res;
	sort(segs.begin(),segs.end());
	
	int st = -2e9,ed = -2e9;
	for(auto seg:segs){
		if(ed < seg.first){ // ���1�����������޷��ϲ� 	����һ��������յ�С����һ���������㣬����ǲ��ཻ 
			//������1����㲻�ǳ�ʼ��������£������� 
			if(st != -2e9) res.push_back({st,ed}); //����1�Ž�res����
			st = seg.first;  //ά������2
			ed = seg.second;
		}
		//���������������н�������������Ҫ���ҽ������Ϊ�ϳ����Ǹ��� 
		else if(ed < seg.second) ed = max(ed,seg.second); 
		//(ʵ����Ҳ�����3������1��������2����ʱ����Ҫ�κβ���������ʡ��)
	}
	//����Ƕ�����2 ���ٴδ������洦�����������޷��ϲ���ʱ�򣬱���if(ed < seg.first)�����һ��ѭ���� 
	//��һ�ΰ�����1�浽������ˣ� ͬʱ��st,ed����Ϊ����2�ģ���ʱ����Ҫ��󲹴�һ�� 
	if(st != -2e9)  res.push_back({st,ed});
	segs = res;
}

int main(){
	
	cin >> n;
	for(int i = 0; i < n;i++){
		int l,r;
		cin >> l >> r;
		segs.push_back({l,r});
	}
	
	//�ϲ����� 
	merge(segs);
	//���
	cout << segs.size()  << endl;
	
	return 0;
}
