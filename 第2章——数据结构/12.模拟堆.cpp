//STL模板
优先队列： priority_queue<T> //默认为大根堆
创建小根堆： priority_queue<T,vector<T>,greater<T>>

//模拟堆|小根堆为例
1.插入一个数：heap[++tt]=x; up(tt);
2.求最小值：heap[1];
3.删除最小值：heap[1]=heap[tt]; tt--; down(1);
4.删除第k个节点：head[k]=heap[tt]; tt--; down(k); up(k);
5.将第k个节点数字改为x：heap[k]=x; down(k); up(k);
int n, tt, h[N]; //tt:堆内现有元素个数

// 初始化堆：O(n)
void init() {
    for (int i = n / 2; i > 0; i--) down(i);
}

// 插入元素：O(log n)
void insert(int x) {
    //从堆底插入然后up
    h[++tt] = x;
    up(tt);
}

// 向上调整
void up(int p) {
    while (p > 1) {
        if (h[p] > h[p / 2]) {
            swap(h[p], h[p / 2]);
            p /= 2;
        }
        else break;
    }
}

// 向下调整
void down(int p) {
    int s = p * 2;
    while (s <= tt) {
        if (s < tt && h[s] < h[s + 1]) s++;
        if (h[s] > h[p]) {
            swap(h[s], h[p]);
            p = s; s = p * 2;
        }
        else break;
    }
}

// 删除根节点：用尾节点覆盖根节点，再向下调整
void extract() {
    h[1] = h[tt--];
    down(1);
}

// 删除第k个节点： 用尾节点覆盖第k个节点，再向上或下调整
void remove(int k) {
    h[k] = h[tt--];
    up(k); down(k);
}

// 将第k个节点数字改为x
void alter(int k, int x) {
    h[k] = x;
    up(k); down(k);
}
