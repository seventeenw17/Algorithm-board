//DP：O(n^2)
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;
int n;
int a[N], f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
	    if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
	}
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}

//二分贪心：O(n*log n)
#include <bits/stdc++.h>
using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int n;
int a[N], p[N]; //p[]:不同长度上升子序列的结尾数字的最小值

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int len = 0;
    p[0] = -INF;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (p[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        p[r + 1] = a[i];
    }
    cout << len << endl;
    return 0;
}
