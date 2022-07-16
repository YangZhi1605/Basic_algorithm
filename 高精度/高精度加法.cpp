#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A,vector<int> &B){
	if(A.size() < B.size()) return add(B,A);//为了方便计算，统一让A数组中存储比较长的字符串，B中存储比较短的字符串
	 
	vector<int> C;//存储加和结果的函数
	int scale = 0;//表示当前有的进位数字
	
	//加法是从个位开始的，现在模拟从个位加的过程
	/*
	a = 567, b = 28
	为了方便计算，将两个数分别 **倒序** 存放在 A， B 两个整数数组中。 
	A = [7, 6, 5], B = [8, 2]
	*/ 
	
	//枚举长的数组的每一位去加短的数组的每一位
	for(int i = 0;i < A.size();i++ ){
		scale += A[i]; //加上A的第i个数字 
		if(i < B.size()) scale += B[i];//在B数组还有数字的情况下，加上B的数字
		//将加和结果放到结果数组中
		C.push_back(scale % 10) ;
		scale /= 10;//更新进位 
	}
	
	//如果最后还有进位，放进结果数组中
	if(scale)  C.push_back(scale);
	return C;
}

/*
1
999999999
*/

int main(){
	string a,b;//以字符串形式输入两个整数，用于待会的倒序存储
	vector<int> A,B;
	cin >> a >> b;
	//倒序存储输入的两个数 
	for(int i = a.size() - 1;i >= 0;i--)  A.push_back(a[i]-'0');
	for(int i = b.size() - 1; i >=0;i--) B.push_back(b[i]-'0');
	
	auto C = add(A,B);//调用加法函数
	//同样也是倒序输出 
	for(int i = C.size()-1;i >= 0;i--) cout<<C[i];
	
	
	
	return 0;
}
