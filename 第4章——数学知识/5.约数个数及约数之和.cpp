(1)约数个数

unordered_map<int, int> prime;
//分解质因数
void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                prime[i]++;
            }
        }
    }
    if (x > 1) prime[x]++;
}
//求约数个数
int num() {
    int ans = 1;
    for (auto it: prime) {
        int c = it.second;
        ans = ans * (c + 1); //有时需要取模
    }
    return ans;
}
(2)约数之和
int sum() {
    int ans = 1;
    for (auto it: prime) {
        int sum = 1;
        int p = it.first, c = it.second;
        for (int i = 1; i <= c; i++) sum = sum * p + 1; //有时需要取模
        ans = ans * sum; //有时需要取模
    }
    return ans;
}
