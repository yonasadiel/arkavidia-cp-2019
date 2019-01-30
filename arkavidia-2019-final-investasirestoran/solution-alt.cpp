// by: Yonas Adiel
#include <bits/stdc++.h>
using namespace std;

int n, m, p, x;
int a[205];

long long sim(int pos) {
    int mr = m;
    long long ret = 0;
    int b[205];
    for (int i=0; i<n; i++) b[i] = a[i];
    while (mr > 0) {
        while (b[pos] == 0) { pos++; ret++; pos %= n; }
        b[pos] = 0;
        mr--;
        ret += p;
        pos += p;
        pos %= n;
    }
    return ret;
}

void solve() {
    memset(a, 0, sizeof a);
    scanf("%d%d%d", &n, &m, &p);
    for (int i=0; i<m; i++) {
        scanf("%d", &x);
        a[x-1]++;
    }
    int ans = 0;
    long long anst = 1e18;
    for (int i=0; i<n; i++) {
        long long t = sim(i);
        if (t < anst) {
            ans = i;
            anst = t;
        }
    }
    printf("%d %lld\n", ans+1, anst);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}