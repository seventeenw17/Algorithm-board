/*区间问题贪心*/
//区间选点|最大不相交区间数量
1 每个区间按右端点排序
2 枚举每个区间
	若已有点，直接下一步
	否则选择右端点

#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
int n;
PII p[N];

bool cmp(PII& a, PII &b) {
    return a.r < b.r;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
    }
    sort(p + 1, p + 1 + n, cmp);

    int tmp = -2e9;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(tmp >= p[i].l && tmp <= p[i].r) continue;
        tmp = p[i].r;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

//区间分组
1 按照区间左端点排序
2 从前往后处理
	判断能否放入目前的组中
	(当前区间左端点是否大于某个组内区间的最大右端点/*所有组最小区间右端点*/)
		1. 存在这样的组，更新所有组最小区间右端点
		2. 不存在，则新建一个组
#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
int n;
PII p[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
    }

    sort(p + 1, p + 1 + n);
    priority_queue<int,vector<int>,greater<int>> hp;
    for (int i = 1; i <= n; i++) {
        if (!hp.size() || p[i].l <= hp.top()) hp.push(p[i].r);
        else {
            hp.pop();
            hp.push(p[i].r);
        }
    }
    cout << hp.size() << endl;
    return 0;
}

//区间覆盖
1 按照区间左端点排序
2 从前往后处理
	在所有能覆盖start的区间内选择右端点最大的区间
	将start更新为右端点的最大值
#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
int n, s, t;
PII p[N];

int main() {
    cin >> s >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
    }

    sort(p + 1, p + 1 + n);
    int ans = 0;
    bool st = false;
    for (int i = 1; i <= n; i++) {
        int j = i , ed = -2e9;
        while (j <= n && p[j].l <= s) { //双指针找到能覆盖最长的区间
            ed = max(ed, p[j].r);
            j++;
        }
        if (ed < s) { //区间的终点小于了起点
            st = false;
            break;
        }
        ans++;
        if (ed >= t) {
            st = true;
            break;
        }
        s = ed;
        i = j - 1;
    }
    if (!st) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
