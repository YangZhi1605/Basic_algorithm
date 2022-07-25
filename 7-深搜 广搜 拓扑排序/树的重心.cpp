#include <iostream>
#include <cstring>
#include <algorithm>



using namespace std;
const int N  = 1e5 + 10;
const int M = 2*N;
int n;
int h[N],ne[M],e[M],idx;
bool st[N];
int ans = N;

void add(int a,int b){
    e[idx]  = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}


int dfs(int u){
    st[u] = true;//����������������

    //ͳ���Ե�ǰ��uΪ���������ж�������
    int sum = 1;
    //ͳ����uΪ������ͨ�������������������Ƕ���
    int res = 0;

    //��ס���u,����Ϊ��㣬��������ڽӱ�
    for(int i = h[u];i != -1;i = ne[i]){
        //��ȡ��ǰλ�õ��ڽӱ������㣨�������е���ֵ��
        int j = e[i];

        if(!st[j]){
            int s = dfs(j); //���ص���jΪ���µ��������� 
            res = max(res,s);//ͳ�����ڵ��������������ֵ 
            sum += res;
        }
    }
    //��Ϊ�����ǵ�������һ��������ô���������������Ľ�㣬�����ܵ�n ��ȥ ����������
    res = max(res,n-sum);
    //���������ֵ�е���Сֵ 
    ans = min(ans,res);

    return sum;

}


int main(){
    cin >> n;
    //��ʼ���ڽӱ�
    
    memset(h,-1,sizeof h);

    // �����ڽӱ�
    for(int i = 0;i < n-1;i++){
        int a,b;
        cin >> a >>b;
        add(a,b);
        add(b,a);
    }

    dfs(1);
    cout << ans <<endl;
    return 0;
}
