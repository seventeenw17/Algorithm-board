// 给定一个大小为1e6的数组。有一个大小为的滑动窗口，它从数组的最左边移动到最右边。
// 你只能在窗口中看到个数字。每次滑动窗口向右移动一个位置。
// 请确定滑动窗口位于每个位置时窗口内的最大值。
#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int a[N], que[N], hh, tt;
int n, k;

int main() {
    scanf("%d%d" ,&n, &k);
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        while (hh <= tt && i- k + 1 > que[hh]) hh++;
        while (hh <= tt && a[que[tt]] >= a[i]) tt--;
        que[++tt] = i;
        if (i >= k - 1) printf("%d ", a[que[hh]]);
    }
    printf("\n");
    return 0;
}
