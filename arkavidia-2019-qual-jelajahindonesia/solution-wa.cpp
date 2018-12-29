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
vector<pii> adj[NMAX+5];
ll dp[NMAX + 5];

void dfs(int v, int p){
    for(pii x : adj[v]){
        if(x.fi == p) continue;
        dp[x.fi] = dp[v] + x.se;
        dfs(x.fi, v);
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        ll sum = 0;
        scanf("%d", &n);
        for(i=1;i<n;++i){
           // Asumsi input : node_u node_v cost
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
            memset(dp, 0, sizeof dp);
            dfs(1, 1);
            int node = max_element(dp+2, dp+n+1) - dp;
            memset(dp, 0, sizeof dp);
            dfs(node, node);
            ll ans;
            if(node > 2){
                ans = *max_element(dp+2, dp+node);
                if(node < n){
                    ans = max(ans, *max_element(dp+node+1, dp+n+1));
                }
            }
            else{
                ans = *max_element(dp+3, dp+n+1);
            }

            // debug(ans);
            printf("%lld\n", 2*sum - ans);
        }

        for(i=1;i<=n;++i){
            adj[i].clear();
        }
    }
    return 0;
}