树与图的广度优先遍历
时间复杂度O(n+m)，n:点数，m:边数
*框架：
int bfs()
{
	queue<T> que;
	que.push(初始状态);
	//初始化
	while (que.size())
	{
		auto t = que.front();//取队头
		que.pop();
		for (int i = h[t]; i != -1; i = ne[i])//遍历
		{
			T j = e[i];
			if (!st[j])
			{
				st[j] = true;
				/*完成题目逻辑*/
				que.push(j); //入队
			}
		}
	}
	return 题目需要的量;
}

