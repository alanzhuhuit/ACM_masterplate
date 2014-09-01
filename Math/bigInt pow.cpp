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

