//idx start from 1
int add(int idx, int num)   //��idx�����num
{
	while (idx <= MaxVal)
	{
		tree[idx] += num;
		idx += (idx & -idx);
	}
	return 0;
}

int sum(int idx)   //��1-idx�������
{
	int s = 0;
	while (idx > 0)
	{
		s += tree[idx];
		idx -= idx & -idx;	
	}
	return s;
}

int getSingle(int idx)   //��idx���ֵ���˷�����Sum(idx) - Sum(idx-1)��һ��
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

����ɶθ��¿��Ի���������״������µ���ϣ�
delta[i]��ʾA[i]...A[n]�Ĺ�ͬ����
������A��ԭʼֵ����������org��
sum[x] = org[1]+...+org[x] + delta[1]*x + delta[2]*(x-1) + delta[3]*(x-2)+...+delta[x]*1

                                         = org[1]+...+org[x] + segma(delta[i]*(x+1-i))

                                         = segma(org[i]) + (x+1)*segma(delta[i]) - segma(delta[i]*i)��1 <= i <= x

