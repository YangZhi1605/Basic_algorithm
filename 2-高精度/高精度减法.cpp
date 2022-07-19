#include <iostream> 
#include <vector>

using namespace std;

bool cmp(vector<int> A,vector<int> B){
	//先看是不是一样长，假如不是，判断是不是A数组更长 
	if(A.size() != B.size()) return A.size() > B.size();
	else{
		//进入这个循环就是一样长，那就逐未逐位的比较 
		//注意这儿的比较，代码末尾的测试报错就是因为这儿
		//逐位比较的逻辑是从个位开始，对于这两个数组而言，个位是从A[A.size()-1]开始倒着数的 
		for(int i = A.size()-1;i >= 0;i--){
			//当出现了不相同的，就用A作为一个基准，判断A是不是更大
			if(A[i] != B[i])  return A[i] > B[i];
		}
	}
	
	return true;//上面的比较没有出现false，那就是A更大 
}


vector<int> sub(vector<int> &A, vector<int> &B) {
	vector<int> C;
	
	int t = 0;//用t表示借位的数值，每个借位要在新一位的A中扣除 
	for(int i = 0;i < A.size();i++){
	    //模拟相减,ans_bit表示每一位相减的结果
		int ans_bit = A[i] - t; 
		//A数组中，当前位的处理好了，看看B数组还有么有位数，有的话就处理
		if(i < B.size()) ans_bit -= B[i];//模拟相减，在A模拟相减(一般都是减去的借位)的基础上，减去B数组中，该位置上的数值
		
		//存相减的结果
		//为了防止是负数，采用+10 再取模10 的玩法
		C.push_back((ans_bit+10)%10);
		
		//处理相减之后，是否导致了借位
		//结果小于0的时候，表示相减出来是负数，那么就需要借位了，需要记住这里借了一位，待会在高位中扣除 
		if(ans_bit < 0) t =1;
		else t = 0;
	}
	
	//这种逆存然后正常从低位遍历，模拟相减的情况，假如最后结果是3，那么在逆着算出来的数组C中
	//应该存储的是300，再同样逆着输出，结果就是003，那么就是有前导0了。
	//积累去除前导0
	//对于这种逆着存储的数组去除前导0，其实就是判断结尾是否为0，假如是，就去结尾 
	while(C.size() > 1 && C.back() == 0)  C.pop_back();
	
	return C;
}

int main(){
	string a,b;
	vector<int> A,B;
	cin >> a >> b;
	
	for(int i = a.size()-1;i >= 0;i--) A.push_back(a[i] - '0');
	for(int i = b.size()-1;i >= 0;i--) B.push_back(b[i] - '0');
	
	//由于相减会出现负数，所以得考虑输入得参数，谁更大
	if(cmp(A,B))  //默认返回true的是A大于B的情况
	{
		auto C = sub(A,B) ;
		for(int i = C.size()-1;i >= 0; i--) cout << C[i];
		
	}else{
		printf("-");
		auto C = sub(B,A);
		for(int i = C.size()-1;i >= 0;i--) cout <<C[i];
	}
	 
	return 0;
}

/*
123456789
987654321

输出
135802468

标准答案
-864197532 
*/ 
