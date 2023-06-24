//推公式
//耍杂技的牛

#include <bits/stdc++.h>
#define w first
#define s second
using namespace std;

typedef pair<int,int> PII;
const int N = 50010, INF = 0x3f3f3f3f;
int n;
PII p[N];

bool cmp(PII& a, PII& b) {
    return a.w + a.s < b.w + b.s;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].w >> p[i].s;
    }
    sort (p + 1, p + 1 + n, cmp);

    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        p[i].w += p[i - 1].w;
        ans = max(ans, p[i - 1].w - p[i].s);
    }
    cout << ans << endl;
    return 0;
}
