// By: Adyaksa Wisanggeni
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAXN 100000

int n,dp[MAXN+5][2], ps[MAXN+5][2],arr[MAXN+5];

int rekur(int now, bool parity);

int calc(int now, bool parity){
	if(now==n)return 0;
	int &ret = ps[now][parity];
	if(ret != -1)return ret;
	ret = 0;
	ret += calc(now+1,parity)%INF;
	if(parity == arr[now]%2)ret += rekur(now,parity);
	ret %= INF;
	return ret;
}

int rekur(int now, bool parity){
	int &ret = dp[now][parity];
	if(ret != -1)return ret;
	ret = 1;
	ret += calc(now+1,!parity);
	ret %= INF;
	return ret;
}

void solve(){
	int res = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		dp[i][0] = dp[i][1] = ps[i][0] = ps[i][1] = -1;
	}
	for(int i = n-1; i >= 0; i--){
		calc(i,0);
		calc(i,1);
	}
	for(int i = 0; i < n; i++){
		if(arr[i]%2){
			res += rekur(i,1);
			res %= INF;
		}
	}
	printf("%d\n", res);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
}