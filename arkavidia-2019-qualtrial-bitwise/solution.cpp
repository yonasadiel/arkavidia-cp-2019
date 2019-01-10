#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x, n;
    string op;
    cin >> t;
    while (t--) {
        cin >> x >> n >> op;
        if (op != "XOR") {
            for (int i=0; i<n; i++) {
                printf("%d%c", x, (i == n-1 ? '\n' : ' '));
            }
        } else {
            if (x == 1 && n % 2 == 0) {
                printf("2 3%c", (n == 2? '\n' : ' '));
                for (int i=2; i<n; i++) {
                    printf("%d%c", 1, (i == n-1 ? '\n' : ' '));
                }
            } else if (n & 1) {
                for (int i=0; i<n; i++) {
                    printf("%d%c", (i == 0? x : 1), (i == n-1 ? '\n' : ' '));
                }
            } else {
                for (int i=0; i<n; i++) {
                    printf("%d%c", (i == 0? x^1 : 1), (i == n-1 ? '\n' : ' '));
                }
            }
        }
    }
}