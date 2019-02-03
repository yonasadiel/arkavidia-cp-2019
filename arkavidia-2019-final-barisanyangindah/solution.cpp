// by: Wiwit Rifai
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;

int a[N];

int main() {
  auto startt = clock();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    long long ans = 0;
    vector<tuple<int, int, int> > seg;
    for (int i = 0; i < n; ++i) {
      vector<tuple<int, int, int> > new_seg;
      int le = i, last = -1;
      // Pertama maintan mask yang mungkin sehingga terdapat indeks x sehingga AND dari [x, i] = mask.
      // Lalu setiap mask tsb di maintain indeks l terkiri sehingga AND [l,i] = mask dan
      // indeks r terkiri sehingga pada range [r,i] tidak ada a[j] = mask untuk r <= j <= i.
      // Untuk setiap indeks x sehingga l <= x < r, pasti range [x, i] itu tidak indah.
      // Terdapat at most log_2(A) mask yang berbeda
      for (auto & it : seg) {
        int mask, l, r;
        tie(mask, l, r) = it;
        int res = mask & a[i];
        if (res == a[i]) {
          // mask nya jadi a[i], perlu cari indeks le terkecil sehingga AND [le, i] = a[i] karena
          // semua x pada le <= x <= i pasti range [x, i] jadi tidak indah
          le = min(le, l);
        }
        else if (res == mask) {
          // mask tidak terpengaruh oleh a[i]
          new_seg.push_back(it);
        }
        else if (res != last) {
          // mask terpengaruh oleh a[i], semua segment [x,i] untuk l <= x < r menjadi indah semua
          // tapi mask nya harus tetep di simpan, karena suatu saat bisa jadi tidak indah lagi.
          new_seg.emplace_back(res, l, l);
        }
        last = res;
      }
      // tambahin mask terakhir
      new_seg.emplace_back(a[i], le, i+1);
      seg.swap(new_seg);

      // Hitung banyak range [x,i] yang indah
      int cnt = i+1;
      for (auto it : seg) {
        int mask, l, r;
        tie(mask, l, r) = it;
        cnt -= r-l;
      }
      ans += cnt;
    }
    printf("%lld\n", ans);
  }
  cerr << " Time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s" << endl;
  return 0;
}