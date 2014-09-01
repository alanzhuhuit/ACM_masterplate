|KMP
|P: 模式
|T: 文本
|Pi: 前缀函数
|ans: 记录成功匹配的开头位置
|computePrefix(): 计算前缀函数
|calcT(): 计算匹配个数
--------------------------------------------------------
const int MAXT = ;
const int MAXP = ;
char P[MAXP], T[MAXT], ans[MAXT];

int Pi[MAXN], lenP, lenT;

void computePrefix()
{
	//lenP = strlen(P);
	memset(Pi, -1, sizeof(Pi));
	//Pi[0] = -1;
	int k = -1;
	for (int q = 1; q < lenP; q++)
	{
		while (k >= 0 && P[k+1] != P[q]) k = Pi[k];
		if (P[k+1] == P[q]) k++;
		Pi[q] = k;
	}
	return;
}

int calcT()
{
	int res = 0;
	int q = -1;
	for (int i = 0; i < lenT; i++)
	{
		while (q >= 0 && P[q+1] != T[i]) q = Pi[q];
		if (P[q+1] == T[i]) q++;
		if (q+1 == lenP) res++, q = Pi[q];
		// if (q+1 == lenP) { res++, q = Pi[q]; ans[ans_num++] = i-lenP;}
	}
	return res;
}

int init(char p[], char T[])
{
	lenP = strlen(P);
	lenT = strlen(T);
	computePrefix();
	cout << calcT() << endl;
	return 0;
}
