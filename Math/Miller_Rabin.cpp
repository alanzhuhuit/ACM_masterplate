bool witness(int a, int n)
{
	int x, d=1;
	for (int i = ceil(log(n - 1.0) / log(2.0)) - 1; i >= 0; i--) 
	{
		x = d; d = (d * d) % n;
		if (d==1 && x!=1 && x!=n-1) return 1;
		if (((n-1) & (1<<i)) > 0) d = (d * a) % n;
	}
	return (d == 1 ? false : true);
}

bool MillerRabin(int n, int s = 50)
{
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	while (s--)
	{
		a = rand() * (n-2) / RAND_MAX + 1;
		if (witness(a, n)) return false;
	}
	return 1;
}
