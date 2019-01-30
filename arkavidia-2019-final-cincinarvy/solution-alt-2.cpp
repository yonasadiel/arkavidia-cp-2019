// by: Tony

#include <bits/stdc++.h>

using namespace std;

int solve(){
    int d,x,y,vk,va;
    scanf("%d %d %d %d %d", &d, &x, &y, &vk, &va);
    if(va > vk || (1.0L*(y+d)*vk/va <= sqrtl(1LL*x*x + 1LL*(y+d)*(y+d)) && (1.0L*(y)*vk/va <= sqrtl(1LL*x*x + 1LL*(y)*(y)))))
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