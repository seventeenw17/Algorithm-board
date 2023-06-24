// 判断树根
p[x] == x?
// 求集合编号
while (p[x] != x) x = p[x];
// 合并集合，x1是x集合编号，y1是y集合编号
p[x] = y1; / p[y] = x1;

/* (1)普通并查集 */
//并查集初始化 | 每个节点是一个集合
void init() {
    for (int i = 1; i <= n; i++) p[i] = i;
}

// 普通查找 + 路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 合并a,b两个数所在集合
void merge(int a, int b) {
    p[find(a)] = find(b);
}

/* (2)维护集合元素个数 */
// 并查集初始化 | 每个节点是一个集合 | 每个集合元数个数为1
void init() {
    for (int i = 1; i<=n; i++) {
        p[i] = i;
        s[i] = 1;
    }
}

// 普通查找 + 路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 合并集合 + 加和
void merge(int a, int b) {
    if (find(a) == find(b)) // 已经在同一集合当中
        return;
    s[find(b)] += s[find(a)];
    p[find(a)] = find(b);
}

/* (3)维护到根节点距离 */
// 并查集初始化 | 每个节点是一个集合
void init() {
    for (int i = 1; i <= n; i++) p[i] = i;
}
// 普通查找 + 路径压缩 + 距离压缩
int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}
// 合并集合 + 加和
void merge(int a, int b) {
    if (find(a) == find(b)) // 已经在同一集合当中
        return;
    p[find(a)] = find(b);
    d[find(a)] // 根据题目而定
}
