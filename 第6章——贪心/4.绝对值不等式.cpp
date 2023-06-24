//绝对值不等式
//货仓选址

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i] - a[n / 2 + 1]);
    }
    cout << ans << endl;
    return 0;
}

