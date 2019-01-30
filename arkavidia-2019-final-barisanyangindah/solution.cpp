// by: Yonas Adiel
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];
vector<int> zeros[32];

void solve() {
    for (int j=0; j<31; j++) { zeros[j].push_back(-1); }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        for (int j=0; j<31; j++)
            if ((a[i] & (1 << j)) == 0)
                zeros[j].push_back(i);
    }
    for (int j=0; j<31; j++) { zeros[j].push_back(n); }

    long long ans = (long long) n * (n - 1) / 2;
    for (int i=0; i<n; i++) {
        int l = 0, r = n - 1;
        for (int j=0; j<31; j++) {
            if (a[i] & (1 << j)) {
                int k = lower_bound(zeros[j].begin(), zeros[j].end(), i) - zeros[j].begin();
                r = min(r, zeros[j][k] - 1);
                l = max(l, zeros[j][k - 1] + 1);
            }
        }
        ans -= (i - l + 1) * (r - i + 1) - 1;
    }
    printf("%lld\n", ans);
    for (int j=0; j<31; j++) { zeros[j].clear(); }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}