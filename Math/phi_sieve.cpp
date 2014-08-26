void sieve_phi(int n)
{
    for (ll i = 1; i <= n; i++) phi[i] = i;
    for (ll i = 2; i <= n; i++)
        if (phi[i] == i)
        {
            for (ll j = i; j <= n; j += i)
                phi[j] = phi[j] * (i-1) / i;
        }
}
