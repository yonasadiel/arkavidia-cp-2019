#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAXN 200000

int t,n,cur,arr[MAXN+5],val[2][MAXN+5];
long long res;

long long pangkat(long long a, long long b){
	if(b==0)return 1;
	if(b==1)return a;
	long long temp = pangkat(a,b/2)%INF;
	return (((temp*temp)%INF)*pangkat(a,b%2))%INF;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < 2*n; i++){
			scanf("%d", &arr[i]);
			val[0][i] = false;
			val[1][i] = false;
		}
		cur = 0;
		res = 0;
		for(int i = 2*n-1; i >= 0; i--){
			if(val[cur][arr[i]]){
				res += pangkat(2,i+1);
				cur = !cur;
			}
			val[cur][arr[i]] = true;
		}
		printf("%lld\n", res);
	}
}