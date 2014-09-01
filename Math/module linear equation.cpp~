int ans[maxn];
bool modEquation(int a, int b, int n)
{
	int d, x, y;
	d = extendEuclid(a, b, x, y);
	if (b % d != 0) return false;
	else
	{
		ans[0] = x * (b/d) % n;
		for (int i = 1; i < d; i++)
			ans[i] = (ans[i-1] + (n/d)) % n;
		return true;
	}
}
