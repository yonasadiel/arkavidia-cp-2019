//by : irfan sofyana
#include <tcframe/spec.hpp>

using namespace tcframe;
using namespace std;

#define MAXT 100
#define MAXR 100
#define MAXC 100
#define INF 1000000000
#define pb push_back
#define fi first
#define se second

class ProblemSpec : public BaseProblemSpec{
    protected:
        int T;
        int R, C, ans;
        vector<vector<char> > grid;
        
        void InputFormat(){
            LINE(R, C);
            GRID(grid) % SIZE(R, C);
        }

        void OutputFormat(){
            LINE(ans);
        }

        void GradingConfig(){
            TimeLimit(1);
            MemoryLimit(512);
        }

        void MultipleTestCasesConfig(){
            Counter(T);
            OutputPrefix("");
        }

        void MultipleTestCasesConstraints(){
            CONS(1 <= T && T <= MAXT);
        }

        void Constraints(){
            CONS(3 <= R && R <= MAXR);
            CONS(3 <= C && C <= MAXC); 
        }
};

class TestSpec : public BaseTestSpec <ProblemSpec>{
    protected:
        void BeforeTestCase(){
            grid.clear(); 
        }

        void TestGroup1(){
            for (int i = 0 ; i < 5; i++)
                CASE(R = rnd.nextInt(3, 10), C = rnd.nextInt(3, 10), GenerateGrid(R, C, grid));
        }
        
        void TestGroup2(){
            for (int i = 0; i < rnd.nextInt(1, MAXT); i++)
                CASE(R = rnd.nextInt(3, 100), C = rnd.nextInt(3, 100), GenerateGrid(R, C, grid));
        }

        void TestGroup3(){
            for (int i = 0; i < 20; i++)
                CASE(R = 3, C = rnd.nextInt(3, 100), GenerateGrid(R, C, grid));
        }

        void TestGroup4(){
            for (int i = 0; i < 20; i++)
                CASE(R = rnd.nextInt(3, 100), C = 3, GenerateGrid(R, C, grid));
        }

        void TestGroup5(){
            for (int i = 0; i < MAXT; i++)
                CASE(R = rnd.nextInt(3, 100), C = rnd.nextInt(3, 100), GenerateGrid(R, C, grid));
        }

        void TestGroup6(){
            for (int i = 0; i < rnd.nextInt(50, MAXT); i++)
                CASE(R = rnd.nextInt(3, 100), C = rnd.nextInt(3, 100), GenerateImpossible(R, C, grid));
        }

        void TestGroup7(){
            for (int i = 0; i < rnd.nextInt(50, MAXT); i++)
                CASE(R = rnd.nextInt(3, 100), C = rnd.nextInt(3, 100), GenerateMostlyImpossible(R, C, grid));
        }
        
    private:
        void InitGrid(int R, int C, vector<vector<char> > &tgrid){
            vector<char> trow;
            for (int i = 0; i < R; i++){
                trow.clear();
                for (int j = 0; j < C; j++){
                    if (i % 2 == 0 && j % 2 == 0)
                     trow.pb('#');
                    else    
                     trow.pb('.');
                }
                tgrid.pb(trow);
            }
            for (int i = 0; i < C; i++){
                tgrid[0][i] = '#';
                tgrid[R-1][i] = '#';
            }
            for (int i = 0; i < R; i++){
                tgrid[i][0] = '#';
                tgrid[i][C-1] = '#';
            }
        }

        void InitOriginalGrid(int R, int C, vector<vector<char> > &grid){
            vector<char> trow;
            for (int i = 0; i < R; i++){
                trow.clear();
                for (int j = 0; j < C; j++)
                    trow.pb('.');
                grid.pb(trow);
            }
        }

