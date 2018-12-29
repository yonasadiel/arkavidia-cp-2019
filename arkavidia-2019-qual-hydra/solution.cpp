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
ll a[NMAX + 5];

ll divi(ll val){
    ll ans = 0;
    for(int i=0;i<n;++i){
        ll tmp = a[i];
        while(tmp){
            tmp /= val;
            ans += tmp;
        }
    }
    return ans;
}

__uint128_t bigdivi(ll val){
    __uint128_t ans = 0;
    for(int i=0;i<n;++i){
        ll tmp = a[i];
        while(tmp){
            tmp /= val;
            ans += tmp;
        }
    }
    return ans;
}

void print128(__uint128_t val){
    const __uint128_t pem = 1000000000000000000LL;
    ll dep = val / pem;
    ll bel = val % pem;
    if(dep > 0)
        printf("%lld", dep);
    printf("%lld\n", bel);
}

int main(){
    scanf("%d", &t);
    while(t--){
        ll val;
        scanf("%d %lld", &n, &val);
        for(i=0;i<n;++i)
            scanf("%lld", a+i);
        
        vector<ll> v;
        // vector<__uint128_t> v;
        int sq = sqrtl(val);
        for(i=2;i<=sq && val;++i){
            if(val % i == 0){
                int cnt = 0;
                do{
                    cnt ++;
                    val /= i;
                }while(val % i == 0);
                v.pb(divi(i)/cnt);
                // v.pb(bigdivi(i)/cnt);
            }
        }
        if(val > 1){
            v.pb(divi(val));
            // v.pb(bigdivi(i));
        }

        printf("%lld\n", *min_element(v.begin(), v.end()));
        // print128(*min_element(v.begin(), v.end()));
    }
    return 0;
}