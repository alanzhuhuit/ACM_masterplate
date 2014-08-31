//------------bigInt n^m----------
ll pow(ll n, ll m, ll mod = 0)
{
	if(m < 0) return 0;
	ll ans = 1;
	ll k = n;
	while(m)
	{
		if(m & 1) 
		{
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

void extendEuclid(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return;
	}
	extendEuclid(b, a % b, x, y);
	int tmp = x, x = y, y = tmp - (a / b) * y;
}

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
