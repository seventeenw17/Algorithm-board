基本框架
1 初始状态入队
2 循环while(que.size()) 取出队头进行拓展
例题 走迷宫
给定一个N*M的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可通过的墙壁。
最初，有一个人位于左上角(1, 1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角(n, m)处，至少需要移动多少次。
数据保证(1, 1)处和(n, m)处的数字为，且一定至少存在一条通路。
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
PII que[N*N]; //数组模拟队列
int hh, tt;
int n, m ,p[N][N], d[N][N];
int dx[] = {0, 1, 0, -1}, dy[]={1, 0, -1, 0};

bool check(int x1, int y1) {
return (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m
		&& p[x1][y1] == 0 && d[x1][y1] == -1);
}

int bfs() {
    memset(d, -1, sizeof(d));
    hh = 0, tt = -1;
    que[++tt] = {1, 1};
    d[1][1] = 0;
    while (hh <= tt) {
        PII tp = que[hh++]; //取队头
        for (int i = 0; i < 4; i++) {
            int x1 = tp.x + dx[i], y1 = tp.y + dy[i];
            if (check(x1, y1)) {
                d[x1][y1] = d[tp.x][tp.y] + 1;
                que[++tt] = {x1, y1};
            }
        }
    }
    return d[n][m];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> p[i][j];

    cout << bfs() << endl;
    return 0;
}
