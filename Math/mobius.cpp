/*
g:to get the num of pairs of (x, y) s.t. gcd(x,y) is prime; 
*/

const int maxn = 1e6 + 10;

bool is[maxn];
int prime[maxn], primeCnt, miu[maxn], sum[maxn];// g[maxn]; //

void mobius()//g(x) = sum
{
    for(int i = 0; i < maxn; i++) is[i] = 1;
	primeCnt = 0, miu[1] = 1;//g[1] = 0;
    for(int i = 2; i < maxn; i++)
    {
        if(is[i]) prime[primeCnt++] = i, miu[i] = -1;// g[i] = 1;
        for(int j = 0; j < primeCnt; j++)
		{
            if(prime[j] * i >= maxn) break;
            is[i * prime[j]] = 0;
            if(i % prime[j] == 0)
	    	{
                miu[i * prime[j]] = 0;
                //g[i * prime[j]] = miu[i];
                break;
            }
	    	else
	    	{
                miu[i * prime[j]] = -miu[i];
                //g[i * prime[j]] = miu[i] - g[i];
            }
        }
    }
    sum[0] = 0;
    for(int i = 1; i < maxn; i++) sum[i] = sum[i-1] + miu[i];
    //for(int i = 1; i < maxn; i++) sum[i] = sum[i-1] + g[i];
}

//找[1,a],[1,b],[1,c]内互质的数的对数
ll solveTriple(int a,int b, int c)
{
     ll ans=0;
     int small = min(a, min(b, c));
     for(int i = 1, last = 0; i <= small; i = last+1)
     {
         last = min(a/(a/i), min(b/(b/i), c/(c/i)));
         ans += (ll)(sum[last] - sum[i-1]) * (a/i) * (b/i) * (c/i);
     }
     return ans;
}

//找[1,a],[1,b]内互质的数的对数
ll solveDouble(int a, int b)
{
    ll ans = 0;
    int small = min(a, b);
    for (int i = 1, last = 0; i <= small; i = last+1)
    {
        last = min(a/(a/i), b/(b/i));
        ans += (ll)(sum[last] - sum[i-1]) * (a/i) * (b/i);
    }
    return ans;
}

//rec[i][j]: [1,i],[1,j]内互质的数的对数
//一次性给出rec的大表
ll now[maxn] = {0};
ll rec[maxn][maxn];
void initRec()
{
    rec[0][0] = 0;
    for (int i = 1; i < maxn; i++)
    {
        rec[i][0] = 0;
        for (int j = 1; j <= maxn; j++)
        {
            if (__gcd(i, j) == 1) now[j]++;
            rec[i][j] = rec[i][j-1] + now[j];
        }
    }
}
