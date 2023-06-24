(1)普通Dijkstra，时间复杂度：，适用于稠密图
基本逻辑
1 d[1] = 0, d[2 ~ n] = INF;
2 for (i: 1 ~ n) //每次循环确定起点到一个点的最短距离
	t：不在st中，且距离最近的点 //每次找当前最近的未确定最短路的点
	将t放入s
	用t更新到其它的距离
代码实现
int n, m;   //点数、边数
int g[N][N];//邻接矩阵存储稠密图
int d[N];   //最短距离
bool st[N]; //该点是否已求最短路

//初始所有点之间都没有边
memset(g, INF, sizeof(g));

int dijkstra() {
    //初始化所有点到1距离为INF
    memset(d, INF, sizeof(d));
    d[1] = 0;//第一个点为0
    for (int i = 1; i <= n; i++) {
        int t = -1;
        //每次找出距离1最近的点并更新其最短路
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
        }
        st[t] = true;
        //用该点去求的到其他可达的点的距离
        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], d[t] + g[t][j]);
    }
    return d[n]; //若 d[n]==INF，则无最短路
}
(2)堆优化Dijkstra，时间复杂度：，适用于稀疏图
基本逻辑
1 d[1] = 0, d[2 ~ n] = INF;
2 第一个点入堆
3 while (堆不为空)
	 取堆顶并弹出
	 若已确定最短路则continue
	 拓展堆顶
	 更新最短路，入堆
代码实现
typedef pair<int,int> PII; //first:到1的距离|second:点编号
int n, m;  //点数、边数
int h[N], e[M], w[M], ne[M], idx; //邻接表存储稀疏图
int d[N];
bool st[N];

memset(h, -1, sizeof(h));

int dijkstra() {
    //初始所有点到1距离为INF
    memset(d, INF, sizeof(d));
    d[1] = 0;
    //创建PII的小根堆|first:到1的距离，second:点编号
    priority_queue<PII,vector<PII>,greater<PII>> que;
    //第一个点入堆
    que.push({0, 1});
    while (hp.size()) {
        //取出堆顶
        PII t = que.top();
        que.pop();
        int u = t.second, dist = t.first;
        //如果已经确定则直接下一次
        if (st[u])   continue;
        st[u] = true; //为true
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > dist + w[i]) {
                d[j] = dist + w[i];
                //入堆
                que.push({d[j], j});
            }
        }
    }
    return d[n]; //若 d[n]==INF，则无最短路
}
