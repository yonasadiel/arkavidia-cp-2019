// by: Dicky Novanto

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001, maxw = 1001;

ll dp[maxn][maxw], harga[maxn];
int n;
int banyak[maxn];

ll solve(int idx, int banyakBeli) {
	if(idx == n){
		if(banyakBeli == 0){return 0;}
		else{return inf;}
	}
	if(dp[idx][banyakBeli] != -1){return dp[idx][banyakBeli];}
	if(banyakBeli < banyak[idx]){return solve(idx+1, banyakBeli);}
	ll ans1 = harga[idx] + solve(idx, banyakBeli-banyak[idx]);
	ll ans2 = harga[idx] + solve(idx+1, banyakBeli-banyak[idx]);
	ll ans3 = solve(idx+1, banyakBeli);
	return dp[idx][banyakBeli] = min(min(ans1,ans2),ans3);	
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);

	while(tc--){
		int banyakBeli;
		int q;
		scanf("%d %d",&n,&q);
		for(i=0;i<n;i++){
			scanf("%d %lld",&banyak[i],&harga[i]);
		}

		memset(dp, -1, sizeof dp);
		while(q--){
			scanf("%d",&banyakBeli);
			ll ans = solve(0,banyakBeli);
			printf("%lld\n",ans);	
		}	
	}
	
	return 0;
};