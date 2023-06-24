（1）点
struct Point {
    double x, y;
    Point() = default;
    Point(double x, double y) : x(x), y(y) {}
};
（2）向量
using Vector = Point;
向量的基本运算
// 向量 + 向量 = 向量，点 + 向量 = 向量
Vector operator + (Vector a, Vector b) {
    return Vector(a.x + b.x, a.y + b.y);
}
// 点 - 点 = 向量(向量 BC = C - B)
Vector operator - (Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}
// 向量 * 数 = 向量
Vector operator * (Vector a, double p) {
    return Vector(a.x * p, a.y * p);
}
// 向量 / 数 = 向量
Vector operator / (Vector a, double p) {
return Vector(a.x / p, a.y / p);
}
// 点 | 向量的比较
bool operator < (const Vector& a, const Vector& b) {
return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
// 求极角，在极坐标系中，平面上任何一点到极点的连线和极轴的夹角叫做极角。
// 单位弧度 rad
double polarAngle(Vector A) {
return atan2(A.y, A.x);
}
// 重载 == 运算符
bool operator == (const Point& A, const Point& B) {
    return !sgn(A.x - B.x) && !sgn(A.y - B.y);
}
// 点积
double Dot(Vector a, Vector b) {
    return (a.x * b.x + a.y + b.y);
}
// 模长计算
double Length(Vector a) {
    return sqrtl(Dot(a, a));
}
// 计算向量夹角，返回弧度
double Angle(Vector a, Vector b) {
    return acos(Dot(a, b) / Length(a) / Length(b));
}
// 叉积 | 返回的数字
double Cross(Vector a, Vector b) {
    return (a.x * b.y - a.y * b.x);
}
// 计算向量构成的平行四边形面积
double Area(Point A, Point B, Point P) {
    return Cross(B - A, P - A);
}
To-Left判断
// To-Left测试 | 点P是否在向量 AB 左边
bool toLeft(Point A, Point B, Point P) {
    return (Cross(B - A, P - A) > 0);
}
向量旋转

// 向量 a 逆时针旋转 theta(弧度) 角
Vector rotate(Vector a, double theta) {
    double xr = a.x * cos(theta) - a.y * sin(theta);
    double yr = a.x * sin(theta) + a.y * cos(theta);
    return Vector(xr, yr);
}
// 点 A 绕 P 逆时针旋转 theta(弧度) 角
Point rotate(Point A, Point P, double theta) {
    Point V = A - P;
    double c = cos(theta), s = sin(theta);
    return Point(P.x + V.x * c - V.y * s, P.y + V.x * s + V.y * c);
}
// 向量的单位法线实际上就是将该向量向左旋转 90 度
// 因为是单位法线所以长度归一化调用前请确保 a 不是零向量
Vector Normal(const Vector& a) {
    double L = Length(a);
    return Vector(- a.y / L, a.x / L);
}
// 向右旋转
Vector Format(const Vector& a) {
    double L = Length(a);
    return Vector(a.x / L, a.y / L);
}
（3）线段
struct Segment {
    Point A, B;
};
点是否在线段上
// 判断点 P 是否在线段 AB 上
bool isOnTheSeg(Point P, Segment AB) {
    Point A = AB.A, B = AB.B;
    return fabs(Cross(A - P, B - P)) < eps && Dot(A - P, B - P) <= 0;
}
线段是否相交
// 判断线段 AB 和 CD 是否相交
bool isIntersect(Segment AB, Segment CD) {
    Point A = AB.A, B = AB.B, C = CD.A, D = CD.B;
    if (fabs(Cross(B - A, D - C)) < eps && (isOnTheSeg(C, AB) || isOnTheSeg(D, AB))) return true;
    if (isOnTheSeg(C, AB) || isOnTheSeg(D, AB)) return true;
    return Cross(B - A, C - A) * Cross(B - A, D - A) <= 0;
}

（4）直线
struct Line {
    Point P;
    Vector v;
    Line(Point P, Vector v) : P(P), v(v){}
};
点到直线距离

// 点 A 到直线 (p,v) 距离，已知 P, v, A
double distOfPointToLine(Line le, Point A) {
    Point P = le.P, v = le.v;
    return fabs(Cross(v, A - P) / Length(v));
}
// 点 P 到直线 AB 距离，已知 P, A, B
double distOfPointToLine(Point A, Point B, Point P) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v1) / Length(v1));
}
点在直线投影
// 点 A 在直线 (p,v) 上投影，已知 P, v, A
Point projectionOfPointLine(Line le, Point A) {
    Point P = le.P, v = le.v;
    return P + v * (Dot(v, A - P) / Dot(v, v));
}
// 点 P 在直线 AB 上投影，已知 P, A, B
Point projectionOfPointLine(Point A, Point B, Point P) {
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
}
求两直线交点
Point intersectionOfLines(Line le1, Line le2) {
    Point P1 = le1.P, v1 = le1.v;
    Point P2 = le2.P, v2 = le2.v;
    return P1 + v1 * (Cross(v2, P1 - P2) / Cross(v1, v2));
}
（5）多边形
struct Polygon {
    vector<Point> points;
    Polygon() = default;
    Polygon(int n, Point points[]) { // 第一个点存两次
        for (int i = 0; i < n; i++) {
            this->points.push_back({points[i].x, points[i].y});
        }
        this->points.push_back({points[0].x, points[0].y});
    }
};
多边形面积
基于叉积的公式（任意多边形）
double area(Polygon poly) {
    double s = 0;
    vector<Point>& p = poly.points;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        s += p[i].x * p[i + 1].y - p[(i + 1) % n].x * p[i].y;
    }
    return fabs(s / 2);
}
判断点是否在多边形内（任意）
// 点是否在多边形内 | 内部返回1，外部返回-1，多边形上返回0
int isPointInPoly(Point P, Polygon poly){
    int wn = 0;
    vector<Point>& pnt = poly.points;
    int n = pnt.size();
    for (int i = 0; i < n; i++) {
        if (isOnTheSeg(P, Segment(pnt[i], pnt[(i + 1) % n]))) return 0;
        int k = sgn(Cross(pnt[(i + 1) % n] - pnt[i], P - pnt[i]));
        int d1 = sgn(pnt[i].y - P.y);
        int d2 = sgn(pnt[(i + 1) % n].y - P.y);
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k > 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn == 0) return -1;
    return 1;
}
判断点是否在多边形内（凸多边形）
n次To-Left测试
// 点是否在凸多边形内 | 内部返回1，外部返回-1，多边形上返回0
int isPointInTuPoly(Point P, Polygon poly) {
    vector<Point>& pnt = poly.points;
    int n = pnt.size();
    for (int i = 0; i < n; i++) {
        Point A = pnt[i], B = pnt[(i + 1) % n];
        if (Cross(B - A, P - A) < 0) return -1;
        if (Cross(B - A, P - A) < eps) return 0;
    }
    return 1;
}
