//混合背包问题|01+完全+多重 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
int f[N];

int main()
{
    cin >> n >> m;
    int v, w, s;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> s;
        if (s == 0) //完全背包 
        {
            for (int j = v; j <= m; j++)
            {
                f[j] = max(f[j], f[j - v] + w);
            }
        }
        else if (s == -1) //01背包 
        {
            for (int j = m; j >= v; j--)
            {
                f[j] = max(f[j], f[j - v] + w);
            }
        }
        else //多重背包+二进制优化 
        {
            for (int k = 1; k <= s; k *= 2)
            {
                for (int j = m; j >= k * v; j--)
                {
                    f[j] = max(f[j], f[j - k * v] + k * w);
                }
                s -= k;
            }
            if (s)
            {
                for (int j = m; j >= s * v; j--)
                {
                    f[j] = max(f[j], f[j - s * v] + s * w);
                }
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}
