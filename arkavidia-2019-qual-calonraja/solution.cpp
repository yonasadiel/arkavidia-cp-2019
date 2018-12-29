// by: Tony
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double PI = acos(-1);

const int NMAX = 100000;
int n,i,j,k,t;
int q;
int l;
vector<int> adj[NMAX+5];
int up[NMAX+5][21];
int timer;
int tin[NMAX+5], tout[NMAX+5];
int sz[NMAX+5];

/* Copy From cp-algorithms.com */

void dfslca(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
    sz[v] = 1;
	for(int i=1;i<=l;++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for(int x : adj[v]){
		if(x!=p){
			dfslca(x, v);
            sz[v] += sz[x];
        }
    }
	tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int find_child(int u, int v){
	for(int i=l;i>=0;--i)
		if(!is_ancestor(up[v][i], u))
			v = up[v][i];
	return v;
}

void preprocess(int root){
	memset(up, 0, sizeof up);
	timer = 0;
	l = ceil(log2(n));
	dfslca(root, root);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=1;i<n;++i){
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        preprocess(1);

        scanf("%d", &q);
        while(q--){
            int x, y;
            /*
                x is root, y is subtree
            */
            scanf("%d %d", &x, &y);
            if(x == y)
                printf("%d\n", n);
            else if(is_ancestor(y, x))
                printf("%d\n", n - sz[find_child(y, x)]);
            else
                printf("%d\n", sz[y]);
        }

        for(i=1;i<=n;++i)
            adj[i].clear();
    }
    return 0;
}