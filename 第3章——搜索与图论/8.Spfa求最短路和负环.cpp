(1)单源最短路
基本逻辑
1 d[1] = 0, d[2 ~ n] = INF;
2 第一个点入队;
    while (队列不空)
		取出队头
		for (拓展队头)
			j = e[i];
			用t更新最短路
			若t不在队列则入队
代码实现
int n, m;
int h[N], e[N], w[N], ne[N], idx; //邻接表
int que[N], hh, tt; //模拟队列|需要考虑空间问题|本来写了给去掉了
int d[N];
bool st[N]; //点是否在队列里

memset(h, -1, sizeof(h));

int spfa() {
    queue<int> que;
    //初始化距离
    memset(d, INF, sizeof(d));
    d[1] = 0; st[1] = true;
    que.push(1);//第一个点入队
    while (que.size()) {
        int t=que.front(); //取出队头
        que.pop();
        st[t] = false;
        //拓展队头
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if (!st[j]) { //如果j不在队列里则入队
                    que.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return d[n]; //若 d[n] == INF，无最短路
}
(2)*判断负环
基本逻辑
1 所有点入队
2  while (队列不空)
		取出队头
		for (拓展队头)
			j = e[i];
			用t更新最短路
				cnt[j]=cnt[t]+1;
					cnt[j]==n 则有负环
			若t不在队列则入队
代码实现
int n, m;
int h[N], e[N], w[N], ne[N], idx;
int d[N], cnt[N]; //cnt[i]到第i个点经过的边数
bool st[N];

memset(h, -1, sizeof(h));

void add(int p, int x, int c) {
    e[idx] = x;
    w[idx] = c;
    ne[idx] = h[p];
    h[p] = idx++;
}

bool spfa() {
    queue<int> que;
    //所有点入队
    for (int i = 1; i <= n; i++) {
        que.push(i);
        st[i] = true;
    }
    while (que.size()) {
        int t = que.front(); //取出队头
        que.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1; //更新经过的边数
                //经过了n条边，则至少经过了n+1个点，即肯定存在负环
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    que.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}
