// 将区间[l, r]分为[l, mid]和[mid + 1, r]
// 求升序序列中第一个>=x的值
int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;

        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]分为[l, mid - 1]和[mid, r] |注意此时mid的选取
// 求升序序列中最后一个<=x的值
int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;

        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
