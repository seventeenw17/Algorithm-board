// 分别存储数据，前节点和后节点，已用节点数量
int e[N], l[N], r[N], idx;

// 初始化
void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 在第k个插入的数的右端插入一个数
// 最左端插入：insert(0,x)
// 最右端插入：insert(l[1],x)
// 第k个插入的数左侧插入：insert(l[k+1],x)
// 第k个插入的数右侧插入：insert(k+1,x)
void insertR(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

// 删除第k个插入的数，传入k+1
void deletek(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

// 从左到右打印
void print() {
    for (int i = r[0]; i != 1; i = r[i])
        printf("%d ",e[i]);
}
