//从根节点出发dp, 找到每个节点所在层数以及其father
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


//one problem from hihoCoder game 3.. not sure
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const int maxn = 105;
const int maxval = 205;
const int maxd = 1e6+10;

int n, maxk = 0;
int dp[maxn][maxval][2], g[maxn][maxn];
int v[maxn], fa[maxn], ans[maxval], step[maxn];
//bool check[maxn];
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

int tmp[maxval][2];

void searchTree(int x)
{
    //for (int i = 0; i < edge[x].size(); i++)
    //    if (fa[x] != edge[x][i]) searchTree(edge[x][i]);
    dp[x][v[x]][0] = dp[x][v[x]][1] = 0;
    for (int i = 0; i < edge[x].size(); i++)
    if (fa[x] != edge[x][i])
    {
        for (int tot = 0; tot <= 2*n; tot++) tmp[tot][0] = dp[x][tot][0], tmp[tot][1] = dp[x][tot][1];
        int y = edge[x][i];
        for (int tot = v[x]; tot <= 2*n; tot++)
            for (int ytot = 1; ytot <= 2*n; ytot++)
            {
                if (tmp[tot][1] < maxd) //|| tot == v[x])
                {
                    dp[x][tot + ytot][0] = min(dp[x][tot + ytot][0], tmp[tot][1] + g[x][y] + dp[y][ytot][0]);
                    dp[x][tot + ytot][1] = min(dp[x][tot + ytot][1], tmp[tot][1] + g[x][y] + g[x][y] + dp[y][ytot][1]);
                }
                if (tmp[tot][0] < maxd) //|| tot == 0)
                {
                    dp[x][tot + ytot][0] = min(dp[x][tot + ytot][0], tmp[tot][0] + g[x][y] + g[x][y] + dp[y][ytot][1]);
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
//    memset(check, false, sizeof(check));
    fa[1] = 1;
    dfs(1, 1);
    for (int k = maxk; k > 0; k--)
    {
        for (int i = 1; i <= n; i++)
            if (step[i] == k) searchTree(i);
    }
    //searchTree(1);
    for (int i = 0; i < maxval; i++)
        ans[i] = dp[1][i][0];
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
