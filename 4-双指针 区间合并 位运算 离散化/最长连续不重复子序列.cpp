#include <iostream> 

using namespace std;
const int N  =100010;
int a[N],h[N];

int main(){
	int n;
	cin >> n;
	for(int i = 0;i< n;i++) cin >> a[i];
	
	int cnt = 0;
	for(int i = 0,j = 0; i < n;i++){
		h[a[i]] ++;//��ϣ��ͳ��a������ÿ�������ֵĴ��� 
		while(h[a[i]] > 1) {
			h[a[j]] --;//ע����������jָ��ȥɨ����ô��Ҫдjָ�� 
			j++;
		}
		
		cnt = max(cnt,i-j+1);//ͳ��i~j�����е����ָ���������3~5������������5-3+1 
	}
	
	cout << cnt;
	return  0;

}
