// by: Yonas Adiel
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct mat
{
    long long m[3][3];
};

mat matmul(mat a, mat b)
{
    mat c;
    c.m[0][0] = (((a.m[0][0] * b.m[0][0]) % MOD) + ((a.m[0][1] * b.m[1][0]) % MOD)) % MOD;
    c.m[0][1] = (((a.m[0][0] * b.m[0][1]) % MOD) + ((a.m[0][1] * b.m[1][1]) % MOD)) % MOD;
    c.m[1][0] = (((a.m[1][0] * b.m[0][0]) % MOD) + ((a.m[1][1] * b.m[1][0]) % MOD)) % MOD;
    c.m[1][1] = (((a.m[1][0] * b.m[0][1]) % MOD) + ((a.m[1][1] * b.m[1][1]) % MOD)) % MOD;
    return c;
}

mat matpow(mat b, long long p)
{
    mat m;
    m.m[0][0] = 1;
    m.m[0][1] = 0;
    m.m[1][0] = 0;
    m.m[1][1] = 1;
    long long k = 1;
    for (int i = 0; i < 60; i++)
    {
        if (p & k)
        {
            m = matmul(m, b);
        }
        b = matmul(b, b);
        k <<= 1;
    }
    return m;
}

long long fibo(long long n)
{
    mat m, c;
    m.m[0][0] = 1;
    m.m[0][1] = 1;
    m.m[1][0] = 1;
    m.m[1][1] = 0;

    c = matpow(m, n);
    return c.m[0][0];
}

void solve()
{
    long long n;
    scanf("%lld", &n);
    long long ans = fibo(n + 1) - 1;
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
}