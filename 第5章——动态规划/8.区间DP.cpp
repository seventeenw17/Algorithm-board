//DP实现
#include <bits/stdc++.h>
using namespace std;

const int N = 310, INF = 0x3f3f3f3f;
int n;
int a[N], s[N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <=  n; i++) {
            int l = i, r = i + len - 1;
            f[l][r] = INF;
            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);

        }

    cout << f[1][n] << endl;
    return 0;
}

//记忆化搜索实现
#include <bits/stdc++.h>
using namespace std;

const int N = 310, INF = 0x3f3f3f3f;
int n;
int a[N], s[N], f[N][N];

int dfs(int i, int j) {
    if (i == j) return 0;
    if (f[i][j] != INF) return f[i][j];
    for (int k = i; k <= j - 1; k++) {
        f[i][j] = min(f[i][j], dfs(i, k) + dfs(k + 1, j) + s[j] - s[i - 1]);
    }
    return f[i][j];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    memset(f,INF,sizeof(f));
    cout << dfs(1, n) << endl;
    return 0;
}
