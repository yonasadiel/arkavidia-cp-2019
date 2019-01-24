#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
int dp[200005];

void solve() {
    scanf("%d%d", &n, &m);

    vector<int> factors;
    for (int l=2, k=n; l<=k && k > 1; l++) {
        if (k % l == 0) {
            factors.push_back(l);
            while (k % l == 0) k /= l;
        }
    }

    dp[0] = true;
    for (int i=1; i<=n; i++) {
        dp[i] = false;
        for (int j : factors) {
            if (j <= i) dp[i] |= dp[i - j];
        }
    }
    printf("%s\n", (dp[m] && dp[n-m] ? "YA" : "TIDAK"));
}

int main() {
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}