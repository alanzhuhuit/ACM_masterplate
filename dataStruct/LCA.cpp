int ans[maxn][maxn];
int ancestor[maxn];
bool visited[maxn];
int nowTree = 1;
int tree[maxn];

void lca(int x)
{
    tree[x] = nowTree;
    ancestor[x] = x;
    for (int i = 0; i < child[x].size(); i++)
    {
        int y = child[x][i];
        lca(y);
        union_(x, y);
        ancestor[getFather(x)] = x;
    }
    visited[x] = true;
    for (int i = 1; i <= tot; i++)//tot: number of point in the tree
    if (visited[i] && tree[i] == tree[x])
        if (i != x) ans[x][i] = ans[i][x] = ancestor[getFather(i)];
        else ans[x][x] = x;
    return;
}

int main()
    for (int i = 1; i <= tot; i++)
    if (!hasFather[i])  {lca(i); nowTree++;}
    return 0;
}

