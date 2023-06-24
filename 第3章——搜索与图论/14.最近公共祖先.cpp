（1）树上倍增法
时间复杂度：O((n + m) * log(n))
int n, m, high; // high:树的高度,high = log2(n)
int h[N], e[M], ne[M], idx;
int d[N], f[N][20];// d[i]:i点的深度，f[i][j]:从i点向上走2^j步到的点
queue<int> que;

void add(int p, int x) {
    e[idx] = x, ne[idx] = h[p], h[p] = idx++;
}
// BFS预处理
void bfs(int u) {
    memset(d, INF, sizeof(d));
    d[0] = 0, d[u] = 1;
    que.push(u);
    while (que.size()) {
        int t = que.front();
        que.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + 1) {
                d[j] = d[t] + 1;
                que.push(j);
                f[j][0] = t; // 二进制预处理
                for (int k = 1; k <= high; k++) {
                    f[j][k] = f[f[j][k - 1]][k - 1];
                }
            }
        }
    }
}
// 回答询问
int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    // u和v跳到同一层
    for (int i = high; i >= 0; i--) {
        if (d[f[u][i]] >= d[v]) u = f[u][i];
    }
    if (u == v) return u;
    // u和v一起向上走
    for (int i = high; i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
（2）Tarjan算法
基于DFS和并查集，时间复杂度：O(n + m)
下为树中两点距离，使用Tarjan求LCA
typedef pair<int, int> PII;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int d[N]; // 到根节点距离
int p[N];
int ans[M];
int st[N]; // 0:未遍历，1:正在遍历，2:已经遍历过
vector<PII> query[N]; // query[u].first:查询的另一个点，query[u].second:查询的编号

void init() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void add(int p, int x, int c) {
    e[idx] = x, w[idx] = c, ne[idx] = h[p], h[p] = idx++;
}
// DFS预处理
void dfs(int u, int fa) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        d[j] = d[u] + w[i];
        dfs(j, u);
    }
}
// 进行递归及并查集操作
void tarjan(int u) {
    st[u] = 1; // 正在遍历
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            tarjan(j);
            p[j] = u;
        }
    }
    // 遍历所有和u相关的查询
    for (auto [v, id] : query[u]) {
        if (st[v] == 2) {
            int anc = find(v);
            ans[id] = d[u] + d[v] - d[anc] * 2;
        }
    }
    st[u] = 2; // 已经遍历过
}

void solve() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a != b) {
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
    }
    init();
    dfs(1, -1);
    tarjan(1);
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}
