#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;
int n ,m;
char a[N], b[N];
int f[N][N];

int main() {
    cin >> n >> a + 1 >> m >> b + 1;
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; j <= m; j++) f[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    }

    cout << f[n][m] << endl;
    return 0;
}
