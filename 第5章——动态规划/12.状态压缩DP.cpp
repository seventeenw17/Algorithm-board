//状态压缩DP
//蒙德里安的梦想 |普通写法
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 12, M = 1 << N;
int n, m, f[N][M]; //列和列可能的状态
bool st[M];

void solve() {
    memset(f, 0, sizeof(f));
    //预处理每个状态
    for (int i = 0; i < 1 << n; i++) {
        int cnt = 0; //连续0的个数
        st[i] = true;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1)  { //i二进制形式下的第j位是否为1
                //看前面连续0的个数，若为奇数则不合法
                if (cnt & 1) st[i] = false; cnt = 0; //计数清零
            }
            else cnt++;
        }
        //判断最下面的一段的连续0的个数
        if (cnt & 1) st[i] = false;
    }
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 1 << n; j++)
            for (int k = 0; k < 1 << n; k++) {
                //j&k==0，无重叠放置的
                //j|k，考虑第i列和i-1,i-2列的状态，两列均没有连续奇数个空格
                if (!(j & k) && st[j | k]) f[i][j] += f[i - 1][k];
            }

    cout << f[m][0] << endl;
}

signed main() {
    while (cin >> n >> m) {
        if (!(m || n)) break;
        solve();
    }
    return 0;
}

//蒙德里安的梦想 |去除无效状态
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 12, M = 1 << N;
int n, m;
int f[N][M]; //列和列可能的状态
bool st[M];
vector<int> state[M]; //存储合法状态

void solve() {
    memset(f, 0, sizeof(f));
    //预处理每个状态
    for (int i = 0; i < 1 << n; i++) {
        int cnt = 0; //连续0的个数
        st[i] = true;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) { //i二进制形式下的第j位是否为1
                //看前面连续0的个数，若为奇数则不合法
                if (cnt & 1) st[i] = false;
                cnt = 0; //计数清零
            }
            else cnt++;
        }
        //判断最下面的一段的连续0的个数
        if (cnt & 1) st[i] = false;
    }

    //预处理所有状态，只留下合法状态
    for (int j = 0; j < 1 << n; j++) {
        state[j].clear(); //清除上次解答
        for (int k = 0; k < 1 << n; k++) {
            //j&k==0，无重叠放置的
            //j|k，考虑第i列和i-1,i-2列的状态，两列均没有连续奇数个空格
            if (!(j & k) && st[j | k]) state[j].push_back(k);
        }
    }

    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 1 << n; j++)
            for (auto k: state[j])
                f[i][j] += f[i - 1][k];

    cout << f[m][0] << endl;
}

signed main() {
    while (cin >> n >> m) {
        if (!(m || n)) break;
        solve();
    }
    return 0;
}


//最短Hamilton路径
#include <bits/stdc++.h>
using namespace std;

const int N = 21, M = 1 << N, INF = 0x3f3f3f3f;
int n, d[N][N], f[M][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];

    memset(f, INF, sizeof(f));
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if((i - (1 << j)) >> k & 1) //路径中包含j点
                    f[i][j] = min(f[i][j], f[i - (1 << j)][k] + d[k][j]);
                }
            }

    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}