        void GenerateGrid(int R, int C, vector<vector<char> > &grid){
            vector<vector<char> > tgrid;
            int NR = 2 * R + 1;
            int NC = 2 * C + 1;

            InitOriginalGrid(R, C, grid);
            InitGrid(NR, NC, tgrid);

            //random B position
            //bx, by 1 indexing
            int bx = rnd.nextInt(2, 2*R);
            int by = rnd.nextInt(2, 2*C);
            while ((bx % 2 == 1 && by % 2 == 1)) {
                bx = rnd.nextInt(2, 2*R);
                by = rnd.nextInt(2, 2*C);
            }
            tgrid[bx-1][by-1] = 'B';

            //copy to original grid
            if (bx % 2 == 0 && by % 2 == 0){
                grid[(bx/2)-1][(by/2)-1] = 'B';
            }else {
                if (bx%2 == 1) {
                    grid[((bx-1)/2)-1][(by/2)-1] = 'B';
                    grid[((bx+1)/2)-1][(by/2)-1] = 'B';                     
                }else {
                    grid[(bx/2)-1][((by-1)/2)-1] = 'B';
                    grid[(bx/2)-1][((by+1)/2)-1] = 'B';
                }
            }

            //random F position
            //fx, fy 1 indexing
            int fx, fy;
            do{
                fx = rnd.nextInt(1, R);
                fy = rnd.nextInt(1, C);
                fx *= 2;
                fy *= 2;
            }while ((fx == bx && fy == by)||grid[(fx/2)-1][(fy/2)-1] == 'B' || tgrid[fx-1][fy-1] == 'B');
            tgrid[fx-1][fy-1] = 'F';
            grid[(fx/2)-1][(fy/2)-1] = 'F';

            vector<pair<int,int> > jalur;
            //jalur zero indexing
            GetPath(bx, by, fx, fy, tgrid, jalur);

            for (int i = 0; i < (int)jalur.size(); i++){
                //posx, posy 1 indexing
                int posx = jalur[i].fi + 1;
                int posy = jalur[i].se + 1;
                
                if (posx%2 == 0 && posy%2 == 0) {
                   if (grid[(posx/2)-1][(posy/2)-1] == '.')
                    grid[(posx/2)-1][(posy/2)-1] = 'S';
                }
                else if (posx%2 == 0 && posy%2 == 1){
                    if (grid[(posx/2)-1][((posy-1)/2)-1] == '.')
                        grid[(posx/2)-1][((posy-1)/2)-1] = 'S';
                    if (grid[(posx/2)-1][((posy+1)/2)-1] = '.')
                        grid[(posx/2)-1][((posy+1)/2)-1] = 'S';
                }
                else if (posx%2 == 1 && posy%2 == 0){
                    if (grid[((posx-1)/2)-1][(posy/2)-1] == '.')
                        grid[((posx-1)/2)-1][(posy/2)-1] = 'S';
                    if (grid[((posx+1)/2)-1][(posy/2)-1] == '.')
                        grid[((posx+1)/2)-1][(posy/2)-1] = 'S';
                }
            }

            for (int i = 0; i < R; i++){
                for (int j = 0; j < C; j++){
                    if (grid[i][j] == '.') {
                        int rdm = rnd.nextInt(1, 2);
                        if (rdm == 2)
                            grid[i][j] = '#';
                    }
                }
            }

            for (int i = 0; i < R; i++){
                for (int j = 0; j < C; j++){
                    if (grid[i][j] == 'S') {
                        grid[i][j] = '.';
                    }
                }
            }
        }

        void InitDistant(int r, int c, vector<vector<int> > &dist){
            vector<int> tmp;
            for (int i = 0; i < r; i++){
                tmp.clear();
                for (int j = 0; j < c; j++)
                    tmp.pb(-1);
                dist.pb(tmp);
            }
        }

        void InitPrede(int r, int c, vector<vector<pair<int,int> > > &prede){
            vector<pair<int,int> > tmp;
            for (int i = 0; i < r; i++){
                tmp.clear();
                for (int j = 0; j < c; j++)
                    tmp.pb(make_pair(0, 0));
                prede.pb(tmp);
            }
        }

        pair<int,int> dir(int idx){
            if (idx == 0) return make_pair(0, -1);
            else if (idx == 1) return make_pair(-1, 0);
            else if (idx == 2) return make_pair(0, 1);
            else return make_pair(1, 0);
        }

        bool is_valid(int rr, int cc, int Rr,int Cc) {
            return (2 <= rr && rr <= Rr) && (2 <= cc && cc <= Cc);
        }

        bool is_ground(int rr, int cc,const vector<vector<char> > &tgrid){
            return (tgrid[rr-1][cc-1] == '.' || 
                tgrid[rr-1][cc-1] == 'B' || tgrid[rr-1][cc-1] == 'F');
        }

        void GetPath(int bx, int by, int fx, int fy,const vector<vector<char> > &tgrid, vector<pair<int,int> > &jalur){
            queue<pair<int,int> > q;
            vector<vector<int> > dist;
            vector<vector<pair<int,int> > > prede;
            int r = (int)tgrid.size();
            int c = (int)tgrid[0].size();
            InitDistant(r, c, dist);
            InitPrede(r, c, prede);


            dist[bx-1][by-1] = 0;
            //queue still one indexing
            q.push(make_pair(bx, by));
            while (!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++){
                    pair<int,int> dr = dir(i);
                    int nr = cur.fi + dr.fi * (cur.se % 2 == 0 ? 3 : 2);
                    int nc = cur.se + dr.se * (cur.fi % 2 == 0 ? 3 : 2);
                    if (is_valid(nr, nc, r-1, c-1)){
                        if (is_ground(nr, nc, tgrid) && dist[nr-1][nc-1] == -1){
                            dist[nr-1][nc-1] = dist[cur.fi-1][cur.se-1] + 1;
                            q.push(make_pair(nr, nc));
                            prede[nr-1][nc-1] = make_pair(cur.fi-1, cur.se-1);
                        }
                    }
                }
            }       

            int tx = prede[fx-1][fy-1].fi;
            int ty = prede[fx-1][fy-1].se;
            while (tx != bx-1 || ty != by-1){
                jalur.pb(make_pair(tx, ty));
                int ttx = tx;
                int tty = ty;
                tx = prede[ttx][tty].fi;
                ty = prede[ttx][tty].se;
            }
        }
        void GenerateImpossible(int R, int C, vector<vector<char> > &grid){
            GenerateGrid(R, C, grid);
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++){
                    if (grid[i][j] == '.')
                        grid[i][j] = '#';
                }
        }
        void GenerateMostlyImpossible(int R, int C, vector<vector<char> > &grid){
            GenerateGrid(R, C, grid);
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++){
                    if (grid[i][j] == '.'){
                        if (rnd.nextInt(1, 2) == 2)
                            grid[i][j] = '#';
                    }
                }
        }
};
