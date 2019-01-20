// by: Adyaksa Wisanggeni
#include  <bits/stdc++.h>
using namespace std;

#define DIMSIZE 10
#define MAXN 100000
int dim[15],arr[MAXN+5],a[15],b[15],kali[MAXN+5],pre[MAXN+5];

void solve(){
	int total = 1;
	int q;
	for(int i = 0; i < DIMSIZE; i++){
		scanf("%d", &dim[i]);
		total *= dim[i];
	}
	kali[DIMSIZE-1] = 1;
	for(int i = DIMSIZE-2; i >= 0; i--){
		kali[i] = kali[i+1]*dim[i+1];
	}
	for(int i = 0; i < total; i++){
		scanf("%d", &arr[i]);

		for(int j = 0; j < (1<<DIMSIZE); j++){
			int cur = i;
			int temp = j;
			int pos = 0;
			while(temp){
				if(temp%2)cur -= kali[pos];
				temp /= 2;
				pos++;
			}
			if(cur<0)continue;
			else pre[i] += arr[cur];
		}
	}
	scanf("%d", &q);
	for(int t = 0; t < q; t++){
		long long res = 0;
		for(int i = 0; i < DIMSIZE; i++){
			scanf("%d", &a[i]);
			a[i]--;
		}
		for(int i = 0; i < DIMSIZE; i++){
			scanf("%d", &b[i]);
			b[i]--;
		}
		for(int i = (1<<DIMSIZE); i >= 0; i--){
			int cur = i;
			int pos = 0;
			int val = 0;
			bool par = true;
			while(pos < DIMSIZE){
				if(cur%2){
					val += b[pos]*kali[pos];
					par = !par;
				} else {
					val += a[pos]*kali[pos];
				}
				pos++;
				cur /= 2;
			}
			if(par)res += pre[val];
			else res -= pre[val];
		}
		printf("%lld\n", res);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
}