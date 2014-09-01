int CRT(int a[],int m[],int n)
{
	int M = 1;
	int ans = 0;
	for(int i = 0; i< n; i++) M *= m[i];
	for(int i = 0; i < n; i++)
	{
		int x, y;
		int Mi = M / m[i];
		extendEuclid(Mi, m[i], x, y);
		ans = (ans + Mi * x * a[i]) % M;
	}
	if(ans < 0) ans += M;
	return ans;
}
