二分图： 图中不含奇数奇数个点环
图的所有的点可分为两个集合，
所有边只在两个集合之间不在集合内部。

代码实现
int n, m;
int h[N], e[M], ne[M], idx; //邻接表
int cor[N]; //未染色:0，已染色:1|2

void add(int p, int x) {
    e[idx] = x;
    ne[idx] = h[p];
    h[p] = idx++;
}
(1)DFS实现
bool dfs(int u, int c) {
    cor[u] = c; //染上色
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        //和父节点同色|子树未染色但染色失败，都返回false
        if (cor[j] == c || (!cor[j] && !dfs(j, 3 - c)))
            return false;
    }
    return true;
}
void solve() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int a, b;
    /*加无向边代码省略*/
    //每次染一个连通块
    for (int i = 1; i <= n; i++) {
        if (!cor[i] && !dfs(i, 1)) {  //染色失败
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
(2)BFS实现
bool bfs(int u) {
    queue<int> que;
    cor[u] = 1; //连通块第一个点染上色1
    que.push(u); //入队
    while (que.size()) {
        int t = que.front(); //取出队头
        que.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!cor[j]) { //未染色则染上不同色后入队
                cor[j] = 3 - cor[t];
                que.push(j);
            }
            else if (cor[j] == cor[t]) //同色则返回false
                return false;
        }
    }
    return true;
}
void solve() {
    /*同上DFS做法*/
    for (int i = 1; i <= n; i++) {
        if (!cor[i] && !bfs(i)) { //染色失败
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
