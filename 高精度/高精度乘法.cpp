#include <iostream> 
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A,int b){
	vector<int> C;
	int ans = 0;//���ڿ��ǽ�λ
	//ģ��˷��Ĺ���
	for(int i = 0;i < A.size() || ans ;i++) {
		if(i < A.size()) ans += A[i]*b; //ģ��������λȥ��b�Ĺ��� 
		C.push_back(ans%10) ;//�Ϲ�񣬴洢������
		ans /= 10; 
	}
	//1234*0�����
	while(C.size() > 1 && C.back() == 0)  C.pop_back();
	
	return C;
}

int main(){
	string a;
	int b;
	
	cin >> a >>b;
	vector<int> A;
	for(int i = a.size()-1;i >= 0;i--) A.push_back(a[i] - '0');
	
	auto C = mul(A,b);
	
	for(int i = C.size()-1; i >= 0;i--) cout <<C[i];
	
	return 0;
}
