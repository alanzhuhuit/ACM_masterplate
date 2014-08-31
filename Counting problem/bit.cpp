//idx start from 1
int add(int idx, int num)   //在idx点加上num
{
	while (idx <= MaxVal)
	{
		tree[idx] += num;
		idx += (idx & -idx);
	}
	return 0;
}

int sum(int idx)   //求1-idx的区间和
{
	int s = 0;
	while (idx > 0)
	{
		s += tree[idx];
		idx -= idx & -idx;	
	}
	return s;
}

int getSingle(int idx)   //求idx点的值，此方法比Sum(idx) - Sum(idx-1)快一点
{
	int s = tree[idx];
	if (idx > 0)
	{
		int z = idx - (idx & -idx);
		idx--;
		while (idx != z)
		{
			s -= tree[idx];
			idx -=  idx & -idx;
		}
	}
	return s;
}

区间成段更新可以化成两个树状数组更新的组合：
delta[i]表示A[i]...A[n]的共同增量
把数组A的原始值保存在数组org中
sum[x] = org[1]+...+org[x] + delta[1]*x + delta[2]*(x-1) + delta[3]*(x-2)+...+delta[x]*1

                                         = org[1]+...+org[x] + segma(delta[i]*(x+1-i))

                                         = segma(org[i]) + (x+1)*segma(delta[i]) - segma(delta[i]*i)，1 <= i <= x

