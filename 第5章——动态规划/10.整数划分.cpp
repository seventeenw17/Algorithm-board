//数字划分

//完全背包
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n;
int f[N];

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = f[j] % mod + f[j - i] % mod;

    cout << f[n] << endl;
    return 0;
}

//DP
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n, f[N][N];

int main() {
    cin >> n;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j - 1] % mod + f[i - j][j] % mod;

    int ans = 0;
    for (int j = 1; j <= n; j++)
        ans = ans % mod + f[n][j] % mod;

    cout << ans << endl;
    return 0;
}

