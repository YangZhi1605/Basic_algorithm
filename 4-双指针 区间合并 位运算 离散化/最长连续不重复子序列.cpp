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
		h[a[i]] ++;//哈希表统计a数组中每个数出现的次数 
		while(h[a[i]] > 1) {
			h[a[j]] --;//注意这里是用j指针去扫，那么需要写j指针 
			j++;
		}
		
		cnt = max(cnt,i-j+1);//统计i~j区间中的数字个数，比如3~5，有三个，即5-3+1 
	}
	
	cout << cnt;
	return  0;

}
