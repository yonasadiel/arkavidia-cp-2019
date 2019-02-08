// by: Tony

#include <bits/stdc++.h>

using namespace std;

__uint128_t p2(__uint128_t a){
    return a * a;
}

int solve(){
    int d,x,y,vk,va;
    scanf("%d %d %d %d %d", &d, &x, &y, &vk, &va);
    __uint128_t bvk= abs(vk);
    __uint128_t bva= abs(va);
    __uint128_t by = abs(y);
    __uint128_t bd = abs(d);
    __uint128_t bx = abs(x);
    // if(va > vk || (1.0L*(y+d)*vk/va <= sqrtl(1LL*x*x + 1LL*(y+d)*(y+d)) && (1.0L*(y)*vk/va <= sqrtl(1LL*x*x + 1LL*(y)*(y)))))
    if(va > vk || (p2(by+bd)*p2(bvk) < p2(bva)*(p2(bx) + p2(by+bd)) && p2(by)*p2(bvk) < p2(bva)*(p2(y) + p2(x))))
        puts("YA");
    else
        puts("TIDAK");
    return 0;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}