// by : Tony

#include <bits/stdc++.h>

using namespace std;

#define rb(a, r, c) rubik[(a)*n * n + (r)*n + (c)]

const long long mod = 1e9 + 7;
int rubik[2405];
int num[2405];
int mat[405];
int cntf[30];

void rotateccw(int n, int x)
{
    memcpy(mat, rubik + x * n * n, 4 * n * n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rb(x, i, j) = mat[j * n + n - i - 1];
        }
    }
}

void rotatecw(int n, int x)
{
    memcpy(mat, rubik + x * n * n, 4 * n * n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rb(x, i, j) = mat[(n - j - 1) * n + i];
        }
    }
}

void dox(int n, int x)
{
    // 0(0,2) -> 1(2,2) -> 4(2,0) -> 3(0,0)
    for (int i = 0; i < n; ++i)
    {
        swap(rb(0, n - i - 1, n - 1 - x), rb(1, n - x - 1, i));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(1, n - x - 1, i), rb(4, i, x));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(4, i, x), rb(3, x, n - i - 1));
    }
    if (x == 0)
    {
        rotateccw(n, 2);
    }
    else if (x == n - 1)
    {
        rotatecw(n, 5);
    }
}

void doX(int n, int x)
{
    for (int i = 0; i < n; ++i)
    {
        swap(rb(0, n - i - 1, n - 1 - x), rb(3, x, n - i - 1));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(3, x, n - i - 1), rb(4, i, x));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(4, i, x), rb(1, n - x - 1, i));
    }
    if (x == 0)
    {
        rotatecw(n, 2);
    }
    else if (x == n - 1)
    {
        rotateccw(n, 5);
    }
}

void doy(int n, int x)
{
    // 2(2,0) -> 0(2,0) -> 5(2,0) -> 4(2,0)
    for (int i = 0; i < n; ++i)
    {
        swap(rb(2, n - 1 - x, i), rb(4, n - x - 1, i));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(4, n - 1 - x, i), rb(5, n - x - 1, i));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(5, n - 1 - x, i), rb(0, n - x - 1, i));
    }
    if (x == 0)
    {
        rotateccw(n, 3);
    }
    else if (x == n - 1)
    {
        rotatecw(n, 1);
    }
}

void doY(int n, int x)
{
    // 2(2,0) -> 4(2,0) -> 5(2,0) -> 0(2,0)
    for (int i = 0; i < n; ++i)
    {
        swap(rb(2, n - 1 - x, i), rb(0, n - x - 1, i));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(0, n - 1 - x, i), rb(5, n - x - 1, i));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(5, n - 1 - x, i), rb(4, n - x - 1, i));
    }
    if (x == 0)
    {
        rotatecw(n, 3);
    }
    else if (x == n - 1)
    {
        rotateccw(n, 1);
    }
}

void doz(int n, int x)
{
    // 2(0,0) -> 1(0,0) -> 5(2,2) -> 3(0,0)
    for (int i = 0; i < n; ++i)
    {
        swap(rb(2, i, x), rb(3, i, x));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(3, i, x), rb(5, n - i - 1, n - x - 1));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(5, n - i - 1, n - x - 1), rb(1, i, x));
    }
    if (x == 0)
    {
        rotateccw(n, 0);
    }
    else if (x == n - 1)
    {
        rotatecw(n, 4);
    }
}

void doZ(int n, int x)
{
    // 2(0,0) -> 3(0,0) -> 5(2,2) -> 1(0,0)
    for (int i = 0; i < n; ++i)
    {
        swap(rb(2, i, x), rb(1, i, x));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(1, i, x), rb(5, n - i - 1, n - x - 1));
    }
    for (int i = 0; i < n; ++i)
    {
        swap(rb(5, n - i - 1, n - x - 1), rb(3, i, x));
    }
    if (x == 0)
    {
        rotatecw(n, 0);
    }
    else if (x == n - 1)
    {
        rotateccw(n, 4);
    }
}

long long powmod(long long b, int e)
{
    long long res = 1;
    for (; e; e >>= 1)
    {
        if (e & 1)
            res = res * b;
        b = b * b;
    }
    return res;
}

void solve()
{
    memset(cntf, 0, sizeof cntf);
    memset(num, -1, sizeof num);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<char, int>> v;
    for (int i = 0; i < m; ++i)
    {
        char c;
        int a;
        getchar();
        scanf("%c %d", &c, &a);
        v.push_back({c, --a});
    }
    for (int i = 0; i < n * n * 6; ++i)
    {
        rubik[i] = i;
    }
    int cnt = 1;
    do
    {
        for (const pair<char, int> &mv : v)
        {
            if (mv.first == 'x')
            {
                dox(n, mv.second);
            }
            else if (mv.first == 'X')
            {
                doX(n, mv.second);
            }
            else if (mv.first == 'y')
            {
                doy(n, mv.second);
            }
            else if (mv.first == 'Y')
            {
                doY(n, mv.second);
            }
            else if (mv.first == 'z')
            {
                doz(n, mv.second);
            }
            else
            {
                doZ(n, mv.second);
            }
        }
        for (int i = 0; i < n * n * 6; ++i)
        {
            if (rubik[i] == i && num[i] == -1)
            {
                num[i] = cnt;
            }
        }
        cnt++;
    } while (*min_element(num, num + n * n * 6) == -1);
    long long ans = 1;
    for (int i = 0; i < n * n * 6; ++i)
    {
        int sq = sqrt(num[i]);
        int tmp = num[i];
        for (int j = 2; j <= sq && tmp > 1; ++j)
        {
            if (tmp % j == 0)
            {
                int cnt = 0;
                do
                {
                    cnt++;
                    tmp /= j;
                } while (tmp % j == 0);
                cntf[j] = max(cntf[j], cnt);
            }
        }
        if (tmp > 1)
        {
            cntf[tmp] = max(cntf[tmp], 1);
        }
    }
    for (int i = 2; i < 30; ++i)
    {
        if (cntf[i])
        {
            if (ans * powmod(i, cntf[i]) < ans)
                assert(false);
            ans *= powmod(i, cntf[i]);
        }
    }
    printf("%lld\n", ans % 1000000007);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        solve();
    }
    return 0;
}

/* 
3x3
        9  10 11
        12 13 14
        15 16 17
        --------
0 1 2 | 18 19 20 | 36 37 38 | 45 46 47
3 4 5 | 21 22 23 | 39 40 41 | 48 49 50
6 7 8 | 24 25 26 | 42 43 44 | 51 52 53
        --------
        27 28 29
        30 31 32
        33 34 35


                    (0,0) (0,1) (0,2)
                    (1,0) (1,1) (1,2)
                    (2,0) (2,1) (2,2)
                    -----------------
(0,0) (0,1) (0,2) | (0,0) (0,1) (0,2) | (0,0) (0,1) (0,2) | (0,0) (0,1) (0,2)
(1,0) (1,1) (1,2) | (1,0) (1,1) (1,2) | (1,0) (1,1) (1,2) | (1,0) (1,1) (1,2)
(2,0) (2,1) (2,2) | (2,0) (2,1) (2,2) | (2,0) (2,1) (2,2) | (2,0) (2,1) (2,2)
                    -----------------
                    (0,0) (0,1) (0,2)
                    (1,0) (1,1) (1,2)
                    (2,0) (2,1) (2,2)

  2
1 3 5 6
  4
*/