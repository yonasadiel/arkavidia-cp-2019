// by: Yonas Adiel
#include <bits/stdc++.h>
using namespace std;

int w, h, x_1, y_1, x_2, y_2;

int solve() {
    scanf("%d%d", &x_1, &y_1);
    scanf("%d%d", &x_2, &y_2);
    int x_c, y_c;
    if      (x_1 < x_2) { x_c = (w - x_1); }
    else if (x_1 > x_2) { x_c = x_1;       }
    else {
        printf("%s\n", ((x_1 == 0 || x_1 == w) ? "YAY" : "NAY"));
        return 0;
    }
    if      (y_1 < y_2) { y_c = (h - y_1); }
    else if (y_1 > y_2) { y_c = y_1;       }
    else {
        printf("%s\n", ((y_1 == 0 || y_1 == h) ? "YAY" : "NAY"));
        return 0;
    }

    // at this point:
    // logo hit the left-right wall at t = x_c, x_c + w, x_c + 2w, and so on
    // logo hit the top-bottom wall at t = y_c, y_c + h, y_c + 2h, and so on
    // we need to determine is it exist a, b so that x_c + aw = y_c + bh
    // aw - bh = y_c - x_c will have solution only and only y_c - x_c divisible by gcd(w, h)
    printf("%s\n", ((abs(y_c - x_c) % __gcd(w, h) == 0) ? "YAY" : "NAY"));
}

int main() {
    int t;
    scanf("%d", &t);
    while (scanf("%d%d", &w, &h) == 2) {
        solve();
    }
}