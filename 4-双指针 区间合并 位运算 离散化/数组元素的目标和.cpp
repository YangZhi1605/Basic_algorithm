#include <cstdio>

const int N = 100010;
int a[N],b[N];

int n,m,x;
int main()
{
    scanf("%d %d %d",&n,&m,&x);
    
    for(int i = 0; i < n ;i++) scanf("%d",&a[i]);
    
    for(int i = 0; i < m;i++) scanf("%d",&b[i]);
    
    //����Ӧ�������������˫ָ�룬����jָ���˼��͹鲢�Ƕ�����
    //˫ָ�����
    //����������˼��ȥģ��ͺ�
    for(int i = 0 , j = m-1 ; i < n ; i++)
    {
        while(j >= 0 && a[i] + b[j] > x ) j--; //Ҫȷ��j��һ���������� j >= 0; ��Ϊ�ǵ��ŵ������������粻���ƣ����ܾͼ�����
        if(j >= 0 && a[i] + b[j] == x) printf("%d %d",i,j);
    }
    
    
    return 0;
}
