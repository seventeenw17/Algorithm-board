// 给定一个长度为的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int stk[N], n, tt = 0;

int main() {
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d" ,&x);
        // 当栈顶元素大于所输入元素时弹出栈顶元素
        while(tt&&stk[tt] >= x) tt--;
        // 此时栈顶的元素（若有元素）便是向左第一个比它小的
        if (tt) cout << stk[tt] << " ";
        else cout << "-1 ";
        stk[++tt] = x;
    }
    return 0;
}
