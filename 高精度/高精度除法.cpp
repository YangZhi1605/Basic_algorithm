#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;


vector<int> div(vector<int> &A,int &b,int &r) {
	vector<int> C;
	//模拟除法的过程，除法是从高位开始除的
	
	for(int i = A.size()-1;i >= 0;i--){
		r = r * 10 + A[i]; //把余数追加回原本的高位
		C.push_back(r/b) ;//补上余数之后，计算该位进行除法的结果 
		//更新余数
		r %= b; 
	} 
	//因为待会要逆向输出，这里就反转一下吧 
	reverse(C.begin(),C.end());
	//去除0
	while(C.size() > 1 && C.back() == 0)  C.pop_back();
	return C;
}

int main(){
	string a; //被除数 
	int b; //除数
	//最后让求商和余数
	cin >> a >> b;
	vector<int>A ;
	for(int i = a.size()-1; i >= 0;i--) A.push_back(a[i] - '0');
	
	int r;//表示最后计算的余数
	auto C = div(A,b,r) ;
	
	
	//输出商
	for(int i = C.size()-1;i >= 0;i--)  cout << C[i];
	
	//输出余数
	cout << endl;
	cout << r; 
	
	return 0;
}
