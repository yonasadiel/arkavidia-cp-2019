// by: Tony

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int NMAX = 100000;
int n,m, t;
char r[NMAX + 5];
char s[NMAX + 5];

bool check(const char *s, int len, int sublen){
    int seglen = len / sublen;
    for(int i=1;i<seglen;++i){
        for(int j=0;j<sublen;++j){
            if(s[j] != s[i*sublen + j])
                return false;
        }
    }
    return true;
}

void solve(){
    scanf("%s", r);
    scanf("%s", s);
    n = strlen(r);
    m = strlen(s);
    if(strncmp(r, s, min(n, m)) != 0){
        puts("-1");
        return;
    }
    int a = __gcd(n, m);
    int sq = sqrt(a);
    vector<int> v;
    for(int i=1;i<=sq;++i){
        if(a%i == 0){
            v.pb(i);
            if(a/i != i){
                v.pb(a/i);
            }
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int x : v){
        if(check(r, n, x) && check(s, m, x)){
            s[x] = 0;
            printf("%s\n", s);
            return;
        }
    }
    puts("-1");
}

int main(){
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}