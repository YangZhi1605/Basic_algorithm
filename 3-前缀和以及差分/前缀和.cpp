#include <iostream>
#include <cstdio>

using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N],sum[N];

int main(){
	scanf("%d %d",&n,&m);
	
	//����
	for(int i= 1;i <= n;i++) scanf("%d",&a[i]);
	
	//Ԥ����
	for(int i =1;i <= n;i++)  sum[i] = sum[i-1] + a[i];
	
	//����m��ѯ��
	while(m--) {
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);//ʹ��ǰ׺�ͼ��㹫ʽ 
	}
	return 0;
}
