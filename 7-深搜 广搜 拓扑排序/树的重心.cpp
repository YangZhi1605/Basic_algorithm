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
    st[u] = true;//标记搜索过这个点了

    //统计以当前的u为根，其下有多少子树
    int sum = 1;
    //统计以u为根，连通块中最多的子树的数量是多少
    int res = 0;

    //逮住这个u,以它为起点，遍历这个邻接表
    for(int i = h[u];i != -1;i = ne[i]){
        //获取当前位置的邻接表各个结点（及其其中的数值）
        int j = e[i];

        if(!st[j]){
            int s = dfs(j); //返回的是j为根下的子树数量 
            res = max(res,s);//统计现在的子树数量的最大值 
            sum += res;
        }
    }
    //因为深搜是单纯的搜一个方向，那么除了这个方向以外的结点，就用总的n 减去 搜索出来的
    res = max(res,n-sum);
    //答案是找最大值中的最小值 
    ans = min(ans,res);

    return sum;

}


int main(){
    cin >> n;
    //初始化邻接表
    
    memset(h,-1,sizeof h);

    // 连接邻接表
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
