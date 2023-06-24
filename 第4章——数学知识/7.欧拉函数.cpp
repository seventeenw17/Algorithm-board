(1)定义法：时间复杂度：O(n * sqrt(n))
int phi(int n) { //分解质因数框架
    int ans = n;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
(2)线性法求中每个数的欧拉函数，时间复杂度：O(n)
int e[N]; //每个数的欧拉函数
bool st[N]; //是否被筛掉
vector<int> prime; //存储素数

void phi(int n) {
    e[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime.push_back(i);
            e[i] = i - 1;
        }
        for (int j = 0; prime[j] <= n / i; j++) {
            int t = prime[j] * i;
            st[t] = true;
            if (i % prime[j] == 0) {
                e[t] = e[i] * prime[j];
                break;
            }
            e[t] = e[i] * (prime[j] - 1);
        }
    }
}
