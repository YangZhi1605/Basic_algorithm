#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;


vector<int> div(vector<int> &A,int &b,int &r) { //����û�жԴ���������޸ģ���&ֻ��Ϊ��Ч�ʡ������޸�ֵ 
	vector<int> C;
	//ģ������Ĺ��̣������ǴӸ�λ��ʼ����
	
	for(int i = A.size()-1;i >= 0;i--){
		r = r * 10 + A[i]; //������׷�ӻ�ԭ���ĸ�λ
		C.push_back(r/b) ;//��������֮�󣬼����λ���г����Ľ����Ҫ�õ��̣����������� 
		//��������
		r %= b; 
	} 
	//��Ϊ����Ҫ�������������ͷ�תһ�°� 
	reverse(C.begin(),C.end());
	//ȥ��0
	while(C.size() > 1 && C.back() == 0)  C.pop_back();//ע����������Ǵ���1����Ϊ������Ҫ��һ��
	//���綼��0��������0��ʱ��popһ�����͵ñ������һ���� 
	return C;
}

int main(){
	string a; //������ 
	int b; //����
	//��������̺�����
	cin >> a >> b;
	vector<int>A ;
	for(int i = a.size()-1; i >= 0;i--) A.push_back(a[i] - '0');
	
	int r;//��ʾ�����������
	auto C = div(A,b,r) ;
	
	
	//�����
	for(int i = C.size()-1;i >= 0;i--)  cout << C[i];
	
	//�������
	cout << endl;
	cout << r; 
	
	return 0;
}
