const int N = 2;

struct matrix
{
    ll mat[N][N];
    void zero()
    {
        memset(mat, 0, sizeof(mat));
    }
    void I()
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) mat[i][j] = bool(i == j);
    }
    void fib()
    {
        mat[0][0] = mat[0][1] = mat[1][0] = 1;
        mat[1][1] = 0;
    }
} I, Ab, Ak, B;

matrix add(matrix A, matrix B, ll mod = 0)
{
    matrix res;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {res.mat[i][j] =  A.mat[i][j] + B.mat[i][j]; if (mod) res.mat[i][j] %= mod;}
    return res;
}

matrix multi(matrix A, matrix B, ll mod = 0)
{
    matrix res;
    res.zero();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) if (mod) res.mat[i][j] += ((A.mat[i][k] * B.mat[k][j]) % mod), res.mat[i][j] %= mod; else res.mat[i][j] += A.mat[i][k] * B.mat[k][j];
    return res;
}

matrix pow(matrix A, ll m, ll mod = 0) // A^m % mod
{
    matrix res;
    res.I();
    while(m)
    {
        if(m & 1)
            res = multi(res, A, mod);
        A = multi(A, A, mod);
        m >>= 1;
    }
    return res;
}

matrix addpow(matrix A, ll n, ll mod = 0)//I + A + A^2 +...+ A^n
{
    matrix temp, res, ans;
    ans.I(); temp.I();
    res.zero();
    n++;
    while (n)
    {
        if (n & 1)
        {
            res = add(res, multi(ans, temp, mod));
            temp = multi(temp, A, mod);
        }
        ans = add(ans, multi(ans, A, mod), mod);
        A = multi(A, A, mod);
        n >>= 1;
    }
    return res;
}
