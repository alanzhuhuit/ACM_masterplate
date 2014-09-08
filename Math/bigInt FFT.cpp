//maxn >= 4*max(lenA, lenB)
vir C[maxn];
void multipFFT(vir* A, vir* B, int lenA, int lenB, int* ans, int &lenAns)// ans, lenAns返回结果
{
        memset(C, 0, sizeof(C));
        int loglen = 0, len = 1;
        while (len <= lenA || len <= lenB) {loglen++; len <<= 1;}
        loglen++; len <<= 1;
        dft(A, len, loglen);
        dft(B, len, loglen);
        for (int i = 0; i < len; i++) C[i] = A[i]*B[i];
        idft(C, len, loglen);
        int i = 0, y = 0;
        for ( ; i < len; i++)
        {
            int x = y + int(C[i].re+0.5);
            y = x/10;
            x %= 10;
            ans[i] = x;
        }
        while (y > 0) {ans[i++] = y % 10; y /= 10;}
        lenAns = i;
        while(ans[lenAns-1] == 0 && lenAns > 1) lenAns--;
}
