// by: Wiwit Rifai
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 20;

int a[N];

// sparse table
int sp_and[LG][N], sp_min[LG][N];

int get_and(int l, int r) {
  int len = r - l;
  int lg = 31 - __builtin_clz(len);
  return sp_and[lg][l] & sp_and[lg][r-(1<<lg)];
}

int get_min(int l, int r) {
  int len = r - l;
  int lg = 31 - __builtin_clz(len);
  return min(sp_min[lg][l], sp_min[lg][r-(1<<lg)]);
}

// cari batas kiri agar range [x, i] itu tidak indah dan punya AND[x, i] = mask
// binser cari L terkiri sehingga AND [L, i] = mask
int get_left(int i, int mask) {
  int lo = 0, hi = i;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (get_and(mid, i+1) < mask)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}

// cari batas kanan agar range [x, i] itu tidak indah dan punya AND[x, i] = mask
// caranya: binser cari R terkiri sehingga semua elemen [R, i] itu > mask,
// sehingga pasti [R, i] tidak menganding a[j] = mask,
// karena elemen a[R-1] itu pasti <= mask, maka AND[R, i] <= mask
// Jadi R-1 adalah batas terkanan yang mungkin sehingga AND[R-1, i] = mask.
int get_right(int i, int mask) {
  int lo = 0, hi = i+1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (get_min(mid, i+1) <= mask)
      lo = mid + 1;
    else
      hi = mid;
  }
  return hi;
}

int main() {
  auto startt = clock();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      sp_min[0][i] = sp_and[0][i] = a[i];
    }
    // bangun sparse table
    for (int i = 0; i + 1 < LG; ++i) {
      for (int j = 0; j + (1 << (i+1)) <= n; ++j) {
        sp_min[i+1][j] = min(sp_min[i][j], sp_min[i][j+(1<<i)]);
        sp_and[i+1][j] = sp_and[i][j] & sp_and[i][j+(1<<i)];
      }
    }
    long long ans = 0;
    vector<int> and_masks;
    for (int i = 0; i < n; ++i) {
      // update semua mask yang mungkin setelah ditambah a[i]
      vector<int> new_masks;
      int last = -1;
      for (int mask : and_masks) {
        mask &= a[i];
        if (last != mask)
          new_masks.push_back(mask);
        last = mask;
      }
      if (new_masks.empty() || new_masks.back() != a[i])
        new_masks.push_back(a[i]);
      and_masks.swap(new_masks);

      // hitung range [x, i] yang indah
      int cnt = i+1;
      for (int mask : and_masks) {
        // cari batas kiri l dan batas kanan r sehingga setiap l <= x < r maka range [x, i] itu tidak indah dan AND [x,i] = mask 
        int l = get_left(i, mask), r = get_right(i, mask);
        r = max(r, l);
        cnt -= r - l;
      }
      ans += cnt;
    }
    printf("%lld\n", ans);
  }
  cerr << " Time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s" << endl;
  return 0;
}