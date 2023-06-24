void merge_sort(int p[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;

    merge_sort(p, l, mid);
    merge_sort(p, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if(p[i] <= p[j]) temp[k++] = p[i++];
        else temp[k++] = p[j++];
    }
    while (i <= mid) temp[k++] = p[i++];
    while (j <= r) temp[k++] = p[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        p[i] = temp[j];
}

// 求逆序对
int merge_sort(int p[], int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    int sum = merge_sort(p, l, mid) + merge_sort(p, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (p[i] <= p[j]) temp[k++] = p[i++];
        else {
            temp[k++] = p[j++];
            sum += mid - i + 1;
        }
    }
    while (i <= mid) temp[k++] = p[i++];
    while (j <= r) temp[k++] = p[j++];
    for (i = l, j = 0; i <= r; i++, j++) 
        p[i] = temp[j];
    return sum;
}