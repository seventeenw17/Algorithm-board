// head:头节点,e:存储元素,ne:存储下标
int head, e[N], ne[N], idx;

// 初始化
void init() {
    head = -1;
    idx = 0;
}

// 在头部插入一个数
void insertByHead(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 在第k个数后面插入，传入k-1
void insertBehind(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 删除第k个插入的数，传入k-1
void deleteBehind(int k) {
    ne[k] = ne[ne[k]];
}

// 打印输出
void print() {
    for (int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);
    printf("\n");
}
