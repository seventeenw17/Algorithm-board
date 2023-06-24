二分图的匹配：从二分图的两个集合中选择边
所有的边之间没有公共点

二分图的匹配：从二分图的两个集合中选择边
所有的边之间没有公共点
时间复杂度：，一般不会达到
代码实现
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int p[N]; //右边点匹配到的左边点的序号
bool st[N]; //是否匹配到了左边的点

bool find(int x) {
    //遍历点左边点可达的点
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j])  {//如果还没匹配到左边的点
            st[j] = true;
            //对应右边的点还没有匹配|右边点可以有别的匹配
            if (!p[j] || find(p[j])) {
                p[j] = x;
                return true;
            }
        }
    }
    return false;
}
void solve() {
    memset(h, -1, sizeof(h));
    cin >> n1 >> n2 >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        add(a, b); //只存从左到右的边
    }
    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, 0, sizeof(st)); //每次更新st为false
        if (find(i)) ans++;
    }
    cout << ans << endl;
}

