// by : Irfan Sofyana
#include <bits/stdc++.h>

typedef long long LL;

const LL MOD = 1e9 + 7;

using namespace std;

LL N, A, B, L, R;
int T, Q;

LL power(LL a,LL b,LL mod){
    LL ret = 1;
    while (b > 0){
        if (b%2 == 1) ret = ((ret%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        b /= 2;
    }
    return ret;
}

LL opmod(LL a, LL b){
    if (a >= 0) return a%b;
    else {
        LL tmp = abs(a);
        tmp /= b;
        return ((tmp + 1)*b + a)%b;
    }
}

LL invm(LL x){
    return power(x, MOD-2, MOD);
}

LL getNth(LL N, LL A, LL B){
    LL tmp = (power(10, N, MOD) * (A % MOD))%MOD;
    tmp = (tmp * invm(B))%MOD;

    LL ex = (power(10, N, B) * (A % B))%B;
    ex = (ex * invm(B))%MOD;
    return opmod(tmp-ex, MOD);
}

LL solve(LL L, LL R){
    LL kanan = getNth(R, A, B);
    LL kiri = getNth(L-1, A, B);
    kiri = (kiri * power(10, R-L+1, MOD))%MOD;
    return opmod(kanan-kiri, MOD);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> A >> B;
       // cout << getNth(N, A, B) << " xxx\n";
        cin >> Q;
        while (Q--){
            cin >> L >> R;
            //cout << getNth(L-1, A, B) << " kiri\n";
            //cout << getNth(R, A, B) << " kanan\n"; 
            cout << solve(L, R) << '\n';
        }
    }
   // cout << power(2, 10, 5) << '\n';
    return 0;    
}
