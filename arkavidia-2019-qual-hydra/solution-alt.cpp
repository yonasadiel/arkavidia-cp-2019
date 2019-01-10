// by: Dewita

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t,n,x,a[100010];
vector<ll> pr;
ll v[18000010]={};
ll cnt,ans,tmp;

ll get(ll val){
    ll cur = 0;
    for(ll i=0;i<n;++i){
        ll tmp = a[i];
        while (tmp) {
            tmp /= val;
            cur += tmp;
        }
    }
    return cur;
}

int main() {
	scanf("%lld", &t);
	for (ll i=2;i<=18000000;++i) {
		if (v[i]) continue;
		pr.push_back(i);
		x = pr.size();
		v[i] = x;
		for (ll j=i*i;j<=18000000;j+=i) {
			v[j] = x;
		}
	}
	while (t--) {
		scanf("%lld %lld", &x, &n);
		for (ll i=0;i<n;++i) {
			scanf("%lld", a+i);
		}
		ans = -1;
		for (auto e:pr) {
			if (x%e==0) {
				cnt = 0;
				tmp = get(e);
				while (x%e==0) {
					x /= e;
					++cnt;
				}
				tmp /= cnt;
				if (ans<0) ans = tmp;
				else ans = min(ans, tmp);
			}
		}
		if (x>1) {
			tmp = get(x);
			if (ans<0) ans = tmp;
			else ans = min(ans, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}