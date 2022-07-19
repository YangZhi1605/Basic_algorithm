#include <iostream>

using namespace std;

const int N  = 100010;
int n ;
long long res = 0; //ȷʵ���������ݴ��˵Ļ�����������ͳ�����
int a[N],t[N];

long long merge_sort(int a[],int l ,int r)
{
    if(l >= r) return 0;
    
    int mid = l + r >> 1;
    
    res = merge_sort(a,l,mid) + merge_sort(a,mid+1,r);
    
    int i = l ,j = mid+1;
    int k = 0;
    
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) t[k++] = a[i++]; //�����ģ�����һ�£���Ϊ���ڵ�ʱ���ǲ���������Ե�
        else
        {
            //�������İɣ�
            //��ǰ��i��λ���Ѿ��Ǳ�jλ�õ����ݴ��ˣ���ô��i��j����������
            //�����j��������mid + 1 - i
            res += mid + 1 - i ;
            t[k++] = a[j++];
        }
    }
    
    while(i <= mid) t[k++] = a[i++];
    while(j <= r) t[k++] = a[j++];
    
    for(int i = l,j =0;i <= r;i++,j++) a[i] = t[j];
    
    return res;
}


int main()
{
    scanf("%d",&n);
    
    for(int i = 0; i < n;i++) scanf("%d",&a[i]);
    
    res = merge_sort(a,0,n-1);
    
    printf("%lld",res);
    
    return 0;
}

