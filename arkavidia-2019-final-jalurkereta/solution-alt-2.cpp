#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<pair<int, int>> adj[300002];
vector<int> padj[300002];
int n;
int deg[300002];
char p[300002];
int a[300002];
int b[300002];
int c[300002];
int atas[300002];
int dp[300002];
int bawah[300002];
bool vis[300002];

int dfs(int v)
{
    if (dp[v] == -1)
    {
        dp[v] = 0;
        for (int x : padj[v])
        {
            dp[v] = max(dp[v], dfs(x) + 1);
        }
    }
    return dp[v];
}

int solve()
{
    memset(dp, -1, sizeof dp);
    memset(atas, 0, sizeof atas);
    memset(bawah, 0, sizeof bawah);
    memset(vis, false, sizeof vis);
    memset(deg, 0, sizeof deg);
    int m, dummy;
    n = 0;
    scanf("%d%d", &m, &dummy);
    for (int i = 0; i < m; ++i)
    {
        getchar();
        scanf("%c %d %d %d", p + i, a + i, b + i, c + i);
        n = max(max(n, a[i]), max(b[i], c[i]));
        if (p[i] == 'A')
        {
            adj[a[i]].push_back({b[i], i});
            adj[a[i]].push_back({c[i], i});
            deg[b[i]]++;
            deg[c[i]]++;
        }
        else
        {
            adj[a[i]].push_back({c[i], i});
            adj[b[i]].push_back({c[i], i});
            deg[c[i]] += 2;
        }
    }
    queue<int> q;
    q.push(1);
    atas[1] = 1;
    bawah[1] = 2;
    int now = 3;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if (adj[tmp].size() == 1)
        {
            if (--deg[adj[tmp][0].first])
                continue;
            int idx = adj[tmp][0].second;
            int x = adj[tmp][0].first;
            int m = a[idx];
            int n = b[idx];
            atas[x] = atas[m];
            bawah[x] = bawah[n];
            q.push(x);
        }
        else if (adj[tmp].size() == 2)
        {
            int x = adj[tmp][0].first;
            int y = adj[tmp][1].first;
            --deg[x];
            --deg[y];
            atas[x] = atas[tmp];
            bawah[y] = bawah[tmp];
            bawah[x] = atas[y] = now++;
            q.push(x);
            q.push(y);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        padj[atas[i]].push_back(bawah[i]);
    }
    printf("%d\n", dfs(1));
    for (int i = 1; i <= n; ++i)
    {
        padj[i].clear();
        adj[i].clear();
    }
    return 0;
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