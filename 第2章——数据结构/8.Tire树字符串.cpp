// son[i][j]: 第i个节点下，字符j的位置
// cnt[]: 以当前节点为终点的字符串数量
int son[N][26],cnt[N],idx;

//插入
void insert(string str) {
    int p = 0; //从0号节点开始
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a'; // 将a~z映射到0~25
        if (!son[p][u]) // 不存在节点则创造节点
            son[p][u] = ++idx;
        p = son[p][u]; // 继续向下走
    }
    cnt[p]++; // 记录数量
}

// 询问
int query(string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) // 没有该节点，返回0
            return 0;
        p = son[p][u];
    }
    return cnt[p]; // 返回该节点结尾的字符串数量
}
