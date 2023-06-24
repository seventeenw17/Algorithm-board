#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n;
int a[N][N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    memset(f, -INF, sizeof(f));
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];

    int ans = -INF;
    for (int j = 1; j <= n; j++)
        ans = max(ans, f[n][j]);
    cout << ans << endl;
    return 0;
}
