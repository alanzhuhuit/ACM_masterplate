//-------------------------大整数n^m-------------------------------------------------------

long long pow(long long n, long long m, long long mod = 0)
{
    if(m < 0) return 0;
    long long ans = 1;
    long long k = n;
    while(m){
        if(m & 1) {
            ans *= k;
            if(mod) ans %= mod;
        }
        k *= k;
        if(mod) k %= mod;
        m >>= 1;
    }
    return ans;
}

//---------------------------------------------------------------------------------

ll combination(int a, int b) //C(a,b) a>=b
{
    return fac[a] * inv[b] % mod * inv[a - b] % mod;
}   

void comb_init()
{
	fac[0] = fac[1] = 1;
	inv[0] = inv[1] = 1;
	for(int i = 2; i < maxn; i++) 
	{
    		fac[i] = fac[i - 1] * i % mod;
   	 	inv[i] = pow(fac[i], mod - 2, mod);
	}
}
