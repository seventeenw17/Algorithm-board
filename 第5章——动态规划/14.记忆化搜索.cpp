#include <bits/stdc++.h>
using namespace std;
//滑雪
const int N = 310;
int n, m;
int h[N][N], f[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int i, int j) {
    if (f[i][j] != -1) return f[i][j];
    f[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m && h[i][j] > h[x][y])
            f[i][j] = max(f[i][j], dfs(x, y) + 1);
    }
    return f[i][j];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];

    int ans = 0;
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));

    cout << ans << endl;
    return 0;
}
