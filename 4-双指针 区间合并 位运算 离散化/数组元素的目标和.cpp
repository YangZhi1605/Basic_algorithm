#include <cstdio>

const int N = 100010;
int a[N],b[N];

int n,m,x;
int main()
{
    scanf("%d %d %d",&n,&m,&x);
    
    for(int i = 0; i < n ;i++) scanf("%d",&a[i]);
    
    for(int i = 0; i < m;i++) scanf("%d",&b[i]);
    
    //这种应该是两个区间的双指针，调整j指针的思想和归并那儿差不多的
    //双指针迭代
    //按照正常的思想去模拟就好
    for(int i = 0 , j = m-1 ; i < n ; i++)
    {
        while(j >= 0 && a[i] + b[j] > x ) j--; //要确定j的一个基础条件 j >= 0; 因为是倒着迭代回来，假如不控制，可能就减完了
        if(j >= 0 && a[i] + b[j] == x) printf("%d %d",i,j);
    }
    
    
    return 0;
}
