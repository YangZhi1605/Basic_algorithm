#include <iostream>

using namespace std;
const int N  = 100010;
int n,m;

int a[N],b[N];

int main(){
	
	cin >>n >> m;
	//�ж� a �����Ƿ�Ϊ b ���е������� 
	for(int i = 0;i<n;i++) cin >> a[i] ;
	for(int i = 0;i < m;i++) cin >> b[i];
	
	int i = 0,j = 0;
	while(i < n && j < m){
		if(a[i] == b[j]) i++; //��ǰԪ�ط�����Ϊ�������Ҫ��
		j ++; 
		
	}
	
	if(i == n) puts("Yes") ;
	else puts("No");
	
	return 0;
}

