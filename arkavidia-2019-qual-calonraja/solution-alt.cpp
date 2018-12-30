#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];
int subtree[100005];

int l;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;


int dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    subtree[v] = 0;
    for (int u : adj[v])
        if (u != p)
            subtree[v] += dfs(u, v);

    tout[v] = ++timer;
    return subtree[v] + 1;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int solve() {
    memset(subtree, -1, sizeof subtree);
    for (int i=0; i<n; i++) {
        adj[i].clear();
    }

    int u, v;
    for (int i=0; i<n-1; i++) {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess(0);

    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        int anc = lca(x, y);
        if (anc == y) {
            int ans = n - 1;
            for (int v : adj[y]) {
                if (is_ancestor(v, x) && !is_ancestor(v, y)) {
                    ans -= 1 + subtree[v];
                }
            }
            printf("%d\n", ans);
        } else {
            printf("%d\n", subtree[y]);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (scanf("%d", &n) == 1) {
        solve();
    }
}