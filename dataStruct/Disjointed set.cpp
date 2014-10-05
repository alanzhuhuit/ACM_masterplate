int getFather(int x)
{
    if (fa[x] != x)
    {
        fa[x] = getFather(fa[x]);
        return fa[x];
    }
    else return x;
}

void union_(int x, int y)
{
    int faX = getFather(x), faY = getFather(y);
    if (faX == faY) return;
    if (Rank[faX] < Rank[faY])
        fa[faX] = faY; else fa[faY] = faX;
    if (Rank[faX] == Rank[faY]) Rank[faX]++;
}

for (int i = 0; i < maxn; i++) fa[i] = i, Rank[i] = 0;
