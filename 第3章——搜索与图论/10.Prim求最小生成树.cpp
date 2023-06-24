基本逻辑
1 d[1 ~ n] = INF;
2 for (i: 1 ~ n)
	t为连通块外距离连通块最近的点
	将t放入连通块
	用t更新其他点到连通块的距离
代码实现
int n, m;
int g[N][N];//邻接矩阵
int d[N];   //到连通块的距离
bool st[N]; //该点是否在连通块内

int prim() {
    memset(d, INF, sizeof(d));//初始化所有距离为INF
    int ans = 0; //连通块的边权和:最小生成树
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
        }
        //如果不是第一个点且距离为INF，则该图不连通，不存在最小生成树
        if (i > 1 && d[t] == INF) return INF;
        //不是第一个点，则加上距离
        if (i > 1) ans += d[t];
        st[t] = true;//放入连通块
        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], g[t][j]);
    }
    return ans; //ans == INF时，则不存在最小生成树
}
