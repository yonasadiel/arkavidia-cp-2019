//by: Dicky Novanto

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 210;

set<int> s, temp;
set<int>::iterator it;

int n,x,p;

ll getWaktu(int awal, int akhir) {
	ll jarak = abs(awal - akhir);
	if(awal > akhir)
		return x - jarak;
	else
		return jarak;
}

set<int>::iterator getNext(int pos) {
	set<int>::iterator it2;
	pos = (pos + p) % x;
	it2 = s.lower_bound(pos);
	if(it2 == s.end()) {
		it2--;
	}
	return it2;
}

ll simulate(int awal) {
	int cur = awal;
	ll totWaktu = 0;

	while(1){
		s.erase(cur);

		if(s.empty()){
			totWaktu += p;
			break;
		}

		int nextPos = *(getNext(cur));

		totWaktu += p;
		totWaktu += getWaktu(cur, nextPos);
		cur = nextPos;
	}

	return totWaktu;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		
		scanf("%d %d %d",&n,&x,&p);
		int a[maxn];

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}

		temp = s;
		ll waktuMin = (ll)1e18;
		int idxMin;

		for(i=0;i<n;i++){
			s = temp; // reset
			ll waktu = simulate(a[i]);
			if(waktu < waktuMin){
				waktuMin = waktu;
				idxMin = a[i];
			}
		}

		printf("%d %lld\n",idxMin, waktuMin);
	}
	return 0;
};