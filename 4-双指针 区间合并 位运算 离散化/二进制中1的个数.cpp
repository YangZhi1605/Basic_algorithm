#include <iostream>

using namespace std;

//经过lowbit中的取反+1运算之后，从右到左数，首先出现的1的这截是不变的，但是其再向左，就和原
//本数全部相反了， 经过&运算，全部会变成0，故可以取出最低位的1及其后面的0 
int lowbit(int x){
	return x &(-x);
}

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int x;
		int cnt = 0;
		cin >> x;
		while(x){
			x -= lowbit(x);
			cnt++;
		}
		cout << cnt << ' ';
	}
	return 0;
}
