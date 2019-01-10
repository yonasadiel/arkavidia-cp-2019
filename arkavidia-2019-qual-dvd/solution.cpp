// by: Yonas Adiel
#include <bits/stdc++.h>
using namespace std;

long long w, h, w_l, h_l, x, y, v_x, v_y;

int solve() {
    scanf("%lld%lld", &w_l, &h_l);
    w -= w_l;
    // logo dvd ukuran w_l x h_l di monitor w x h
    // sama seperti titik di monitor (w - w_l x h - h_l)
    h -= h_l;
    scanf("%lld%lld", &x, &y);
    scanf("%lld%lld", &v_x, &v_y);

    // corner: kalo ga gerak sama sekali, brarti ga akan nabrak
    if (v_x == 0 && v_y == 0) {
        if ((x == 0 || x == w) && (y == 0 || y == h)) {
            printf("YA\n");
        } else {
            printf("TIDAK\n");
        }
        return 0;
    }

    long long gcd = __gcd(v_x, v_y);
    v_x /= gcd, v_y /= gcd;

    // kita dapat membuat barisan bilangan
    // tx(n) = ax + bx n di mana tx(n) menyatakan pada detik ke berapa logo menyentuh ujung ke-n kali, begitu pula dengan y
    // bx = w / v_x
    // ax = (w - x) / |v_x| atau x / |v_x|, tergantung arah gerak
    // kalo v_x nol, brarti cuma nabrak kalo ada di sisi
    // begitu pula sebaliknya

    long long ax, ay;
    if      (v_x > 0) { ax = (w - x); }
    else if (v_x < 0) { ax = x;       }
    else {
        printf("%s\n", ((x == 0 || x == w) ? "YA" : "TIDAK"));
        return 0;
    }
    if      (v_y > 0) { ay = (h - y); }
    else if (v_y < 0) { ay = y;       }
    else {
        printf("%s\n", ((y == 0 || y == h) ? "YA" : "TIDAK"));
        return 0;
    }

    gcd = __gcd(v_y * w, v_x * h);
    // corner: kalau gerak tapi horizontal doang, vertikal doang, atau penuh
    if (gcd == 0) {
        printf("YA\n");
        return 0;
    }

    // menghimpit sudut artinya ada n dam m sehingga
    // tx(n) = ty(m)
    // ax + bx n = ay + by m
    // bx n - by m = ay - ax
    // w n / v_x - h m / v_y = ($ay) / v_y - ($ax) / v_x
    // v_y w n - v_x h m = v_x ($ay) - v_y ($ax)
    // persamaan di atas ada solusi n, m nya kalau
    // v_x ($ay) - v_y ($ax) habis dibagi gcd(v_y w, v_x h)

    printf("%s\n", ((abs(v_x * ay - v_y *ax) % gcd == 0)? "YA" : "TIDAK"));
}

int main() {
    int t;
    scanf("%d", &t);
    while (scanf("%d%d", &w, &h) == 2) {
        solve();
    }
}