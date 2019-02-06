//by: Dicky Novanto

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int maxn = 1e4 + 4;

int indeg[maxn], jalurUp[maxn], jalurDown[maxn], areaUp[maxn], areaDown[maxn];
int dp[maxn];
vector<vi> AdjList, graf, back;
int daerah;

void reset() {
	memset(indeg, 0, sizeof indeg);
	memset(jalurUp, -1, sizeof jalurUp);
	memset(jalurDown, -1, sizeof jalurDown);
	memset(areaUp, -1, sizeof areaUp);
	memset(areaDown, -1, sizeof areaDown);
	memset(dp, -1, sizeof dp);
	AdjList.assign(maxn, vi());
	graf.assign(maxn*10, vi());
	back.assign(maxn, vi());

	daerah = 0;
}

void read(int n){
	for(int i=0;i<n;i++){
		int jalur1, jalur2, jalur3;
		char tipe;
		scanf("\n%c %d %d %d",&tipe, &jalur1, &jalur2, &jalur3);
		if(tipe == 'A'){
			AdjList[jalur1].push_back(jalur2);
			AdjList[jalur1].push_back(jalur3);
			back[jalur2].push_back(jalur1);
			back[jalur3].push_back(jalur1);
			indeg[jalur2]++;
			indeg[jalur3]++;
		}else{
			AdjList[jalur1].push_back(jalur3);
			AdjList[jalur2].push_back(jalur3);
			back[jalur3].push_back(jalur1);
			back[jalur3].push_back(jalur2);
			indeg[jalur3]+=2;
		}
	}
}

void constructJalurAndAreaUpDownAwal(const vi& listAwal) {
	int ukuran = listAwal.size();
	if(ukuran == 1){
		int jalur = listAwal[0];
		jalurUp[jalur] = -1;
		jalurDown[jalur] = -1;
		areaUp[jalur] = daerah++;
		areaDown[jalur] = daerah++;
	}else{
		for(int i=0;i<ukuran;i++){
			int jalur = listAwal[i];
			if(i == 0){
				jalurUp[jalur] = -1;
				jalurDown[jalur] = listAwal[i+1];
				areaUp[jalur] = daerah++;
				areaDown[jalur] = daerah++;
			}else if(i < ukuran - 1){
				jalurUp[jalur] = listAwal[i-1];
				jalurDown[jalur] = listAwal[i+1];
				areaUp[jalur] = areaDown[listAwal[i-1]];
				areaDown[jalur] = daerah++;
			}else{
				jalurUp[jalur] = listAwal[i-1];
				jalurDown[jalur] = -1;
				areaUp[jalur] = areaDown[listAwal[i-1]];
				areaDown[jalur] = daerah++;
			}
		}
	}
}

void constructCabangJalur(int v, int front, int i) {
	if(i == 0){
		jalurUp[v] = jalurUp[front];
		jalurDown[v] = AdjList[front][i+1];
		areaUp[v] = areaUp[front];
		areaDown[v] = daerah++;
	}else{
		jalurUp[v] = AdjList[front][i-1];
		jalurDown[v] = jalurDown[front];
		areaUp[v] = areaDown[jalurUp[v]];
		areaDown[v] = areaDown[front];
	}
}

void constructGabungJalur(int v, int front) {
	jalurUp[v] = jalurUp[front];
	areaUp[v] = areaDown[jalurUp[v]];
	int elemenBawah = back[v][1];
	jalurDown[v] = jalurDown[elemenBawah];
	areaDown[v] = areaDown[elemenBawah];
}

void constructGraph(int n, int m) {
	read(n);

	queue<int> q;
	vi listAwal;
	for(int i=1;i<=m;i++){
		if(indeg[i] == 0){
			listAwal.push_back(i);
			q.push(i);
		}
	}

	//generate daerah awal dari jalur-jalur awal
	constructJalurAndAreaUpDownAwal(listAwal);

	while(!q.empty()) {
		int front = q.front(); q.pop();
		int ukuran = AdjList[front].size();
		for(int i=0;i<ukuran;i++){
			int v = AdjList[front][i];
			indeg[v]--;
			if(indeg[v] == 0){q.push(v);}
			if(ukuran == 2){
				constructCabangJalur(v, front, i);
			}else if(ukuran == 1){
				constructGabungJalur(v, front);
 			}
		}
	}

	for(int i=1;i<=m;i++){ //construct graf final
		graf[areaUp[i]].push_back(areaDown[i]);
	}
}

int solve(int node) {
	if(dp[node] != -1){return dp[node];}
	int ans = 0;
	int ukuran = graf[node].size();
	for(int i=0;i<ukuran;i++){
		int v = graf[node][i];
		ans = max(ans, solve(v));
	}

	return dp[node] = ans+1;
}

void debug(int m){
	int i,j;
	for(i=0;i<daerah;i++){
		printf("daerah: %d->",i);
		for(j=0;j<graf[i].size();j++){
			int v = graf[i][j];
			printf(" %d",v);
		}
		printf("\n");
	}
	for(i=1;i<=m;i++)
		printf("jalurUp[%d]: %d\n",i,jalurUp[i]);
	for(i=1;i<=m;i++)
		printf("jalurDown[%d]: %d\n",i,jalurDown[i]);
	for(i=1;i<=m;i++)
		printf("areaUp[%d]: %d\n",i,areaUp[i]);
	for(i=1;i<=m;i++)
		printf("areaDown[%d]: %d\n",i,areaDown[i]);
}

int main(){
	int tc,i,j;
	int n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		
		reset();
		constructGraph(n,m);
		
		printf("%d\n",solve(0)-1); //berkurang 1 karena jumlah edge dalam path = jumlah node - 1
	}
	return 0;
};