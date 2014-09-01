//离散化专用，用b存原数组，r存排序数组，a存离散化之后的数组，从小到大依次赋值1，2，3……
struct baba
{
          int x, id;
} r[MAXN];

int cmp1(const baba x, const baba y)
{
    return x.x < y.x;
}

REP(i, n) cin >> r[n-1-i].x, b[n-1-i] = r[n-1-i].x, r[n-1-i].id = n-1-i;
sort(r, r+n, cmp1);
int x = -INF, id = 0;
REP(i, n)
｛
    if (r[i].x == x) a[r[i].id] = id;
      else x = r[i].x, a[r[i].id] = ++id;
｝
//==============================================================================================================



int a[MAXN], b[MAXN], sa[MAXN], Rank[MAXN], height[MAXN];
int n;

int cmp(int* r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}

void calHeight(int *r, int *sa, int n)
{
    REP_1(i, n) Rank[sa[i]] = i;//求rank

    int i, j, k = 0;
    for (int i = 0; i < n; height[Rank[i++]] = k)
    {
	if (Rank[i] == 0) height[0] = 0;
        for(k?k--:0, j = sa[Rank[i]-1];r[i+k] == r[j+k]; k++);
    }
}

int wa[MAXN], wb[MAXN], cnt[MAXN];

void sortSuffix(int* r, int* sa, int n, int m)//n为strlen(r)+1;
{
    int i, j, p, *x = wa, *y = wb, *t;
    //第一遍基数排序（可换快排）
    for(i=0; i<m; i++) cnt[i]=0;
    for(i=0; i<n; i++) cnt[x[i]=r[i]]++;
    for(i=1; i<m; i++) cnt[i] += cnt[i-1];
    for(i=n-1; i>=0; i--)
        sa[--cnt[x[i]]] = i;

    for(j=1,p=1; p<n; j*=2,m=p)
    {
        //对第二关键字排序
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if (sa[i]>=j) y[p++]=sa[i]-j;
        //对第一关键字排序
        for(i=0; i<m; i++) cnt[i]=0;
        for(i=0; i<n; i++) cnt[x[y[i]]]++;
        for(i=1; i<m; i++) cnt[i]+=cnt[i-1];
        for(i=n-1; i>=0; i--) sa[--cnt[x[y[i]]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]] = cmp(y,sa[i],sa[i-1],j)?p-1:p++;
    }

    return;
}

int main()
{
    //freopen("in", "r", stdin);
    cin >> n;
    {
	a[n] = 0;//最后赋值为1
	sortSuffix(a, sa, n+1, id+2);//id为a数组中最大的值
	calHeight(a, sa, n);//求Rnak 和 height
    }
    return 0;
}

