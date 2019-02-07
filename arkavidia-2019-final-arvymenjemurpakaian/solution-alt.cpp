// by: Tony

#include <bits/stdc++.h>

using namespace std;

char dp[7][200002];
vector<int> v;
int n, m;

char get(int idx, int rem){
    char &ans = dp[idx][rem];
    if(ans == -1){
        if(idx == 0){
            ans = rem == 0;
        }
        else{
            ans = get(idx-1, rem);
            for(int i=v[idx-1];i<=rem;i+=v[idx-1]){
                if(get(idx-1, rem - i) == 1){
                    ans = 1;
                    break;
                }
            }
        }
    }
    return ans;
}

void solve(){
    v.clear();
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &m);
    int sq = sqrt(n);
    int tmp = n;
    for(int i=2;i<=sq && tmp>1;++i){
        if(tmp % i == 0){
            v.push_back(i);
            do{
                tmp/=i;
            }while(tmp % i == 0);
        }
    }
    if(tmp > 1){
        v.push_back(tmp);
    }
    if(get(v.size(), m) == 1 && get(v.size(), n-m) == 1){
        puts("YA");
    }
    else{
        puts("TIDAK");
    }
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}