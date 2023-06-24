void quick_sort(int p[], int l, int r) {
    if (l >= r) return;
    int x = p[l + r >> 1];
    int i = l - 1,j = r + 1;
    while (i < j) {
        do i++; while (p[i] < x);
        do j--; while (p[j] > x);
        if (i < j) swap(p[i], p[j]);
    }
    quick_sort(p, l, j);
    quick_sort(p, j + 1, r);
}
