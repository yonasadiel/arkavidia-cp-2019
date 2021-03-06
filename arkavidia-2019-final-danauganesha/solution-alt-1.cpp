// By: Adyaksa Wisanggeni

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAXN 1000
#define MAXNN 200000

int n,dp[MAXN+5][MAXN+5];
long long facto[MAXNN+5];

//Buat ngetes
int rekur(int now, int rem){
	if(rem == 0)return 1;
	int &ret = dp[now][rem];
	if(ret != -1)return ret;
	ret = 0;
	for(int i = now+1; i <= n; i+= 2){
		ret += rekur(i,rem-1);
		ret %= INF;
	}
	return ret;
}

long long pangkat(long long a, long long b){
	if(b==0)return 1;
	if(b==1)return a;
	long long temp = pangkat(a,b/2);
	return (((temp*temp)%INF)*pangkat(a,b%2))%INF;
}

long long comb(int n, int k){
	return ((facto[n]*pangkat(facto[n-k],INF-2)%INF)*pangkat(facto[k],INF-2))%INF;
}

void solve(){
	int k;
	scanf("%d %d", &n, &k);
	printf("%lld\n", comb((n+k)/2,k));
}

int main(){
	int t;
	facto[0] = 1;
	for(int i = 1; i <= MAXN; i++){
		facto[i] = facto[i-1]*i;
		facto[i] %= INF;
	}
	scanf("%d", &t);
	while(t--){
		solve();
	}
}