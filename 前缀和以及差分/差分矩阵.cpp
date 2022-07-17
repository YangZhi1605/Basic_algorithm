/*
m行n列，q个询问
在选中的子矩阵中加上C
x1,y1,x2,y2,c  
*/ 

#include <iostream>

using namespace std;
const int N = 1010;
int n,m,q;
int a[N][N],b[N][N];


//此抽象出来的函数，是模拟的怎么在差分数组b的指定区域上加数字
void insert(int x1,int y1,int x2,int y2,int c) {
	b[x1][y1] += c;
	b[x2+1][y1] -= c;
	b[x1][y2+1] -= c;
	b[x2+1][y2+1] += c;
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	
	//将二维数组的信息读取到数组a中
	for(int i =1;i <= n;i++) {
		for(int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	}
	
	//构建差分数组 
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= m;j++)
			//insert(i,j,i,j,a[i][j]);//传递进去的。对于a数组而言，只是一个方格，这个方格的数值是a[i][j]
			//但是对于差分数组b而言，是要处理从(1,1)到(i,j),也就构建出了基础的差分数组 
			
			//当然，也可以直接使用公式构建差分数组
			b[i][j] = a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1] ;
	}
	//q组询问，在指定区间加上c 
	while(q--){
		int x1,x2,y1,y2,c;
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
		insert(x1,y1,x2,y2,c);
	}
	
	//处理一下差分加到原数组的值
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++)
			//线性动态规划的思想 
//			b[i][j] += b[i-1][j] + b[i][j-1]-b[i-1][j-1];
			//假如使用式子构建差分数组，同理可以用式子计算最后a数组的结果了
			a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j];
	}
	
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= m;j++)
			printf("%d ",a[i][j]);
			
		cout << endl;
	}
	
	return 0;
}
