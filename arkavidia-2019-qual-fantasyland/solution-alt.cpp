// by: Yonas Adiel
#include <bits/stdc++.h>
using namespace std;

int n, q;
int price[1005];
pair<int, int> menu[1005];

int solve() {
    for (int i=1; i<1005; i++) {
        price[i] = 2000000000; // INF
    }
    price[0] = 0;
    for (int i=0; i<n; i++) {
        scanf("%d%d", &menu[i].first, &menu[i].second);
    }
    sort(menu, menu + n);
    for (int i=0; i<n; i++) {
        int k = menu[i].first, p = menu[i].second;
        for (int j=k; j<1005; j++) {
            price[j] = min(price[j], price[j-k] + p);
        }
    }
    while (q--) {
        int m;
        scanf("%d", &m);
        printf("%d\n", price[m]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (scanf("%d%d", &n, &q) == 2) {
        solve();
    }
}