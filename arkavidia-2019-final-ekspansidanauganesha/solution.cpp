// By: Adyaksa Wisanggeni
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAXN 100000
#define mat_sz 2

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

void solve(){
	int n;
	scanf("%d", &n);
	printf("%d\n", findNthTerm(n)-1);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
}