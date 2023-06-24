//Huffman树贪心
//合并果子

#include <bits/stdc++.h>
using namespace std;

int n,x;

int main() {
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> hp;
    while (n--) {
        cin >> x;
        hp.push(x);
    }

    int ans = 0;
    while (hp.size() > 1) {
        int a = hp.top(); hp.pop();
        int b = hp.top(); hp.pop();
        ans += (a + b);
        hp.push(a + b);
    }
    cout << ans << endl;
    return 0;
}
