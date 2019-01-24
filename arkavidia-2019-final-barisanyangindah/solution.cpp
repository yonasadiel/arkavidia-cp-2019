// by: Yonas Adiel
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];

void solve() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    long long ans = (long long) n * (n - 1) / 2;
    for (int i=0; i<n; i++) {
        int l = i, r = i;
        for (int j=i-1; j>=0; j--) {
            if ((a[j] & a[i]) == a[i]) l--;
            else break;
        }
        for (int j=i+1; j<n; j++) {
            if ((a[j] & a[i]) == a[i]) r++;
            else break;
        }
        ans -= (i - l + 1) * (r - i + 1) - 1;
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}