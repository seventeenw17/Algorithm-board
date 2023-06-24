/* (1)拉链法 */
// 邻接表存储
const int N = 1e5 + 3;
int h[N], e[N], ne[N], idx = 0;

// 插入
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

// 查找
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

/* (2)开放寻址法 */
const int N = 2e5 + 3, null = 0x3f3f3f3f;
int h[N];

// 插入
void insert(int x) {
    h[find(x)] = x;
}

// 查找
int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;
}
