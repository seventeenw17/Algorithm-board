高斯消元解线性方程组
枚举每一列
1 找到该列元素绝对值最大的行
2 将该行换到最上面
3 将下面元素变为1

const int N = 110, INF = 0x3f3f3f3f;
const double eps = 1e-7;
int n;
double a[N][N]; //增广矩阵

int gauss() {
    int c, r; //列和行
    for (c = 0, r = 0; c < n; c++) {
        //找到该列元素绝对值最大的行
        int t = r;
        for (int i = r; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        }
        //如果该列最大元素为0，直接下一列
        if (fabs(a[t][c]) < eps) continue;
        //将该行换到最上面
        for (int i = c; i <= n; i++)
            swap(a[t][i], a[r][i]);

        //最前面系数化为1
        for (int i = n; i >= c; i--)
            a[r][i] /= a[r][c];

        //将下方元素化为0
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > eps) {
                for (int j = n; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }
    if (r < n) { //非0行的数量小于n，即增广矩阵的秩小于n
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) return 0; //无解
        }
        return INF; //无穷多解
    }
    //求唯一解放入a[0 ~ n-1][n]中
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 1; //有唯一解
}

