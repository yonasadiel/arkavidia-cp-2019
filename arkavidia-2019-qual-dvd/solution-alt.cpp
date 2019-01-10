// by: tony
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int h, w, hc, wc;
    int vx, vy;
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &w, &h, &wc, &hc);
    scanf("%d %d %d %d", &x1, &y1, &vx, &vy);
    x2 = vx+x1;
    y2 = vy+y1;
    w -= wc;
    h -= hc;
    if((x1 == 0 && y1 == 0) || (x1 == w && y1 == h) || (x1 == 0 && y1 == h)|| (x1 == w && y1 == 0)){
        puts("YA");
        return;
    }
    if(wc == 0 || hc == 0){
        puts("TIDAK");
        return;
    }
    // (y2 - y1)x + (x1 - x2)y = (x2 - x1)y1 - (y2 - y1)x1
    long long a = y2 - y1;
    long long b = x1 - x2;
    long long c = 1LL*(x2 - x1)*y1 - 1LL*(y2 - y1)*x1;
    if(llabs(c) % __gcd(llabs(a * w), llabs(b * h)) == 0){
        puts("YA");
    }
    else{
        puts("TIDAK");
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