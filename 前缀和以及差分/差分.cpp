#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N],b[N];//a������ԭ���飬b�����ǲ������
int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i = 1; i <= n;i++) 
    {
        scanf("%d",&a[i]);
        b[i] = a[i] - a[i-1];//�����������
    }
    
    int l,r,c;
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&c);
        //�������У�[l,r]֮���ÿ����������c
        b[l] += c;
        //��Ϊ����ظ�������Ҫ��ȥһ��c
        b[r+1] -= c;
    }
    
   
    for(int i = 1; i <= n;i++)
    {
    	//����ֽ�������������ʽ��( b[i] = a[i] - a[i-1])��ͳ�ƻ���
        // a[i] =  a[i-1] + b[i];
        //b������a����Ĳ�֣��پ�������Ӷ��ԣ�a[i] ��Ӧ����b����ӿ�ͷ�Ӻ͵�i����ֵ����ô���Զ�̬�滮
		//���һ�£����ڵ�ǰ��b[i]״̬����Ҫ��ֻ��b[i-1]��״̬�� 
        b[i] += b[i-1];//�е㶯̬�滮��ζ����
        printf("%d ",b[i]);
    }
    return 0;
}
