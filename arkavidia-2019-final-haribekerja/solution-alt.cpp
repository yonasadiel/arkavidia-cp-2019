#include <bits/stdc++.h>
using namespace std;

vector<int> lantai;

bool is_valid(int x) {
    while (x > 0) {
        if (x % 10 == 4) return false;
        if (x % 100 == 13) return false;
        x /= 10;
    }
    return true;
}

void precompute() {
    for (int i=1; i<=1000000; i++) {
        if (is_valid(i)) {
            lantai.push_back(i);
        }
    }
}

void solve() {
    int n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        int lo = lower_bound(lantai.begin(), lantai.end(), x) - lantai.begin();
        printf("%d%c", (lantai[lo] == x ? lo + 1 : -1), (i == n-1 ? '\n' : ' '));
    }
}

int main() {
    precompute();
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}