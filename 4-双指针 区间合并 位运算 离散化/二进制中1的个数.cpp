#include <iostream>

using namespace std;

//����lowbit�е�ȡ��+1����֮�󣬴��ҵ����������ȳ��ֵ�1������ǲ���ģ������������󣬾ͺ�ԭ
//����ȫ���෴�ˣ� ����&���㣬ȫ������0���ʿ���ȡ�����λ��1��������0 
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
