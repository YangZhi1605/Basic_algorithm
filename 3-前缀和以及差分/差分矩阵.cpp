/*
m��n�У�q��ѯ��
��ѡ�е��Ӿ����м���C
x1,y1,x2,y2,c  
*/ 

#include <iostream>

using namespace std;
const int N = 1010;
int n,m,q;
int a[N][N],b[N][N];


//�˳�������ĺ�������ģ�����ô�ڲ������b��ָ�������ϼ�����
void insert(int x1,int y1,int x2,int y2,int c) {
	b[x1][y1] += c;
	b[x2+1][y1] -= c;
	b[x1][y2+1] -= c;
	b[x2+1][y2+1] += c;
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	
	//����ά�������Ϣ��ȡ������a��
	for(int i =1;i <= n;i++) {
		for(int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	}
	
	//����������� 
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= m;j++)
			//insert(i,j,i,j,a[i][j]);//���ݽ�ȥ�ġ�����a������ԣ�ֻ��һ����������������ֵ��a[i][j]
			//���Ƕ��ڲ������b���ԣ���Ҫ�����(1,1)��(i,j),Ҳ�͹������˻����Ĳ������ 
			
			//��Ȼ��Ҳ����ֱ��ʹ�ù�ʽ�����������
			b[i][j] = a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1] ;
	}
	//q��ѯ�ʣ���ָ���������c 
	while(q--){
		int x1,x2,y1,y2,c;
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
		insert(x1,y1,x2,y2,c);
	}
	
	//����һ�²�ּӵ�ԭ�����ֵ
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++)
			//���Զ�̬�滮��˼�� 
//			b[i][j] += b[i-1][j] + b[i][j-1]-b[i-1][j-1];
			//����ʹ��ʽ�ӹ���������飬ͬ�������ʽ�Ӽ������a����Ľ����
			a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j];
	}
	
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= m;j++)
			printf("%d ",a[i][j]);
			
		cout << endl;
	}
	
	return 0;
}
