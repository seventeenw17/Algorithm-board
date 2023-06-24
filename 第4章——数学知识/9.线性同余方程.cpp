扩展欧几里得算法

//求x,y，使得ax+by==gcd(a,b)
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//解线性同余方程，使得(ax-b)%m==0，即ax+my=b
int d = exgcd(a, mod, x, y);
if (b % d != 0) //无解
else (b/d)*x%mod 为x的一个解

