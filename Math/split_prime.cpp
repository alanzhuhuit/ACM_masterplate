int prime[MAXM];
bool is[MAXN];
int primeCnt;
int split[MAXM][2];//[0]:prime, [1]:cnt
int splitCnt;

void primeChart(int n)//n(log)n
{
    primeCnt = 0;
    memset(is,true,sizeof(is));
    is[0] = is[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (!is[i]) continue;
        prime[primeCnt++] = i;
        for (int j = i+i; j <= n; j += i) is[j] = false;
    }
}

void splitNum(int x)//O(primeCnt)
{
    int p = 0;
    memset(split,0,sizeof(split));
    splitCnt = 0;
    while(x > 1)
    {
        if (x % prime[p] == 0) split[++splitCnt][0] = prime[p];
        while(x % prime[p] == 0) split[splitCnt][1]++, x /= prime[p];
        p++;
    }
    if (x > 1) split[++splitCnt][0] = x,split[splitCnt][1]++;
    for (int i = splitCnt; i > 1; i--) cout << split[i][0] << " " << split[i][1] << " ";
    cout << split[1][0] << " " << split[1][1] << "\n";
}
