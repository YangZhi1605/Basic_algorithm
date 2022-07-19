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
    
    //¼��n����Ϣ
    for(int i= 0; i < n;i++) scanf("%d",&q[i]);
    
    //m��ѯ��
    for(int i = 0; i < m;i++)
    {
        int x;
        scanf("%d",&x);
        
        //ͨ����ͼ+���۷�������ʵ���ǲ��ջ��
        //��ȷ����˵�
        int l = 0, r = n-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            //��������ֳ�����mid��x���Ƚ�
            if(q[mid] >= x) r = mid;
            else l = mid +1;
        }
        
        if(q[l] == x)
        {
            cout << l <<' ';
            
            r = n-1;
            //ȷ���Ҷ˵�
            while(l < r)
            {
                int mid = l+r+1 >> 1;//���ﰴ��֮ǰ������������Ļ���ֱ�Ӿ���д l+r >> 1����ͨ������������Ҫ��Ҫ����1
                if(q[mid] <= x) l = mid;
                else r = mid -1;
            }
            
            cout << r <<endl;
            
        }else cout << "-1 -1" << endl;
    }
    
    return 0;
}
