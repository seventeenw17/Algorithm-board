基本逻辑
1 d[1] = 0, d[2 ~ n] = INF;
2 for (i: 1 ~ k)
	 for (j: 1 ~ m) //遍历每条边
		d[b] = min(d[b], d[a] + w)
代码实现
//使用结构体存边，从a到b权重为w的边
struct Edge {
    int a, b, w;
}e[M];
int n, m, k; //n个点m条边，求不超过k条边的最短路
int d[N],bp[N]; //bp备份上一次的结果，避免连续更新

int ford() {
    memset(d, INF, sizeof(d)); //初始化
    d[1] = 0;
    for (int i = 1; i <= k; i++) {
        memcpy(bp, d, sizeof(d));//备份|防止连续更新
        for (int j = 1; j <= m; j++)  { //遍历每条边
            int a = e[j].a, b = e[j].b, w = e[j].w;
            d[b] = min(d[b], bp[a] + w);
        }
    }
    return d[n]; //若 d[n] > INF / 2:无最短路
}
