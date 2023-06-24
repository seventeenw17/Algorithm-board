#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
//v[i][j]表示第i类物品的第j个的体积
//w[i][j]表示第i类物品的第j个的价值
int v[N][N], w[N][N], s[N], f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s[i]; k++)
                if (v[i][k] <= j) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;
    return 0;
}
