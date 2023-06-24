// 一维
// a[]为原数组，b[]为差分数组
for (int i = 1; i <= n; i++) {
    b[i] += a[i];
    b[i + 1] -= a[i];
}
// 将l到r的每个值加上c
b[l] += c;
b[r + 1] -= c;
// 返回原数组
for (int i = 1; i <= n; i++)
    b[i] += b[i - 1];

// 二维
// a[][]为原数组，b[][]为差分数组
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        b[i][j] += a[i][j];
        b[i + 1][j] -= a[i][j];
        b[i][j + 1] -= a[i][j];
        b[i + 1][j + 1] += a[i][j];
    }
}
// 将(x1,y1)到(x2,y2)的每个数加上c
b[x1][y1] += c;
b[x2 + 1][y1] -= c;
b[x1][y2 + 1] -= c;
b[x2 + 1][y2 + 1] += c;
// 返回原数组
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
