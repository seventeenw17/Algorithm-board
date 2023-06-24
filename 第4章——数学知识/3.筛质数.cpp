①　试除法筛质数，时间复杂度：O(n * log n)
vector<int> prime; //存储1~n之间的素数
bool st[N]; //是否已经被筛掉

void getPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (st[i]) continue;
        prime.push_back(i);
        //筛掉倍数
        for (int j = 2 * i; j <= n; j += i)
            st[j] = true;
    }
}
②　埃氏法筛质数，时间复杂度：O(n * log log n)
void getPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime.push_back(i);
            //筛去质数的倍数
            for (int j = 2 * i; j <= n; j += i)
                st[j] = true;
        }
    }
}
③　线性法筛质数，时间复杂度：O(n)
void getPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime.push_back(i);
        //筛掉质数的倍数
        for (int j = 0; prime[j] <= n / i; j ++) {
            st[prime[j] * i] = true;
            //p[j]是i的最小质因子
            if (i % prime[j] == 0) break;
        }
    }
}
