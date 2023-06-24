基本逻辑
1 初始化
	for (i: 1 ~ n)
		for (j: 1 ~ n)
			if (i == j) d[i,j] = 0;
			else d[i,j] = INF;
2 求最短路
	for (k: 1 ~ n)
		for (i: 1 ~ n)
			for (j: 1 ~ n)
				d[i,j] = min(d[i,j], d[i,k] + d[k,j]);
代码实现
int d[N][N]; //邻接(距离)矩阵
//初始化，到自己距离为0，其余为INF
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
}
//基于DP思想
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
询问：a -> b ,d[a][b]为a到b的最短路
        d[a][b] > INF/2 无最短路
