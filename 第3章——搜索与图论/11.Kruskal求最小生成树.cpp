基本逻辑
1 所有边权重从小到大排序
2 遍历所有边
	找到两端点的父节点
	if(fa!=fb)
		b放入连通块
		更新结果
代码实现
int p[N]; //并查集
//结构体存边
struct Edge {
    int a, b, w;
}e[M];
//按照边权重排序
bool cmp(Edge& e1, Edge& e2) { return e1.w < e2.w; }
//初始化并查集
void init() {
    for(int i = 1; i <= n; i++) p[i] = i;
}
//查找父节点+路径压缩
int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int kruskal() {
    int ans = 0, cnt = 0; //cnt:连通块内边的数量
    sort(e + 1, e + 1 + m, cmp); //按边权重从小到大排序
    for (int i = 1; i <= m; i++) { //遍历每条边
        int a = e[i].a, b = e[i].b, w = e[i].w;
        int fa = find(a), fb = find(b);
        if (fa != fb) {
            p[fa] = fb; //放入连通块
            ans += w;
            cnt++;
        }
    }
    if (cnt < n - 1) return INF; //连通块内边数<n-1，则该图不连通，无最小生成树
    else return ans;
}
