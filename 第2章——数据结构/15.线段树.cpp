/* 线段树维护区间最值 */
// 线段树结构体
struct SegmentTree {
    int val;
    int l, r;
}tr[N << 2];

// 更新值
void pushup(int u) {
    tr[u].val = max(tr[u << 1].val, tr[u << 1 | 1].val);
}

// 建树
void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) tr[u].val = a[l];
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

// 单点修改 | 将a[x]的值修改为v
void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) tr[u].val = v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

// 区间查询
int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].val; // [l,r]覆盖了当前区间
    int mid = l + r >> 1;
    int v = 0;
    if (l <= mid) v = max(v, query(u << 1, l, r)); // 左子节点有重叠
    if (r > mid) v = max(v, query(u << 1 | 1, l, r)); // 右子节点有重叠
    return v;
}

/* 线段树差分，带延迟标记 */
// 线段树结构体
struct SegmentTree {
    int sum;
    int lazy;
    int l, r;
}tr[N << 2];

// 更新和
void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

// 建树
void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) tr[u].sum = a[l];
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

// 延迟标记向下传递
void pushdown(int u) {
    if (tr[u].lazy) { // 节点u带标记
        // 更新左右子节点
        tr[u << 1].sum += tr[u].lazy * (tr[u << 1].r - tr[u << 1].l + 1);
        tr[u << 1 | 1].sum += tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
        // 给左右子节点进行延迟标记
        tr[u << 1].lazy += tr[u].lazy;
        tr[u << 1 | 1].lazy += tr[u].lazy;
        tr[u].lazy = 0;
    }
}

// 区间修改 | 将[l, r]的值增加c
void modify(int u, int l, int r, int c){
    if (l <= tr[u].l && r >= tr[u].r) { // 完全覆盖
        tr[u].sum += c * (tr[u].r - tr[u].l + 1); // 更新节点信息
        tr[u].lazy += c; // 进行延迟标记
    } else {
        pushdown(u); // 下传延迟标记
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, c);
        if (r > mid) modify(u << 1 | 1, l, r, c);
        pushup(u);
    }
}

// 区间查询 | [l, r]区间和
int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].sum; // [l, r]覆盖了当前区间
    pushdown(u); // 下传延迟标记
    int mid = tr[u].l + tr[u].r >> 1;
    int ans = 0;
    if (l <= mid) ans += query(u << 1, l, r); // 左子节点有重叠
    if (r > mid) ans += query(u << 1 | 1, l, r); // 右子节点有重叠
    return ans;
}
