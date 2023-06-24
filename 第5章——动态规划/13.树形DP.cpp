//树形DP
//没有上司的舞会
#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
int n, a[N];
int h[N], e[N], ne[N], idx;
int f[N][2];
bool st[N];

void add(int p, int x) {
    e[idx] = x;
    ne[idx] = h[p];
    h[p] = idx++;
}

void dfs(int u) {
    f[u][1] = a[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main() {
    memset(h, -1, sizeof(h));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int a, b;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        add(b, a);
        st[a] = true;
    }
    int boss = 1;
    while (st[boss]) boss++;

    dfs(boss);
    cout << max(f[boss][0], f[boss][1]) << endl;
    return 0;
}
