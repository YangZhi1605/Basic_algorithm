#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n;
int a[N];

void qui_sort(int a[],int l,int r)
{
    //���õݹ�߽�
    if(l >= r) return;
    
    int i = l-1;
    int j = r+1;
    //ȷ����ǰ���ֿ������ڵ����Ƚϵ��м�ֵ
    int mid = a[(i+j) >>1];
    
    while(i < j)
    {
        //�������
        do i++; while(a[i] < mid);
        do j--; while(a[j] > mid);
        
        printf("��ǰ���е���%d\n",mid);
        printf("��ǰ��i = %d,��ǰ��j = %d,���뽻����a[i] = %d,a[j] = %d\n",i,j,a[i],a[j]);
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
