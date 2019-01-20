// by : Irfan Sofyana
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long LL;

int T;
LL X, K, sum;
vector<LL> PF, PK, PX, kand, batas, ret;
vector<vector<LL> > pkand;


vector<LL> prime_factors(LL x){
    LL i = 2;
    vector<LL> pf;
    while (x > 1){
        if (i * i > x) break;
        if (x%i == 0) {
            pf.pb(i);
            while (x%i == 0){
                x /= i;
            }
            i++;
        }
        else i++;
    }
    if (x > 1) {
        pf.pb(x);
    }
    return pf;
}

vector<LL> find_power(LL x){
    vector<LL> fp;
    for (int i = 0; i < (int)PF.size(); i++){
        LL tot = 0;
        while (x % PF[i] == 0){
            tot++;
            x /= PF[i];
        }
        fp.pb(tot);
    }
    return fp;
}

vector<LL> gabung_vector(vector<LL> a, vector<LL> b){
    vector<LL> ret = a;
    for (int i = 0; i < (int)b.size(); i++){
        ret.pb(b[i]);
    }
    sort(all(ret));
    ret.resize(unique(all(ret)) - ret.begin());
    return ret;
}

LL kali(vector<LL> P){
    LL res = 1;
    for (int i = 0; i < (int)P.size(); i++)
        res *= P[i];
    return res;
}

bool sama(vector<LL> &a, vector<LL> &b){
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool impossible(vector<LL> &p){
    assert(p.size() == batas.size());
    for (int i = 0; i < (int)p.size(); i++){
        if (p[i] > batas[i] && batas[i] > 0)
            return true;
    }
    return false;
}

void update(LL &jumlah, LL tjum,vector<LL> &ret, vector<LL> a){
    if (tjum > jumlah){
        jumlah = tjum;
        ret.clear();
        for (int i = 0; i < (int)a.size(); i++)
            ret.pb(K - a[i]);
    }
}

vector<LL> jumv(vector<LL> &a, vector<LL> &b){
    assert(a.size() == b.size());
    vector<LL> retv;
    for (int i = 0; i < (int)a.size(); i++){
        retv.pb(a[i] + b[i]);
    }
    return retv;
}

bool kecil(vector<LL> &a, vector<LL> &b) {
    assert(a.size() == PF.size());
    assert(b.size() == PF.size());
    double sa = 0.0;
    double sb = 0.0;
    for (int i = 0; i < PF.size(); ++i) {
        sa += double(a[i]) * log(PF[i]);
        sb += double(b[i]) * log(PF[i]);
    }
    return sa < sb;
}


void cari(int pos, vector<LL> a, vector<LL> pcurr, vector<LL> pgoal){
    if (impossible(pcurr))
        return;
    if (sama(pcurr, pgoal)){
        LL tsum = 0;
        for (int i = 0; i < (int)a.size(); i++){
            tsum += K - a[i];
        }
        if (tsum > sum){
            sum = tsum;
            ret.clear();
            for (int i = 0; i < (int)a.size(); i++)
                ret.pb(K - a[i]);
        }
        return;
    }
    //coba dikali dengan k
    pgoal = jumv(pgoal, PK);
    for (int i = pos; i < (int)kand.size(); i++){
        vector<LL> ptmp = jumv(pcurr, pkand[i]);
        //coba kand[i] menjadi kandidat jawaban!
        if (!kecil(ptmp, pgoal)){
            a.pb(kand[i]);
            cari(i, a, ptmp, pgoal);
            a.pop_back();
        }
    }
}

vector<LL> Solve(LL X, LL K){
    kand.clear();
    pkand.clear();
    ret.clear();
    sum = 0;
    LL newx = K-X;

    PF = gabung_vector(prime_factors(newx),prime_factors(K));
    PK = find_power(K);
    PX = find_power(newx);
    batas = find_power(newx);
    //k^(n-1).(k-x) 
    //setiap faktor prima dari (k-x) yang bukan faktor k harus jadi batas
    for (int i = 0; i < (int)batas.size(); i++){
        if (PK[i] > 0) {
            batas[i] = 0;
        }
    }
    //cek semua kemungkinan ai
    for (LL i = newx+1; i < K; i++){
        LL tkali = kali(PF);
        //semua faktor prima i subset dari k^(n-1).(k-x)
        if (tkali % kali(prime_factors(i)) == 0 ){
            kand.pb(i);
            pkand.pb(find_power(i));
        }
    }
    for (int i = 0; i < (int)kand.size(); i++){
        vector<LL> res;
        res.push_back(kand[i]);
        cari(i, res, pkand[i], PX);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        int N;
        cin >> N >> K;
        while (N--) {
            cin >> X;
            vector<LL> ans = Solve(X, K);
            if ((int)ans.size() == 0) ans.pb(X);
            cout << (int)ans.size();
            cout << " ";
            for (int i = 0; i < (int)ans.size(); i++){
                cout << ans[i];
                cout << (i == (int)ans.size()-1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
