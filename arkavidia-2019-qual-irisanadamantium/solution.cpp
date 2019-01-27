// by: Yonas Adiel
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n; // banyak lapisan logam
int a[200005]; // jenis tiap lapisan
int b[100005]; // kondisi cnt pada saat kemunculan terakhir tiap jenis lapisan
int cnt;
long long cost[200005]; // biaya pemotongan

int solve() {
    for (int i=0; i<2*n; i++) {
        scanf("%d", &a[i]);
    }
    memset(b, -1, sizeof b);
    long long total_cost = 0;
    cnt = 0;
    for (int i=2*n-1; i>=0; i--) {
        if (b[a[i]] == -1) {
            b[a[i]] = cnt;
        } else {
            if ((cnt - b[a[i]]) % 2 == 0) {
                total_cost += cost[i];
                total_cost %= MOD;
                cnt++;
            }
        }
    }
    printf("%lld\n", total_cost);
}

int main() {
    cost[0] = 2;
    for (int i=1; i<200005; i++) {
        cost[i] = cost[i-1] << 1;
        cost[i] %= MOD;
    }
    int t;
    scanf("%d", &t);
    while (scanf("%d", &n) == 1) {
        solve();
    }
}