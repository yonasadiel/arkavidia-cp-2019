// by: Jehian Norman
#include <bits/stdc++.h>
using namespace std;

// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;

// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")

// MACROS FOR ATTRIBUTE
#define fi first
#define se second

// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) fill_n(x, sizeof(x)/sizeof(x[0]), y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))

const ll MD = 1e9+7;

inline ll mul(ll a, ll b) {
	return (a * b) % MD;
}

inline ll add(ll a, ll b) {
	return (a + b) % MD;
}

inline ll sub(ll a, ll b) {
	return (a - b + MD) % MD;
}

inline ll powMod(ll a, ll p) {
	ll res = 1;
	for (; p; p >>= 1, a = SQR(a)%MD) {
		if (p & 1) res *= a, res %= MD;
	}
	return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long N;
        scanf("%lld", &N);
        // Exception Case
        if (N == 1) puts("1");
        // Math Case
        else printf("%lld\n", sub(mul(3,powMod(10,N-1)),mul(powMod(9,N-2),24)));
    }
    return 0;
}