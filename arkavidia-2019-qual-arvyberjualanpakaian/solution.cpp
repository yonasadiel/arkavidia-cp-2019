// by: Ahmad Zaky
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// naive sqrt(x)
vector<ll> primes(ll x) {
    vector<ll> res;
    if (x % 2 == 0) {
        res.push_back(2);
        while (x % 2 == 0) {
            x /= 2;
        }
    }
    ll p = 3;
    while (p * p <= x) {
        if (x % p) {
            p += 2;
            continue;
        }
        res.push_back(p);
        while (x % p == 0) {
            x /= p;
        }
    }
    if (x > 1) {
        res.push_back(x);
    }
    return res;
}

ll product(vector<ll> p) {
    ll res = 1;
    for (ll a : p) {
        res *= a;
    }
    return res;
}

vector<ll> ans, pp, c, px, pd, plimit;
vector<vector<ll> > pc;
ll d, x, sumans;

// find prime factorization of t
vector<ll> findpower(ll t) {
    vector<ll> res;
    for (int i = 0; i < pp.size(); ++i) {
        ll p = 0;
        while (t % pp[i] == 0) {
            t /= pp[i];
            p++;
        }
        res.push_back(p);
    }
    return res;
}

// compare product(pi^ai) and product(pi^bi)
bool vless(vector<ll> &a, vector<ll> &b) {
    assert(a.size() == pp.size());
    assert(b.size() == pp.size());
    double pa = 0., pb = 0.;
    for (int i = 0; i < pp.size(); ++i) {
        pa += double(a[i]) * log(pp[i]);
        pb += double(b[i]) * log(pp[i]);
    }
    return pa < pb;
}

