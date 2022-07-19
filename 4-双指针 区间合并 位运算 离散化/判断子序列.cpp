#include <iostream>

using namespace std;
const int N  = 100010;
int n,m;

int a[N],b[N];

int main(){
	
	cin >>n >> m;
	//判断 a 序列是否为 b 序列的子序列 
	for(int i = 0;i<n;i++) cin >> a[i] ;
	for(int i = 0;i < m;i++) cin >> b[i];
	
	int i = 0,j = 0;
	while(i < n && j < m){
		if(a[i] == b[j]) i++; //当前元素符合作为子数组的要求
		j ++; 
		
	}
	
	if(i == n) puts("Yes") ;
	else puts("No");
	
	return 0;
}

