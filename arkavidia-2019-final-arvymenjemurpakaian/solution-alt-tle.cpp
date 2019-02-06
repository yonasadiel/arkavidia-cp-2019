// by: Tony

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    vector<int> v;
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
    bitset<200001> b;
    b.reset();
    b[0] = 1;
    for(int x : v){
        for(int i=x;i<=n;i+=x){
            b |= b << i;
        }
    }
    if(b[m] && b[n-m]){
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