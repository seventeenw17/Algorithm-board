const int N = 100010, M = 200010;
int n, m, h[N], e[M], ne[M], idx;
int hh, tt, que[N], d[N];

void add(int p, int x) {
    e[idx] = x;
    ne[idx] = h[p];
    h[p] = idx++;
}

int bfs() {
    hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i]) que[++tt] = i;

    while (hh <= tt) {
        int t = que[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (d[j] == 0) que[++tt] = j;
        }
    }
    return tt == n - 1; //完成之后从0~n-1即为拓扑序列
}

int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if (bfs()) {
        for (int i = 0; i < n; i++)
            cout << que[i] << ' ';
    }
    else cout << -1 << endl;
    return 0;
}
