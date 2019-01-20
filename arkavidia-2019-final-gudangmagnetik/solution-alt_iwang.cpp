#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

//x dan y genap
int dx1[4] = {0,3,0,-3};
int dy1[4] = {3,0,-3,0};

//x ganjil, y genap
int dx2[4] = {0,3,0,-3};
int dy2[4] = {2,0,-2,0};

//x genap, y ganjil
int dx3[4] = {0,2,0,-2};
int dy3[4] = {3,0,-3,0};

char arr[205][205];
int r,c;


bool valid(int x, int y){
	if(x<0 or x >= 2*r-1 or y<0 or y>=2*c-1)return false;
	if(x%2){
		if(arr[x-1][y] == '#' || arr[x+1][y] == '#')return false;
	} else if(y%2){
		if(arr[x][y-1] == '#' || arr[x][y+1] == '#')return false;
	} else {
		if(arr[x][y] == '#')return false;
	}
	return true;
}

void solve(){
	queue<pair<pair<int,int>,int> > q;
	bool visited[2*MAXN+5][2*MAXN+5];
	bool can = false;
	vector<pair<int,int> > init;

	scanf("%d %d", &r, &c);
	memset(visited,0,sizeof(visited));
	for(int i = 0; i < r*2-1; i++){
		if(i%2){
			for(int j = 0; j < c*2-1; j++){
				arr[i][j] = '.';
			}	
			continue;
		}
		getchar();
		for(int j = 0; j < c*2-1; j++){
			if(j%2){
				arr[i][j] = '.';
				continue;
			}
			scanf("%c", &arr[i][j]);
			if(arr[i][j] == 'B'){
				arr[i][j] = '.';
				init.push_back(make_pair(i,j));
			}
		}
	}
	if(init.size() == 1){
		q.push(make_pair(init[0],0));
	} else {
		q.push(make_pair(make_pair((init[0].first+init[1].first)/2,(init[0].second+init[1].second)/2),0));
	}
	while(!q.empty()){
		pair<pair<int,int>,int> top = q.front();
		q.pop();
		int curx = top.first.first;
		int cury = top.first.second;
		int curstep = top.second;
		if(visited[curx][cury])continue;
		visited[curx][cury] = true;
		if(arr[curx][cury] == 'F'){
			printf("%d\n", curstep);
			can = true;
			break;
		}
		for(int i = 0; i < 4; i++){
			int tgx = curx;
			int tgy = cury;
			if(cury%2){
				tgx += dx3[i];
				tgy += dy3[i];
			} else if(curx%2){
				tgx += dx2[i];
				tgy += dy2[i];
			} else {
				tgx += dx1[i];
				tgy += dy1[i];
			}
			if(valid(tgx,tgy)){
				q.push(make_pair(make_pair(tgx,tgy),curstep+1));
			}
		}
	}
	if(!can)printf("-1\n");
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}	
}