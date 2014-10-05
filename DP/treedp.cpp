int dp[point][num]..;
int fa[maxn], step[maxn], maxk;//fa: father, step: 层数, maxk: 最深的层数
vector<int> edge[maxn];
void dfs(int x, int k)//从根节点出发dp, 找到每个节点所在层数以及其father, root == 1, fa[root] == root.
{
    maxk = max(k, maxk);
    step[x] = k;
    for (int i = 0; i < edge[x].size(); i++)
    {
        if (fa[edge[x][i]] == 0)
        {
            fa[edge[x][i]] = x;
            dfs(edge[x][i], k+1);
        }
    }
    return;
}

void searchTree(int x) //dp point x
{
    //dp[x][0] = 0; dp[x][1] = v[x];
    for (int i = 0; i < edge[x].size(); i++)
    if (fa[x] != edge[x][i])
    {
        int y = edge[x][i];
        for (int pn = m; pn > 0; pn--)//x的维度要从大到小
            for (int yn = 0; yn < pn; yn++)
            if (dp[x][pn-yn] > 0)
                dp[x][pn] = max(dp[x][pn], dp[x][pn-yn] + dp[y][yn]);
    }
    return;
}

int main()
{
	memset(fa, 0, sizeof(fa));
	fa[1] = 1;
	dfs(1, 1);
	for (int k = maxk; k > 0; k--)//从最底层向上找，如果防止层数过深可以对step排序
	{
	    for (int i = 1; i <= n; i++)
	        if (step[i] == k) searchTree(i);
	}
}

//Ex1: find a m-point connected graph of a tree which must contain point 1.
//Point: 1..n, every point has a value.
//The subtree should have the maximum tot value.
const int maxn = 105;

int n, m, maxk = 0;
int dp[maxn][maxn];
int v[maxn], fa[maxn], step[maxn];
vector<int> edge[maxn];

void dfs(int x, int k)
{
    maxk = max(k, maxk);
    step[x] = k;
    for (int i = 0; i < edge[x].size(); i++)
    {
        if (fa[edge[x][i]] == 0)
        {
            fa[edge[x][i]] = x;
            dfs(edge[x][i], k+1);
        }
    }
    return;
}

int tmp[maxn];

void searchTree(int x)
{
    dp[x][0] = 0;
    dp[x][1] = v[x];
    for (int i = 0; i < edge[x].size(); i++)
    if (fa[x] != edge[x][i])
    {
        int y = edge[x][i];
        for (int pn = m; pn > 0; pn--)
            for (int yn = 0; yn < pn; yn++)
            if (dp[x][pn-yn] > 0)
                dp[x][pn] = max(dp[x][pn], dp[x][pn-yn] + dp[y][yn]);
    }
    return;
}

int main()
{
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &n, &m);
    int x, y, w;
    for (int i = 1; i <= n; i++) scanf("%d", v+i);
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    memset(fa, 0, sizeof(fa));
    fa[1] = 1;
    dfs(1, 1);
    for (int k = maxk; k > 0; k--)
    {
        for (int i = 1; i <= n; i++)
            if (step[i] == k) searchTree(i);
    }
    printf("%d\n", dp[1][m]);
    return 0;
}

//Ex2:  every point has a value, every edge has a value.
//Travel from point 1, every point can be only count once but can be traveled more than once.
//Given a distance d. Get the maximum value we can get. The request can be many many.
const int maxn = 105;
const int maxval = 205;
const int maxd = 1e6+10;

int n, maxk = 0;
int dp[maxn][maxval][2], g[maxn][maxn];
int v[maxn], fa[maxn], ans[maxval], step[maxn];
vector<int> edge[maxn];

void dfs(int x, int k)
{
    maxk = max(k, maxk);
    step[x] = k;
    for (int i = 0; i < edge[x].size(); i++)
    {
        if (fa[edge[x][i]] == 0)
        {
            fa[edge[x][i]] = x;
            dfs(edge[x][i], k+1);
        }
    }
    return;
}

//int tmp[maxval][2];

void searchTree(int x)
{
    dp[x][v[x]][0] = dp[x][v[x]][1] = 0;
    for (int i = 0; i < edge[x].size(); i++)
    if (fa[x] != edge[x][i])
    {
        //for (int tot = 0; tot <= 2*n; tot++) tmp[tot][0] = dp[x][tot][0], tmp[tot][1] = dp[x][tot][1];
        int y = edge[x][i];
        for (int tot = 2*n; tot >= v[x]; tot--)
            for (int ytot = 1; ytot <= tot; ytot++)
            {
                if (dp[x][tot-ytot][1] < maxd)
                {
                    dp[x][tot][0] = min(dp[x][tot][0], dp[x][tot-ytot][1] + g[x][y] + dp[y][ytot][0]);
                    dp[x][tot][1] = min(dp[x][tot][1], dp[x][tot-ytot][1] + g[x][y] + g[x][y] + dp[y][ytot][1]);
                }
                if (dp[x][tot-ytot][0] < maxd)
                {
                    dp[x][tot][0] = min(dp[x][tot][0], dp[x][tot-ytot][0] + g[x][y] + g[x][y] + dp[y][ytot][1]);
                }
            }
    }
    return;
}

int main()
{
    memset(dp, 0x59, sizeof(dp));
    scanf("%d", &n);
    int x, y, w;
    for (int i = 1; i <= n; i++) scanf("%d", v+i);
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d%d%d", &x, &y, &w);
        edge[x].push_back(y);
        edge[y].push_back(x);
        g[x][y] = g[y][x]  = w;
    }
    memset(fa, 0, sizeof(fa));
    fa[1] = 1;
    dfs(1, 1);
    for (int k = maxk; k > 0; k--)
    {
        for (int i = 1; i <= n; i++)
            if (step[i] == k) searchTree(i);
    }
    for (int i = 0; i < maxval; i++)
        ans[i] = dp[1][i][0];
    int m = ans[maxval-1];
    for (int i = maxval-2; i >= 0; i--) m = min(m, ans[i]), ans[i] = m;
    int q, d;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &d);
        int l, r, mid;
        l = 0, r = 2*n;
        while ( l <= r)
        {
            mid = (l+r)/2;
            if (ans[mid] > d) r = mid-1;
                else l = mid+1;
        }
        printf("%d\n", r);
    }
    return 0;
}

