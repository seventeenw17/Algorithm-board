(1)普通Nim游戏
Nim游戏先手必胜，当且仅当a1 ^ a2 ^ ... ^ an = 0
#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
    cin >> n;
    int sum = 0;
    while (n--)
    {
        cin >> x;
        sum ^= x;
    }
    if (sum) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
(2)集合Nim游戏，sg函数的应用
#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 10010;
int n, k, x;
int s[N], f[M];

int sg(int x) {
    if (f[x] != -1) return f[x];
    unordered_set<int> g;
    for (int i = 0; i < k; i++) {
        int sum = s[i];
        if (x >= sum) g.insert(sg(x - sum));
    }
    for (int i = 0;; i++)
        if (!g.count(i)) return f[x] = i;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> s[i];
    memset(f, -1, sizeof(f));
    cin >> n;
    int sum = 0;
    while (n--) {
        cin >> x;
        sum ^= sg(x);
    }
    if (sum) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
