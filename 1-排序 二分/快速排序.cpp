#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n;
int a[N];

void qui_sort(int a[],int l,int r)
{
    //设置递归边界
    if(l >= r) return;
    
    int i = l-1;
    int j = r+1;
    //确定当前这轮快排用于迭代比较的中间值
    int mid = a[(i+j) >>1];
    
    while(i < j)
    {
        //常规迭代
        do i++; while(a[i] < mid);
        do j--; while(a[j] > mid);
        
        printf("当前的中点是%d\n",mid);
        printf("当前的i = %d,当前的j = %d,参与交换的a[i] = %d,a[j] = %d\n",i,j,a[i],a[j]);
        if(i < j) swap(a[i],a[j]);
    }
    
    qui_sort(a,l,j);
    qui_sort(a,j+1,r);
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n;i++) cin >> a[i];
    
    qui_sort(a,0,n-1);
    
    for(int i = 0; i < n;i++) cout << a[i] <<' ';
    return 0;
}
