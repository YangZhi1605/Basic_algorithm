#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N],b[N];//a数组是原数组，b数组是差分数组
int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i = 1; i <= n;i++) 
    {
        scanf("%d",&a[i]);
        b[i] = a[i] - a[i-1];//构建差分数组
    }
    
    int l,r,c;
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&c);
        //将序列中，[l,r]之间的每个数都加上c
        b[l] += c;
        //因为会加重复，所以要减去一个c
        b[r+1] -= c;
    }
    
   
    for(int i = 1; i <= n;i++)
    {
    	//将差分结果，根据上面的式子( b[i] = a[i] - a[i-1])，统计回来
        // a[i] =  a[i-1] + b[i];
        //b数组是a数组的差分，举具体的例子而言，a[i] 对应的是b数组从开头加和到i的数值，那么线性动态规划
		//理解一下，对于当前的b[i]状态，需要的只是b[i-1]的状态了 
        b[i] += b[i-1];//有点动态规划的味道了
        printf("%d ",b[i]);
    }
    return 0;
}
