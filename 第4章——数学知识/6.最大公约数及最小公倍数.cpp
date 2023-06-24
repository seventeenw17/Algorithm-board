欧几里得算法求最大公约数
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

拓展到最小公倍数
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
