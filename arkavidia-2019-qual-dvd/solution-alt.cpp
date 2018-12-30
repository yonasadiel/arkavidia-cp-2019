// by: tony
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int h,w;
    int x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &h, &w, &x1, &y1, &x2, &y2);
    // (y2 - y1)x + (x1 - x2)y = (x2 - x1)y1 - (y2 - y1)x1
    long long a = y2 - y1;
    long long b = x1 - x2;
    long long c = 1LL*(x2 - x1)*y1 - 1LL*(y2 - y1)*x1;
    if(llabs(c) % __gcd(llabs(a * w), llabs(b * h)) == 0){
        puts("YAY");
    }
    else{
        puts("NAY");
    }
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}