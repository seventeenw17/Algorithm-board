typedef pair<int, int> PII;
vector<PII> nums;
void divide(int x) { //将质因数分解存入nums，前大后小
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) { //这里保证i一定是质数，因为后续循环x会改变
            int s = 0;
            while (x % i == 0) {
                x /= i;
                s++;
            }
            nums.push_back({i, s});
        }
    }
    if (x > 1) nums.push_back({x, 1});
}
