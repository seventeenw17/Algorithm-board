// 二进制下最后一位1的权重
int lowbit(int x) {
    return x & -x;
}

// 二进制下1的数量
int pop_count(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x = x & (x - 1);
    }
    return cnt;
}
