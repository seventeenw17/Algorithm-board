int ne[], n, m;
char p[], s[];
// p[]: 模板串，s[]: 待匹配的字符串
// ne[]: next数组，n: 模板串长度，m: 待匹配的串长度
// 字符串从下标1开始存
// 创建next数组: 使得ne[i] = j，p[1] ~ p[j]和p[i - j + 1] ~ p[i]相等
for (int i = 2, j = 0; i <= n; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = j;
}

// 比对
for (int i = 1, j = 0; i <= m; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == n) {
        j = ne[j];
        ......
        // 匹配成功后的处理
    }
}
