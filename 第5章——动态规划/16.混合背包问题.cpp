//有依赖的背包问题|分组背包+树形DP
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

const int N = 110;
int n, m;
int v[N], w[N];
int h[N], e[N], ne[N], idx;
int f[N][N];

void add(int p, int x)
{
    e[idx] = x;
    ne[idx] = h[p];
    h[p] = idx++;
}

void dfs(int u)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int s = e[i];
        dfs(s);
        for (int j = m - v[u]; j >=0; j--) //分组背包 
        {
            for (int k = 0; k <= j; k++)
            {
                f[u][j] = max(f[u][j], f[u][j - k] + f[s][k]);
            }
        }
    }
    for (int j = m; j >= v[u]; j--)
    {
        f[u][j] = f[u][j - v[u]] + w[u];
    }
    for (int j = 0; j < v[u]; j++) //比根节点小的全都置为0 
    {
        f[u][j] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int p, root;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;
        else add(p, i);
    }
    
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
} 
