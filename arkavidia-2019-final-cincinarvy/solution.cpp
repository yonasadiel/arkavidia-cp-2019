//By: Adyaksa Wisanggeni
#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define EPS 0.000001
int t,d,x,y,vk,va;

double calc(double a){
	double at = (((double)d+y)/y)*sqrt(a*a+y*y)/va;
<<<<<<< HEAD
	double kt = ((((double)d+y)/y)*a+x)/vk;
=======
	double kt = (((double)d+y)/y*a+x)/vk;
>>>>>>> d09772c2e1aa3e3b5cd3f6bf033fcbaaf5480073
	return kt-at;
}

double cari(double a, double b){
	if(fabs(b-a) <= EPS)return calc(a);

	double mid = (b-a)/3;
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