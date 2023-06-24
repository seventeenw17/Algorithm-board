树与图的存储
无向图==双端有向图 // 添加两条相互的边
树==无环连通图

1. 稠密图：邻接矩阵
// g[i][j]表示从i到j的一条有向边
bool g[N][N]; // 存储0|1，可达或不可达
int g[N][N]; // 存储边权
// 初始化
for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (i == j) g[a][b] = 0;
		else g[a][b] = INF;
// 添加从a到b的边，边权为c
g[a][b] = c;

2. 稀疏图：邻接表
// 数组模拟链表
int h[N];
int e[M], w[M], ne[M], idx;
// 初始化
memset(h, -1, sizeof(h));
// 添加一条p到x的边，边权为c
e[idx] = x;
w[idx] = c;
ne[idx] = h[p];
h[p] = idx++;

3. vector存图
vector<int> g[N];
vector<pair<int, int>> g[N];
// 添加u到v的边
g[u].push_back(v);
// 添加u到v权值为w的边
g[u].push_back({v, w});
