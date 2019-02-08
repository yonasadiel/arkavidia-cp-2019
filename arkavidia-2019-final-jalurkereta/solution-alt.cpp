// by: Wiwit Rifai
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int col[N][2], ncol;

vector<int> starts;
vector<int> g[N];
int din[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d", &n);
        m = n * 3 / 2 + 1;
        memset(pre, 0, sizeof pre);
        memset(nxt, 0, sizeof nxt);
        for (int i = 0; i < n; ++i)
        {
            char ty[3];
            int a, b, c;
            scanf("%s %d %d %d", ty, &a, &b, &c);
            if (ty[0] == 'A')
            {
                assert(nxt[a][0] == 0 || nxt[a][0] == b);
                assert(pre[b][1] == 0 || nxt[b][1] == a);
                nxt[a][0] = b;
                pre[b][1] = a;
                assert(nxt[a][1] == 0 || nxt[a][1] == c);
                assert(pre[c][0] == 0 || nxt[c][0] == a);
                nxt[a][1] = c;
                pre[c][0] = a;
            }
            else
            {
                assert(pre[c][0] == 0 || pre[c][0] == a);
                assert(nxt[a][1] == 0 || nxt[a][1] == c);
                pre[c][0] = a;
                nxt[a][1] = c;
                assert(pre[c][1] == 0 || nxt[c][1] == b);
                assert(nxt[b][0] == 0 || nxt[b][0] == c);
                pre[c][1] = b;
                nxt[b][0] = c;
            }
        }
        starts.clear();
        for (int i = 1; i <= m; ++i)
            if (pre[i][0] == 0 && pre[i][1] == 0)
                starts.push_back(i);
        assert(starts.size() > 0);
        ncol = 0;
        col[starts[0]][0] = ++ncol;
        for (int i = 1; i < starts.size(); ++i)
        {
            col[starts[i - 1]][1] = col[starts[i]][0] = ++ncol;
        }
        col[starts.back()][1] = ++ncol;
        for (int i = 0; i < starts.size(); ++i)
        {
            int v = starts[i], l, r;
            l = nxt[v][0];
            r = nxt[v][1];
            if (l == 0 && r == 0)
                continue;
            if (l == 0)
                l = r;
            if (r == 0)
                r = l;
            if (pre[l][0] == v || pre[l][0] == 0)
                col[l][0] = col[v][0];
            if (pre[r][1] == v || pre[r][1] == 0)
                col[r][1] = col[v][1];
            if (l != r)
            {
                col[l][1] = col[r][0] = ++ncol;
            }
            if (col[l][0] && col[l][1])
                starts.push_back(l);
            if (col[r][0] && col[r][1] && r != l)
                starts.push_back(r);
        }
        for (int i = 1; i <= ncol; ++i)
            g[i].clear();
        fill(din, din + ncol + 1, 0);
        for (int i = 1; i <= m; ++i)
        {
            assert(col[i][0] && col[i][1]);
            g[col[i][0]].push_back(col[i][1]);
            ++din[col[i][1]];
        }
        vector<int> topo;
        for (int i = 1; i <= ncol; ++i)
            if (din[i] == 0)
                topo.push_back(i);
        for (int i = 0; i < topo.size(); ++i)
        {
            int v = topo[i];
            for (int u : g[v])
            {
                --din[u];
                if (din[u] == 0)
                    topo.push_back(u);
            }
        }
        assert(topo.size() == ncol);
        fill(din, din + ncol + 1, 0);
        int ans = 0;
        for (int v : topo)
        {
            ans = max(ans, (int)din[v]);
            for (int u : g[v])
                din[u] = max(din[u], din[v] + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
