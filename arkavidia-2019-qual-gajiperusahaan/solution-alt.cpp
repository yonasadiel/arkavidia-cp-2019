// by : Dewita

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t,n,MD=1e9+7,ans;
	ll m[6][6] = {
		{4, 1, 3, 0, 3, 0},
		{0, 3, 0, 3, 0, 3},
		{3, 0, 4, 1, 3, 0},
		{0, 3, 0, 3, 0, 3},
		{3, 0, 3, 0, 4, 1},
		{0, 3, 0, 3, 0, 3},
	};
	ll m2[6][6], m3[6][6], m4[6][6];
	ll b[6] = {1, 2, 0, 3, 0, 3};
	cin >> t;
	while (t--) {
		cin >> n;
		--n;
		for (ll i=0;i<6;++i) {
			for (ll j=0;j<6;++j) {
				m2[i][j] = (i==j);
				m3[i][j] = m[i][j];
			}
		}
		while (n) {
			if (n&1LL) {
				for (ll i=0;i<6;++i) {
					for (ll j=0;j<6;++j) {
						m4[i][j] = 0;
						for (ll k=0;k<6;++k) {
							m4[i][j] += (m2[i][k]*m3[k][j])%MD;
							m4[i][j] %= MD;
						}
					}
				}
				for (ll i=0;i<6;++i) {
					for (ll j=0;j<6;++j) {
						m2[i][j] = m4[i][j];
					}
				}
			}
			for (ll i=0;i<6;++i) {
				for (ll j=0;j<6;++j) {
					m4[i][j] = 0;
					for (ll k=0;k<6;++k) {
						m4[i][j] += (m3[i][k]*m3[k][j])%MD;
						m4[i][j] %= MD;
					}
				}
			}
			for (ll i=0;i<6;++i) {
				for (ll j=0;j<6;++j) {
					m3[i][j] = m4[i][j];
				}
			}
			n >>= 1LL;
		}
		ans = 0;
		for (ll i=0;i<6;++i) {
			ans += (m2[0][i]*b[i])%MD;
			ans %= MD;
		}
		cout << ans << endl;
	}
	return 0;
}