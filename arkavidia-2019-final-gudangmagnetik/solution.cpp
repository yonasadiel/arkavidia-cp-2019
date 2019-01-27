// by: Yonas Adiel
#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int r, c;
char grid[205][205];
int dist[205][205];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
pii pred[205][205];

bool is_ground(char cc) {
    return cc == '.' || cc == 'B' || cc == 'F';
}

bool is_valid(int rr, int cc) {
    return (2 <= rr && rr <= 2*r) && (2 <= cc && cc <= 2*c);
}

void solve() {
    int sr, sc, fr, fc;
    scanf("%d%d\n", &r, &c);
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            scanf("%c", &grid[i*2][j*2]);
            if (grid[i*2][j*2] == 'B') { sr = 2*i; sc = 2*j; }
            if (grid[i*2][j*2] == 'F') { fr = 2*i; fc = 2*j; }
        }
        scanf("\n");
    }
    for (int i=1; i<=2*r+1; i++) {
        grid[i][1] = grid[i][2*c+1] = '#';
    }
    for (int j=1; j<=2*c+1; j++) {
        grid[1][j] = grid[2*r+1][j] = '#';
    }
    for (int i=2; i<=2*r; i++) {
        for (int j=2; j<=2*c; j++) {
            if ((i % 2 != 0) && (j % 2 == 0)) {
                grid[i][j] = (is_ground(grid[i-1][j]) && is_ground(grid[i+1][j]) ? '.' : '#');
                if (grid[i-1][j] == 'B' && grid[i+1][j] == 'B') {
                    grid[i-1][j] = grid[i+1][j] = '.';
                    sr = i; sc = j;
                    grid[i][j] = 'B';
                }
            } else if ((i % 2 == 0) && (j % 2 != 0)) {
                grid[i][j] = (is_ground(grid[i][j-1]) && is_ground(grid[i][j+1]) ? '.' : '#');
                if (grid[i][j-1] == 'B' && grid[i][j+1] == 'B') {
                    grid[i][j-1] = grid[i][j+1] = '.';
                    sr = i; sc = j;
                    grid[i][j] = 'B';
                }
            } else if ((i % 2 != 0) && (j % 2 != 0)) {
                grid[i][j] = '#';
            }
        }
    }
    // printf("%d %d\n", r, c);
    // for (int i=1; i<=2*r+1; i++) {
    //     printf("%02d ", i);
    //     for (int j=1; j<=2*c+1; j++) {
    //         printf("%c", grid[i][j]);
    //     }
    //     printf("\n");
    // }

    queue<pii> q;
    memset(dist, -1, sizeof dist);
    memset(pred, 0, sizeof pred);

    q.push(mp(sr, sc));
    dist[sr][sc] = 0;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (int i=0; i<4; i++) {
            int nr = cur.fi + dr[i] * (cur.se % 2 == 0 ? 3 : 2);
            int nc = cur.se + dc[i] * (cur.fi % 2 == 0 ? 3 : 2);
            if (is_valid(nr, nc) && is_ground(grid[nr][nc]) && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[cur.fi][cur.se] + 1;
                q.push(mp(nr, nc));
                pred[nr][nc] = cur;
            }
        }
    }
    // if (dist[fr][fc] != -1) {
    //     pii l = mp(fr, fc);
    //     while (l.fi != sr || l.se != sc) {
    //         l = pred[l.fi][l.se];
    //         printf("%d %d\n", l.fi, l.se);
    //     }
    // }
    printf("%d\n", dist[fr][fc]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}