圆周率
const double PI = acos(-1);
极限标准eps
const double eps = 1e-6;
Sgn函数
int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    else return -1;
}
