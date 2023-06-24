/* 树状数组维护前缀和 */
int n, a[N], tr[N];

int lowbit(int x) { return x & -x; }

// 在x位置加上c
void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

// 求x位置的前缀和
int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ans += tr[i];
    }
    return ans;
}
/* 树状数组求逆序对数量（空间消耗较大，一般不用） */
void solve() {
   int ans = 0;
   for (int i = n; i; i--)    {
      ans += sum(a[i] - 1) * a[i];
      add(a[i], 1);
   }
   cout << ans << endl;
}
/* 树状数组差分 */
// 初始化 | 此时tr[]为差分数组
add(i, a[i] - a[i - 1]);
// 区间增加 | [l,r]上每个数加上c
add(l, c);
add(r + 1, -c);
// 查询单点的值
sum(x);