bool vsame(vector<ll> &a, vector<ll> &b) {
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

vector<ll> vadd(vector<ll> &a, vector<ll> &b) {
    assert(a.size() == b.size());
    vector<ll> res = a;
    for (int i = 0; i < b.size(); ++i) {
        res[i] += b[i];
    }
    return res;
}

bool exceed(vector<ll> &a) {
    assert(a.size() == plimit.size());
    for (int i = 0; i < a.size(); ++i) {
        if (plimit[i] > 0 && a[i] > plimit[i]) {
            return true;
        }
    }
    return false;
}

void vprint(vector<ll> &a) {
    for (int i = 0; i < a.size(); ++i) {
        if (i) printf(" ");
        printf("%lld", a[i]);
    }
}
void vprintln(vector<ll> &a) {
    vprint(a); puts("");
}

ll searchspace = 0;

// a is the series of normalized discounts, i.e. X - d
// pos is where c[pos] = a.back()
// pa is the current power of primes
// pt is the target power of primes
// pp is the list of primes
void brute(vector<ll> a, int pos, vector<ll> pa, vector<ll> pt) {
    // printf("pos = %d, a = ", pos); vprint(a); printf(", pt = "); vprintln(pt);
    searchspace++;
    if (searchspace % 100000 == 0) {
        printf("searchspace = %lld, a.size() = %lu, a.front() = %lld, a.back() = %lld\n", searchspace, a.size(), a.front(), a.back());
    }
    if (exceed(pa)) {
        // puts("exceed: abort");
        return;
    }
    if (vsame(pa, pt)) {
        // a solution found!
        ll sum = 0;
        for (ll ai : a) {
            sum += x - ai;
        }
        if (sum > sumans) {
            sumans = sum;
            ans.clear();
            for (ll ai : a) {
                ans.push_back(x - ai);
            }
        }
        return;
    }

    // we refer to corollary 1 for the bound
    pt = vadd(pt, px);
    while (pos < c.size()) {
        vector<ll> pb = vadd(pa, pc[pos]);
        // printf("pb = "); vprintln(pb);
        if (!vless(pb, pt)) {
            a.push_back(c[pos]);
            brute(a, pos, pb, pt);
            a.pop_back();
        }
        pos++;
    }
}

pair<vector<ll>,ll> solve(ll _d, ll _x) {
    // global vars setup
    d = _x - _d;
    x = _x;
    ans.clear();
    c.clear();
    pc.clear();
    sumans = 0;
    searchspace = 0;

    // computation begins
    vector<ll> ppx = primes(x);
    pp = primes(d);
    pp.insert(pp.end(), ppx.begin(), ppx.end());
    sort(pp.begin(), pp.end());
    pp.resize(unique(pp.begin(), pp.end()) - pp.begin());

    px = findpower(x);
    pd = findpower(d);
    // for pruning
    // any pa shall not exceed plimit
    plimit = findpower(d);
    for (int i = 0; i < pp.size(); ++i) {
        if (px[i] != 0) {
            plimit[i] = 0;
        }
    }

    // first, we bruteforce all possible candidates
    // naive O(x sqrt(x))
    ll pt = product(pp);
    for (ll t = d + 1; t < x; ++t) {
        if (pt % product(primes(t)) == 0) {
            c.push_back(t);
            pc.push_back(findpower(t));
        }
    }

    // printf("c: "); vprintln(c);
    // printf("pp: "); vprintln(pp);
    // printf("px: "); vprintln(px);
    // printf("pd: "); vprintln(pd);
    // printf("plimit: "); vprintln(plimit);

    // we're bruteforcing on the powers
    for (int i = 0; i < c.size(); ++i) {
        vector<ll> a = {c[i]};
        brute(a, i, pc[i], pd);
    }

    return make_pair(ans, searchspace);
}

ll sum(vector<ll> &a) {
    ll res = 0;
    for (ll ai : a) {
        res += ai;
    }
    return res;
}

void longest(ll base) {
    int len = 0;
    vector<ll> ans;
    ll ansd = 0;
    for (ll d = 1; d < base; ++d) {
        printf("d = %lld\n", d);
        pair<vector<ll>,ll> _ans = solve(d, base);
        if (_ans.first.size() > len) {
            ansd = d;
            len = _ans.first.size();
            ans = _ans.first;
        }
        printf("d = %lld, length = %d\n", d, _ans.first.size());
        vprintln(_ans.first);
    }
    printf("longest for base = %lld\n", base);
    printf("d = %lld, length = %d, sum = %lld\n", ansd, len, sum(ans));
    vprintln(ans);
}

int solve() {
    scanf("%lld%lld", &d, &x);
    pair<vector<ll>,ll> _ans = solve(d, x);
    vector<ll> ans = _ans.first;
    ll searchspace = _ans.second;
    printf("%d ", ans.size());
    vprintln(ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}

/*
worst case?
input: 313 390
output:
n = 17, sum = 598
52 52 52 52 52 52 39 39 39 38 30 26 15 15 15 15 15

searchspace = 244192465
*/


/*

Problem: let X be the base (e.g. 100 for %) and K be the desired
discount. let d0, d1, ..., dn be the series of discounts, where
0 <= di < X. then proof that n is bounded, when we try to maximize
the value sum(di, i=0..n).

Conjecture: when comparing two sets of solutions (d0, ..., dn) and
(e0, ..., em), if sum(di) > sum(ei), then n > m.

Analysis:

lemma 1: we don't ever need 0/X discount.
proof: obvious
=qed=

let a0...an be the "normalized" discounts, i.e. X-di.
W.L.O.G., let a0 <= a1 <= ... <= an < X.
then, directly from the problem statement, the following is true:

  product(ai, i=0..n) = K X^N

corollary 1: for all t = 0..n-1, product(ai, i=0..t) > K X^t
proof: suppose the opposite. then

  product(ai, i=0..n) <= K X^t product(ai, i=t+1..n) < K X^N

a contradiction
=qed=

corollary 2: ai > K.
proof: obvious from corollary 1.
=qed=

// diminishing values of ai
suppose that for some t > 0, ai is fixed for i < t. then, by corollary
1, we have

  X > at > K X^t / product(ai, i=0..t-1)

call K X^t / product(ai, i=0..t-1) = Lt as the lower bound of at.

then we will have L(t+1) = Lt * X / at > Lt.
it means that the lower bound will be increased as t increasing.

then it is proven that n is bounded as well, because eventually we
would have Lt approaching X as t grows.

*/
