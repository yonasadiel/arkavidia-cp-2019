//By: Adyaksa Wisanggeni
#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define EPS 0.000000001
int t,d,x,y,vk,va;

long double calc(long double a){
	long double at = (((long double)d+y)/y)*sqrt(a*a+y*y)/va;
	long double kt = (((long double)d+y)/y*a+x)/vk;
	return kt-at;
}

long double cari(long double a, long double b){
	if(fabs(b-a) <= EPS)return calc(a);

	long double mid = (b-a)/3;
	if(calc(a+mid) > calc(b-mid)){
		return cari(a,b-mid);
	} else return cari(a+mid,b);
}

void solve(){
	scanf("%d %d %d %d %d", &d, &x, &y, &vk, &va);
	if(cari(0,INF)>=0){
		printf("YA\n");
	} else printf("TIDAK\n");
}

int main(){
	scanf("%d", &t);
	while(t--){
		solve();
	}
}