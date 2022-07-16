#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A,vector<int> &B){
	if(A.size() < B.size()) return add(B,A);//Ϊ�˷�����㣬ͳһ��A�����д洢�Ƚϳ����ַ�����B�д洢�Ƚ϶̵��ַ���
	 
	vector<int> C;//�洢�Ӻͽ���ĺ���
	int scale = 0;//��ʾ��ǰ�еĽ�λ����
	
	//�ӷ��ǴӸ�λ��ʼ�ģ�����ģ��Ӹ�λ�ӵĹ���
	/*
	a = 567, b = 28
	Ϊ�˷�����㣬���������ֱ� **����** ����� A�� B �������������С� 
	A = [7, 6, 5], B = [8, 2]
	*/ 
	
	//ö�ٳ��������ÿһλȥ�Ӷ̵������ÿһλ
	for(int i = 0;i < A.size();i++ ){
		scale += A[i]; //����A�ĵ�i������ 
		if(i < B.size()) scale += B[i];//��B���黹�����ֵ�����£�����B������
		//���Ӻͽ���ŵ����������
		C.push_back(scale % 10) ;
		scale /= 10;//���½�λ 
	}
	
	//�������н�λ���Ž����������
	if(scale)  C.push_back(scale);
	return C;
}

/*
1
999999999
*/

int main(){
	string a,b;//���ַ�����ʽ�����������������ڴ���ĵ���洢
	vector<int> A,B;
	cin >> a >> b;
	//����洢����������� 
	for(int i = a.size() - 1;i >= 0;i--)  A.push_back(a[i]-'0');
	for(int i = b.size() - 1; i >=0;i--) B.push_back(b[i]-'0');
	
	auto C = add(A,B);//���üӷ�����
	//ͬ��Ҳ�ǵ������ 
	for(int i = C.size()-1;i >= 0;i--) cout<<C[i];
	
	
	
	return 0;
}
