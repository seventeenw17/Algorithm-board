1.进制转换
//p进制(2~36)转为十进制 | 字母以大写表示
int p_to_ten(string s, int p) {
    //s[]为顺序存储的p进制字符串
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        x *= p;
        if (s[i] >= 'A' && s[i] <= 'Z') x += (s[i] - 'A' + 10);
        else x += (s[i] - '0');
    }
    return x;
}

//十进制转为p进制
string ten_to_p(int x, int p) {
    string res;
    int tmp = 0;
    do {
        tmp = x % p;
        if (tmp < 10) res.push_back('0' + tmp);
        else res.push_back('A' + tmp - 10);
        x /= p;
    }while(x);
    // 转顺序
    reverse(res.begin(), res.end());
    return res;
}
2.根据日期计算星期数—基姆拉尔森公式
基姆拉尔森公式（求得的w值表示星期数，0～6代表星期一到星期天）：
w = ( d + 2 * m + 3*(m + 1) / 5 + y + y / 4 - y / 100 + y / 400 ) % 7
3.100以内的素数(有25个)
int primes[25] = {
         2,  3,  5,  7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
        53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
};
4.1000以内的素数(有168个)
int primes[168] = {
          2,   3,   5,   7,  11,  13,  17,  19,
         23,  29,  31,  37,  41,  43,  47,  53,
         59,  61,  67,  71,  73,  79,  83,  89,
         97, 101, 103, 107, 109, 113, 127, 131,
        137, 139, 149, 151, 157, 163, 167, 173,
        179, 181, 191, 193, 197, 199, 211, 223,
        227, 229, 233, 239, 241, 251, 257, 263,
        269, 271, 277, 281, 283, 293, 307, 311,
        313, 317, 331, 337, 347, 349, 353, 359,
        367, 373, 379, 383, 389, 397, 401, 409,
        419, 421, 431, 433, 439, 443, 449, 457,
        461, 463, 467, 479, 487, 491, 499, 503,
        509, 521, 523, 541, 547, 557, 563, 569,
        571, 577, 587, 593, 599, 601, 607, 613,
        617, 619, 631, 641, 643, 647, 653, 659,
        661, 673, 677, 683, 691, 701, 709, 719,
        727, 733, 739, 743, 751, 757, 761, 769,
        773, 787, 797, 809, 811, 821, 823, 827,
        829, 839, 853, 857, 859, 863, 877, 881,
        883, 887, 907, 911, 919, 929, 937, 941,
        947, 953, 967, 971, 977, 983, 991, 997
};
5.头文件
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);

    return 0;
}
6.常用STL
(1) vector<T>, 变长数组，倍增的思想
    size()  返回元素个数
    empty()  返回是否为空
    clear()  清空
    front()/back()
    push_back()/pop_back()
    begin()/end()
    []
    支持比较运算，按字典序

(2) pair<T,T>
    first, 第一个元素
    second, 第二个元素
    支持比较运算，以first为第一关键字，
	以second为第二关键字（字典序）

(3) string，字符串
    size()/length()  返回字符串长度
    empty()
    clear()
    substr(起始下标，(子串长度))  返回子串
    c_str()  返回字符串所在字符数组的起始地址

(4) queue<T>, 队列
    size()
    empty()
    push()  向队尾插入一个元素
    front()  返回队头元素
    back()  返回队尾元素
    pop()  弹出队头元素

(5) priority_queue<T>, 优先队列，默认是大根堆
    size()
    empty()
    push()  插入一个元素
    top()  返回堆顶元素
    pop()  弹出堆顶元素
    定义成小根堆的方式：
		priority_queue<T,vector<T>,greater<T>>

(6) stack<T>, 栈
    size()
    empty()
    push()  向栈顶插入一个元素
    top()  返回栈顶元素
    pop()  弹出栈顶元素

(7) deque<T>, 双端队列
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []

(8) set<T>, map<T,T>, multiset<T>, multimap<T,T>,
  基于平衡二叉树（红黑树），动态维护有序序列
    size()
    empty()
    clear()
    begin()/end()
    ++, -- 返回前驱和后继，时间复杂度 O(logn)

    set<T>/multiset<T>
        insert()  插入一个数
        find()  查找一个数
        count()  返回某一个数的个数
        erase()
            (1) 输入是一个数x，删除所有x   O(k + logn)
            (2) 输入一个迭代器，删除这个迭代器
        lower_bound()/upper_bound()
            lower_bound(x)  返回大于等于x的最小的数的迭代器
            upper_bound(x)  返回大于x的最小的数的迭代器
    map<T,T>/multimap<T,T>
        insert()  插入的数是一个pair
        erase()  输入的参数是pair或者迭代器
        find()
        []  注意multimap不支持此操作。 时间复杂度是 O(logn)
        lower_bound()/upper_bound()

(9) unordered_set<T>, unordered_map<T,T>,
  unordered_multiset<T>, unordered_multimap<T,T>, 哈希表
    和上面类似，增删改查的时间复杂度是 O(1)
    不支持 lower_bound()/upper_bound()， 迭代器的++，--

(10) bitset, 圧位
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  返回有多少个1
    any()  判断是否至少有一个1
    none()  判断是否全为0
    set()  把所有位置成1
    set(k, v)  将第k位变成v
    reset()  把所有位变成0
    flip()  等价于~
    flip(k) 把第k位取反
