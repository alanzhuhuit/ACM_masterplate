vector<int> vec[MAXN];
int id[MAXN], pre[MAXN], low[MAXN], s[MAXN], stop, cnt, scnt;
void tarjan(int v, int n)
{
	int t, minc = low[v] = pre[v] = cnt++;
	vector<int>::iterator pv;
	s[stop++] = v;
	for (pv = vec[v].begin(); pv != vec[v].end(); pv++)
	{
		if (-1 == pre[*pv]) tarjan(*pv, n);
		if (low[*pv] < minc) minc = low[*pv];
	}
	if (minc < low[v])
	{
		low[v] = minc;
		return;
	}
	do
	{
		id[t = s[--stop]] = scnt; low[t] = n;
	} while (t != v)
	++scnt;
}

for (int i = 0; i < n; i++)
	if (-1 == pre[i]) tarjan(i, n);
