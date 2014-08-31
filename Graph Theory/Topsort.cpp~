vector<int> edge[maxn];
int step[maxn];//step记录每个点在拓扑排序过程中的层数
void Topsort()	
	int k = 0, num = 0;
	while (num < n)
	{
		k++;
		int flag[maxn];
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= n; i++)
		if (to[i] == 0)
		{
			step[i] = k;
	    		int l = edge[i].size();
	    		for (int j = 0; j < l; j++) flag[edge[i][j]]++;
	    		to[i] = -1;
	    		num++;
		}
		for (int i = 1; i <= n; i++) if (flag[i]) to[i] -= flag[i];
	}
}
