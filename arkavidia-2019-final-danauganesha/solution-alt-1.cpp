// By: Adyaksa Wisanggeni
// solve() : Deret elegan(Pake array)
// solve2() : Danau ganesha variant 1 (N aja), pake fibonacci(n)-1
// solve3() : Danau ganesha variant 2 (N,K), naive solution O(NK)

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAXN 1000
#define mat_sz 2
#define INF 1000000007

int n,dp[MAXN+5][2], ps[MAXN+5][2],arr[MAXN+5];
int dp2[MAXN+5][MAXN+5];

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

void multiply(long long a[mat_sz][mat_sz], long long b[mat_sz][mat_sz])
{
    long long mul[mat_sz][mat_sz];
    for (int i = 0; i < mat_sz; i++)
    {
        for (int j = 0; j < mat_sz; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < mat_sz; k++)
                mul[i][j] += a[i][k]*b[k][j];
                mul[i][j] %= INF;
        }
    }

    for (int i=0; i<mat_sz; i++)
        for (int j=0; j<mat_sz; j++)
            a[i][j] = mul[i][j];
}

long long power(long long F[mat_sz][mat_sz], int n)
{
    long long M[mat_sz][mat_sz] = {{1,1},{1,0}};

    if (n==1) return F[1][0];
    if(n==0)return 0;

    power(F, n/2);

    multiply(F, F);

    if (n%2 != 0) multiply(F, M);

    return F[1][0] ;
}

long long findNthTerm(long long n)
{
    long long F[mat_sz][mat_sz] = {{1,1},{1,0}};

    return power(F, n);
}

void solve2(){
	scanf("%d", &n);
	printf("%d\n", findNthTerm(n)-1);
}

int rekur2(int now, int rem){
	if(rem == 0)return 1;
	int &ret = dp2[now][rem];
	if(ret != -1)return ret;
	ret = 0;
	for(int i = now+1; i <= n; i+= 2){
		ret += rekur2(i,rem-1);
	}
	return ret;
}

void solve3(){
	int k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			dp2[i][j] = -1;
		}
	}
	printf("%d\n", rekur2(0,k));
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve2();
	}
}