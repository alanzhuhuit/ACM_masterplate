char str[maxn*2], s[maxn];
int p[maxn];

int MANACHER(char str[])
{
	int len = strlen(str);
	int mx = 0, id = 0, res = 1;
	for (int i = 1; i < len; i++)
	{
		if (mx > i)
		    	p[i] = min(p[2*id-i], mx-i);
		else
		    	p[i] = 1;

		while(str[i+p[i]] == str[i-p[i]]) p[i]++;
		if (i+p[i] > mx)
		{
			mx = i+p[i];
			id = i;
		}
		res = max(res, p[i]);
	}
	return res;
}
//
void init(int s)
{
	int len = strlen(s);
	str[0] = '$';
	for (int i = 0; i <= len; i++)
		str[2*i+1] = '#', str[2*i+2] = s[i];
	cout << MANACHER(str)-1 << endl;
}

