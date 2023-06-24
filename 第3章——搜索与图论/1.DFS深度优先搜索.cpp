排列数字（经典DFS）
给定一个整数，将数字排成一排，将会有很多种排列方法。
现在，请你按照字典序将所有的排列方法输出
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, a[N];
bool st[N];

void dfs(int u) {
//达到条件则输出
    if (u == n) {
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            a[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;//复原
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}
n皇后（DFS+剪枝）
n皇后问题是指将n个皇后放在的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

现在给定整数，请你输出所有的满足条件的棋子摆法。
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
bool p[N][N];

bool check(int x, int y) {
    for (int i = 0; i < x; i++) { //判断正上方
        if (p[i][y]) return false;
    }
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) { //判断左上
        if (p[i][j]) return false;
    }
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) { //判断右上
        if (p[i][j]) return false;
    }
    return true;
}

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j]) cout << 'Q';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (check(u, j)) { //剪枝，符合条件才继续往下
            p[u][j] = true;
            dfs(u + 1);
            p[u][j] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}
