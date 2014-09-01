int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int extendEuclid(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	extendEuclid(b, a % b, x, y);
	int tmp = x, x = y, y = tmp - (a / b) * y;
}
