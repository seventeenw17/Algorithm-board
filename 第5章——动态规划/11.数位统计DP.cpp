//数位统计DP

#include <bits/stdc++.h>
using namespace std;

int a, b;
vector<int> nums;

int get(int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i -- )
        res = res * 10 + nums[i];
    return res;
}

int power10(int x) {
    int res = 1;
    while (x--)
        res *= 10;
    return res;
}

int count(int n, int x) {
    if (!n) return 0;
    while (n) {
        nums.push_back(n % 10);
        n /= 10;
    }
    n = nums.size();

    int ans = 0;
    for (int i = n - 1 - !x; i >= 0; i--) {
        if (i < n - 1) {
            ans += get(n - 1, i + 1) * power10(i);
            if (!x) ans -= power10(i);
        }
        if (nums[i] == x) ans += get(i - 1, 0) + 1;
        else if (nums[i] > x) ans += power10(i);
    }
    nums.clear();
    return ans;
}

int main() {
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b);
        for (int i = 0; i < 10; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';

        cout << endl;
    }
    return 0;
}

//记忆化搜索
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int l, r, dp[N][N], len, a[N];

int dfs(int pos, int pre, int limit) {
    if (!pos) return 1;
    if (!limit && dp[pos][pre] != -1) return dp[pos][pre];
    int res = 0, up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i ++) {
        if (i == 4 || (i == 2 && pre == 6)) continue;
        res += dfs(pos - 1, i, limit && i == up);
    }
    return limit ? res : dp[pos][pre] = res;
}

int cal(int x) {
    memset(dp, -1, sizeof dp);
    len = 0;
    while (x) a[++ len] = x % 10, x /= 10;
    return dfs(len, 0, 1);
}

signed main() {
    while (cin >> l >> r, l || r) {
        cout << cal(r) - cal(l - 1) << endl;
    }
}
