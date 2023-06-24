树与图的深度优先遍历
*框架：
//有向图深度优先遍历
void dfs(int u, int fa) {
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		dfs(j, u);
	}
}

void dfs(int u, int fa) {
    for (auto& v: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}


