/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std

Jehian Norman Saviero;

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

// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scf(x) scanf("%f", &x)
#define scd(x) scanf("%lf", &x)
#define scld(x) scanf("%Lf", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

const ll MD = 1e9+7;

ll powMod(ll a, ll p, ll md = MD) {
	ll res = 1;
	for (; p; p >>= 1, a = SQR(a)%md) {
		if (p & 1) res *= a, res %= md;
	}
	return res;
}

inline ll MUL(ll A, ll B) {
	return (A * B) % MD;
}

inline ll ADD(ll A, ll B) {
	return (A + B) % MD;
}

inline ll invMod(ll A) {
	return powMod(A, MD-2);
}

inline ll DIV(ll A, ll B) {
	return MUL(A, powMod(B,MD-2));
}

inline ll SUB(ll A, ll B) {
	return ADD(ADD(A,-B),MD);
}

struct query {
	char type;
	ll L, R;
	ll idx, val;
};

vector<query> queries;
set<ll> ids;
map<ll, int> cmprs;
vector<pll> st, arr;
vll val;
int num = 0;

ll A, B, Q;
ll getFirstNDigit(ll n) {
	ll all, frac;
	all = A * powMod(10, n) % MD;
	all *= invMod(B);
	all %= MD;
	ll k = A * powMod(10, n, B) % B;
	frac = k * invMod(B) % MD;
	ll res = ((all - frac) + MD) % MD;
	return res;
}

ll getDigitRange(ll L, ll R) {
	return SUB(getFirstNDigit(R), MUL(getFirstNDigit(L-1), powMod(10, R-L+1)));
}

pll OPR(pll A, pll B) {
	return {ADD(MUL(A.fi, powMod(10, B.se)), B.fi), A.se+B.se};
}

void build() {
	for (int i = 0; i < num-1; ++i) {
		arr[i] = {getDigitRange(val[i], val[i+1]-1), val[i+1]-val[i]};
	}
	arr[num-1] = {getDigitRange(val[num-1], val[num-1]), 1LL};
	for (int i = 0; i < num; ++i) {
		st[i + num] = arr[i];
	}
	for (int i = num-1; i >= 0; --i) {
		st[i] = OPR(st[i << 1], st[i << 1 | 1]);
	}
}

void update(ll idx, int val) {
	int c_idx = cmprs[idx];
	arr[c_idx].fi = val;
	assert( arr[c_idx].se == 1LL );
	st[c_idx + num] = {arr[c_idx].fi, arr[c_idx].se};
	for (int i = c_idx + num; i > 0; i >>= 1) {
		if (i < (i ^ 1)) {
			st[i >> 1] = OPR(st[i], st[i ^ 1]);
		} else {
			st[i >> 1] = OPR(st[i ^ 1], st[i]);
		}
	}
}

ll query(ll L, ll R) {
	int l_idx = cmprs[L];
	int r_idx = cmprs[R+1];
	pll resL = {0LL, 0LL}, resR = {0LL, 0LL};
	for (l_idx += num, r_idx += num; l_idx < r_idx; l_idx >>= 1, r_idx >>= 1) {
		if (l_idx & 1) resL = OPR(resL, st[l_idx++]);
		if (r_idx & 1) resR = OPR(st[--r_idx], resR);
	}
	return OPR(resL, resR).fi;
}

void resetAll() {
	ids.clear();
	cmprs.clear();
	num = 0;
}

int main(int argc, char* argv[]) {
	bool hard = 0;
	if (argc == 2) {
		if (strcmp(argv[1], "hard") == 0) {
			hard = 1;
		}
	}
	int T;
	sci(T);
	// int tc = 0;
	while (T--) {
		resetAll();
		ll N;
		scll(N);
		scanf("%lld %lld %lld", &A, &B, &Q);
		queries.resize(Q);
		char type;
		ids.insert(1);
		for (int i = 0; i < Q; ++i) {
			if (hard) {
				scanf(" %c", &queries[i].type);
			} else {
				queries[i].type = 'S';
			}
			if (queries[i].type == 'S') {
				scanf("%lld %lld", &queries[i].L, &queries[i].R);
				ids.insert(queries[i].L);
				ids.insert(queries[i].R);
				ids.insert(queries[i].R+1);
			} else {
				scanf("%lld %lld", &queries[i].idx, &queries[i].val);
				ids.insert(queries[i].idx);
				ids.insert(queries[i].idx+1);
			}
		}
		ids.insert(N);
		for (ll it : ids) {
			cmprs[it] = num++;
		}
		val.resize(num);
		for (pair<ll,int> it : cmprs) {
			val[it.se] = it.fi;
		}
		st.resize(num + num);
		arr.resize(num);
		build();
		// printf("Case #%d:\n", ++tc);
		for (int i = 0; i < queries.size(); ++i) {
			if (queries[i].type == 'U') {
				update(queries[i].idx, queries[i].val);
			} else {
				printf("%lld\n", query(queries[i].L, queries[i].R));
			}
		}
	}
	return 0;
}