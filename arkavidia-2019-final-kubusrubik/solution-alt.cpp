// by: Yonas Adiel
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define F 0
#define L 1
#define B 2
#define R 3
#define U 4
#define D 5

char cface[] = {'F', 'L', 'B', 'R', 'U', 'D'};

int n;
struct piece
{
    int x;
    int y;
    int color;
    piece()
    {
        x = y = color = -1;
    }
    piece(int _c, int _x, int _y)
    {
        x = _x;
        y = _y;
        color = _c;
    }
    piece(const piece &_o)
    {
        x = _o.x;
        y = _o.y;
        color = _o.color;
    }
};

piece faces[7][22][22];
piece run[7][22][22];
long long path_long[22][22][22];

void rotate_face(int f, bool cw = true)
{
    piece temp[22][22];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = piece(faces[f][i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cw)
            {
                faces[f][i][j] = temp[j][n - i - 1];
            }
            else
            {
                faces[f][i][j] = temp[n - j - 1][i];
            }
        }
    }
}

void print_face()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 + 7 * n; j++)
            printf(" ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[faces[U][i][j].color], faces[U][i][j].x, faces[U][i][j].y);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[faces[L][i][j].color], faces[L][i][j].x, faces[L][i][j].y);
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[faces[F][i][j].color], faces[F][i][j].x, faces[F][i][j].y);
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[faces[R][i][j].color], faces[R][i][j].x, faces[R][i][j].y);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 + 7 * n; j++)
            printf(" ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[faces[D][i][j].color], faces[D][i][j].x, faces[D][i][j].y);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 + 7 * n; j++)
            printf(" ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[faces[B][i][j].color], faces[B][i][j].x, faces[B][i][j].y);
        printf("\n");
    }
    printf("\n");
    printf("------\n");
}

void print_run()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 + 7 * n; j++)
            printf(" ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[run[U][i][j].color], run[U][i][j].x, run[U][i][j].y);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[run[L][i][j].color], run[L][i][j].x, run[L][i][j].y);
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[run[F][i][j].color], run[F][i][j].x, run[F][i][j].y);
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[run[R][i][j].color], run[R][i][j].x, run[R][i][j].y);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 + 7 * n; j++)
            printf(" ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[run[D][i][j].color], run[D][i][j].x, run[D][i][j].y);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 + 7 * n; j++)
            printf(" ");
        for (int j = 0; j < n; j++)
            printf("%c(%d,%d) ", cface[run[B][i][j].color], run[B][i][j].x, run[B][i][j].y);
        printf("\n");
    }
    printf("\n");
    printf("------\n");
}

long long fastpow(long long a, long long b)
{
    long long ans = 1;
    long long p = 1;
    for (int i = 0; i < 40; i++)
    {
        if (b & p)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        p <<= 1;
    }
    return ans;
}

long long invmod(long long x)
{
    return fastpow(x, MOD - 2);
}

void solve()
{
    int m;
    scanf("%d%d\n", &n, &m);
    for (int f = 0; f < 6; f++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                faces[f][i][j] = piece(f, i, j);

    char cc;
    int x;
    while (m--)
    {
        scanf("%c %d\n", &cc, &x);
        piece temp[7][n + 2][n + 2];
        for (int f = 0; f < 6; f++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    temp[f][i][j] = faces[f][i][j];
                }
            }
        }
        if (cc == 'X' || cc == 'x')
        {
            int path[] = {F, R, B, L};
            int xpath[] = {x - 1, x - 1, n - x, x - 1};
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (cc == 'X')
                        faces[path[i]][xpath[i]][i == 2 ? n - j - 1 : j] = temp[path[(i + 4 - 1) % 4]][xpath[(i + 4 - 1) % 4]][(i + 4 - 1) % 4 == 2 ? n - j - 1 : j];
                    else /* cc == 'x' */
                        faces[path[i]][xpath[i]][i == 2 ? n - j - 1 : j] = temp[path[(i + 1) % 4]][xpath[(i + 1) % 4]][(i + 1) % 4 == 2 ? n - j - 1 : j];
                }
            }
            if (x == 1)
            {
                rotate_face(U, cc == 'X');
            }
            else if (x == n)
            {
                rotate_face(D, cc == 'x');
            }
        }
        else if (cc == 'Y' || cc == 'y')
        {
            int path[] = {F, U, B, D};
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (cc == 'Y')
                        faces[path[i]][j][x - 1] = temp[path[(i + 1) % 4]][j][x - 1];
                    else /* cc == 'y' */
                        faces[path[i]][j][x - 1] = temp[path[(i + 4 - 1) % 4]][j][x - 1];
                }
            }
            if (x == 1)
            {
                rotate_face(L, cc == 'y');
            }
            else if (x == n)
            {
                rotate_face(R, cc == 'Y');
            }
        }
        else /* cc == 'Z' || cc == 'z' */
        {
            int path[] = {U, R, D, L};
            int xpath[] = {n - x, x - 1, x - 1, n - x};
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i & 1)
                    {
                        if (cc == 'Z')
                            faces[path[i]][j][xpath[i]] = temp[path[(i + 4 - 1) % 4]][xpath[(i + 4 - 1) % 4]][j];
                        else /* cc == 'z' */
                            faces[path[i]][j][xpath[i]] = temp[path[(i + 1) % 4]][xpath[(i + 1) % 4]][n - j - 1];
                    }
                    else /* !(i & 1) */
                    {
                        if (cc == 'Z')
                            faces[path[i]][xpath[i]][j] = temp[path[(i + 4 - 1) % 4]][n - j - 1][xpath[(i + 4 - 1) % 4]];
                        else /* cc == 'z' */
                            faces[path[i]][xpath[i]][j] = temp[path[(i + 1) % 4]][j][xpath[(i + 1) % 4]];
                    }
                }
            }
            if (x == 1)
            {
                rotate_face(F, cc == 'z');
            }
            else if (x == n)
            {
                rotate_face(B, cc == 'Z');
            }
        }
        // print_face();
    }
    long long ans = 1;
    int cnt = 6 * n * n;
    long long path_long_count = 1;
    for (int f = 0; f < 6; f++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                path_long[f][i][j] = -1;
                run[f][i][j] = piece(f, i, j);
            }
        }
    }
    while (cnt > 0)
    {
        piece temp[7][n + 2][n + 2];
        for (int f = 0; f < 6; f++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    temp[f][i][j] = run[f][i][j];
                }
            }
        }
        for (int f = 0; f < 6; f++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    piece to = faces[f][i][j];
                    run[f][i][j] = piece(temp[to.color][to.x][to.y]);
                    if (path_long[f][i][j] == -1 && run[f][i][j].color == f && run[f][i][j].x == i && run[f][i][j].y == j)
                    {
                        path_long[f][i][j] = path_long_count;
                        cnt--;
                    }
                }
            }
        }
        path_long_count++;
        // print_run();
    }

    ans = 1;
    for (int f = 0; f < 6; f++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = (ans * invmod(__gcd(ans, path_long[f][i][j]))) % MOD;
                ans = (ans * path_long[f][i][j]) % MOD;
            }
        }
    }

    printf("%lld\n", ans % MOD);
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