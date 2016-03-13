/***
//website:hihocode
//ID:thtfive
//《国庆出游》问题解答
**/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 101;
vector<int>G[maxn];
int path[maxn][maxn];
vector<int>order;
bool DFS(int u,int fa,vector<int>&seq,int t)
{
    seq.push_back(u);
    bool flag = true;
    if (u == t)
    {
        int sz = seq.size();
        for (int i = 1; i < sz; ++i)
        {
            int &ans = path[seq[i-1]][seq[i]];
            ++ans;
            if (ans > 1)flag = false;
        }
    }
    else
    {
        for (auto &v:G[u])
        {
            if (v != fa)
            {
                flag &= DFS(v,u,seq,t);
            }
        }
    }
    seq.pop_back();
    return flag;
}
bool check(int u,int v)
{
    vector<int>sequence;
    return DFS(u,-1,sequence,v);
}
int main()
{
    freopen("input.txt","r",stdin);
    int T,N;
    cin>>T;
    while(T--)
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)G[i].clear();
        memset(path,0,sizeof(path));
        int x,y;
        for (int i = 0; i < N-1; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        order.clear();
        order.push_back(1);
        int M;
        cin >> M;
        for (int i = 0; i < M; ++i)
        {
            cin >> x;
            order.push_back(x);
        }
        bool result = true;
        int sz = order.size();
        for (int i = 1; i < sz; ++i)
        {
            result &=check(order[i-1],order[i]);
            if (!result)break;
        }
        if (result)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
