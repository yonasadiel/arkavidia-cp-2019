// by : Irfan Sofyana
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

const int MAXN = 100005;
vector<pair<int,int> > arr[MAXN];
int N, T;
bool visited[MAXN];
long long longest;
long long sumE, ans;

//cari(node) ngehasilin pair<x, y>
//x itu longest path yang ga harus sampe leave , y harus
pair<long long,long long> cari(int node){
    int cnt = 0;
    visited[node] = true;
    //cek leave
    for (int i = 0 ;i < (int)arr[node].size(); i++){
        if (!visited[arr[node][i].fi]) 
            cnt++;
    }
    if (cnt == 0) return {0, 0};
    else {
        pair<long long, long long> jaw = {0, -1e18};
        for (int i = 0; i < (int)arr[node].size(); i++){
            int nxt = arr[node][i].fi;
            long long jarak = 1LL*arr[node][i].se;
            if (!visited[nxt]){
                pair<long long,long long> anak = cari(nxt);
                //cek semua kemungkinan longest path
                //dapetin maksimal
                ans = max(ans, jarak + anak.se);
                ans = max(ans, jaw.se + jarak + anak.fi);
                ans = max(ans, jaw.se + jarak + anak.se);
                ans = max(ans, jaw.fi + jarak + anak.se);
                jaw.fi = max(jaw.fi, jarak + anak.fi);
                jaw.se = max(jaw.se, jarak + anak.se);
            }
        }
        //update ans dengan longest path dari node ke suatu leave
        ans = max(ans, jaw.se);
        return jaw;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        sumE = 0;
        ans = -1e18;
        for (int i = 0; i < N-1; i++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[a].pb({b, c});
            arr[b].pb({a, c});
            sumE += 1LL*c;
        }
        if (N == 2) {
            cout << sumE << '\n';
        }else{
            memset(visited, false, sizeof visited);
            pair<long long, long long> ret = cari(1);
            //bisa jadiin 1 sebagai leave
            if ((int)arr[1].size() == 1) {
                ans = max(ans, ret.fi);
            }
            cout << 2*sumE - ans << '\n';
        }
        for (int i = 1; i <= N; i++)
            arr[i].clear();
    } 
}