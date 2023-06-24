容斥原理

//能被整除的数
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=22;
int n, m;
int p[N];

signed main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> p[i];
    int ans = 0;
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, cnt = 0; //t:乘积，cnt:当前集合元素数量
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                if (t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
                cnt++;
            }
        }
        if (t != -1) {
            if (cnt % 2) ans += n / t;
            else ans -= n / t;
        }
    }
    cout << ans << endl;
    return 0;
}
