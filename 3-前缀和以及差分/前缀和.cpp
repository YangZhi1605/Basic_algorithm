#include <iostream>
#include <cstdio>

using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N],sum[N];

int main(){
	scanf("%d %d",&n,&m);
	
	//输入
	for(int i= 1;i <= n;i++) scanf("%d",&a[i]);
	
	//预处理
	for(int i =1;i <= n;i++)  sum[i] = sum[i-1] + a[i];
	
	//处理m次询问
	while(m--) {
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);//使用前缀和计算公式 
	}
	return 0;
}
