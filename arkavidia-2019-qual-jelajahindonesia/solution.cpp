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
ll ans;
vector<pii> adj[NMAX+5];

pll dfs(int v, int p){
    if(adj[v].size() == 1 && v!=p){
        return {0, 0};
    }
    pll now = {0, LLONG_MIN/2};
    for(int i=0;i<adj[v].size();++i){
        pii x = adj[v][i];
        if(x.fi == p) continue;
        pll ret = dfs(x.fi, v);
        ans = max(ans, x.se + ret.se);
        ans = max(ans, now.fi + x.se + ret.se);
        ans = max(ans, now.se + x.se + ret.fi);
        ans = max(ans, now.se + x.se + ret.se);
		if(v != p)
			now.fi = max(now.fi, x.se + ret.fi);
		else
			now.fi = x.se + ret.fi;
        now.se = max(now.se, x.se + ret.se);
    }
    ans = max(ans, now.se);
    return now;
}

int main(){
    scanf("%d", &t);
    while(t--){
        ll sum = 0;
        ans = LLONG_MIN/2;
        scanf("%d", &n);
        for(i=1;i<n;++i){
           int a, b, c;
           scanf("%d %d %d", &a, &b, &c);
           adj[a].pb({b, c});
           adj[b].pb({a, c});
           sum += c;
        }

        if(n == 2){
            printf("%lld\n", sum);
        }
        else{
            pll tmp =  dfs(1,1);
			debug(tmp.fi);
			debug(tmp.se);
            if(adj[1].size() == 1){
                ans = max(ans, tmp.fi);
            }
			debug(ans);
            printf("%lld\n", 2*sum - ans);
        }

        for(i=1;i<=n;++i){
            adj[i].clear();
        }
    }
    return 0;
}

