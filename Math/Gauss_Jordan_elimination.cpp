int ptr, mat[maxRow][maxCol],  mat[maxRow][maxCol];
int ans[maxCol], x[maxCol];

int dfs(int v, int sizeRow, int sizeCol)
{
	if(v == sz)
	{
		int temp = 0;
		for (int i = 0; i < sizeCol; i++) x[i] = ans[i];
		memcpy(tmat, mat, sizeof(mat));
		for(int i = ptr - 1; i >= 0; i--)
		{
			for(int j = i + 1; j < sizeCol; j++)
				tmat[i][sz] ^= x[j] & tmat[i][j];
			x[i] = tmat[i][sz];
		}
		for (int i = 0; i < sizeCol; i++)
			if (x[i]) temp++;
		return temp;
	}
	ans[v]=0;
	int res = dfs(v+1);
	ans[v]=1;
	res = min(res, dfs(v+1));
	return res;
}

int GaussJordan(int sizeRow, int sizeCol)
{
	ptr = 0;
	for (int row = 0,col = 0; row < sizeRow && col < sizeCol; col++)
	{
		int zptr = -1;
		for (int i = row; i < sizeRow; i++)
		{
			if (mat[i][col])
			{
				zptr=i;
				break;
			}
		}
		if (zptr == -1) continue;
		for (int i = 0; i <= sizeCol; i++)
			swap(mat[row][i], mat[zptr][i]);
		for (int i = 0; i < sizeRow; i++)
		if (i != row)
		{
			if (!mat[i][col]) continue;
			for (int j = 0; j <= sizeCol; j++)
				mat[i][j] ^= mat[row][j];
		}
		row++;
		ptr = row;
	}
	if (ptr == sizeCol)
	{
		int ans = 0;
		for (int i = 0; i < sizeCol; i++)
			if (mat[i][sizeCol]) ans[i] = mat[i][sizeCol]/mat[i][i];
		return ans;//唯一解
	}
	else
	{
		for (int i=ptr;i<sz;i++)
		{
			if (mat[i][sz]!=0) return -1;
		}//无解
		return dfs(ptr);//有自由变元
	}
	return ans;
}

