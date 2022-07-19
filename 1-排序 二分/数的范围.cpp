#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010 ;
int q[N];
int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    
    //录入n个信息
    for(int i= 0; i < n;i++) scanf("%d",&q[i]);
    
    //m个询问
    for(int i = 0; i < m;i++)
    {
        int x;
        scanf("%d",&x);
        
        //通过作图+理论分析，其实还是不恼火的
        //先确定左端点
        int l = 0, r = n-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            //把这个二分出来的mid和x做比较
            if(q[mid] >= x) r = mid;
            else l = mid +1;
        }
        
        if(q[l] == x)
        {
            cout << l <<' ';
            
            r = n-1;
            //确定右端点
            while(l < r)
            {
                int mid = l+r+1 >> 1;//这里按照之前的理解来分析的话，直接就裸写 l+r >> 1。再通过后面代码分析要不要补上1
                if(q[mid] <= x) l = mid;
                else r = mid -1;
            }
            
            cout << r <<endl;
            
        }else cout << "-1 -1" << endl;
    }
    
    return 0;
}
