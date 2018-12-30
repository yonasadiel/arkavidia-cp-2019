//by : irfan sofyana
#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 100000

class ProblemSpec : public BaseProblemSpec{
    protected:
        //list of variables 
        int T;
        int N;
        int Q;
        vector<int> a, b, x, y, ans;

        void MultipleTestCasesConfig(){
            Counter(T);
            OutputPrefix("");
        }

        void InputFormat(){
            LINE(N);
            LINES(a, b) % SIZE(N-1);
            LINE(Q);
            LINES(x, y) % SIZE(Q);
        }

        void OutputFormat(){
            LINES(ans) % SIZE(Q);
        }

        void GradingConfig(){
            TimeLimit(1);
            MemoryLimit(64);
        }

        void MultipleTestCasesConstraint(){
            CONS(1 <= T <= 100);
        }

        void Constraints(){
            CONS(1 <= N && N <= MAXN);
            CONS(eachElementBetween(a, 1, MAXN));
            CONS(eachElementBetween(a, 1, N));
            CONS(eachElementBetween(b, 1, MAXN));
            CONS(eachElementBetween(b, 1, N));
            CONS(IsMakeTree(N, a, b));
            CONS(1 <= Q && Q <= MAXN);
            CONS(eachElementBetween(x, 1, MAXN));
            CONS(eachElementBetween(x, 1, N));
            CONS(eachElementBetween(y, 1, MAXN));
            CONS(eachElementBetween(y, 1, N));
            CONS(a.size() == N-1);
            CONS(b.size() == N-1);
            CONS(x.size() == Q);
            CONS(y.size() == Q);
        }

    private:
        bool eachElementBetween(const vector<int> &X, int lo, int hi){
            for (int i = 0; i < X.size(); i++){
                if (X[i] < lo || X[i] > hi) return false;
            }
            return true;
        }

        void DFS(vector<bool> &visited,const vector<vector<int> > &adj, int node,int parent, bool &ret){
            visited[node] = true;
            for (int i = 0; i < adj[node].size(); i++){
                int nxt = adj[node][i];
                if (visited[nxt]) {
                    if (nxt != parent) {
                        ret = false;
                        return;   
                    }
                }else{
                    DFS(visited, adj, nxt, node, ret);
                }
            }
        }

        bool IsAllVisited(int N,vector<bool> &visited){
            for (int i = 1; i <= N ; i++){
                if (visited[i] == false) return false;
            }
            return true;
        }

        bool IsMakeTree(int N,const vector<int> &a,const vector<int> &b){
            vector<bool> visited(N+1);
            vector<vector<int> > adj(N+1);
            for(int i = 0; i < N-1; i++){
                adj[a[i]].push_back(b[i]);
                adj[b[i]].push_back(a[i]);
            }
            bool ret = true;
            fill(visited.begin(), visited.end(), false);
            DFS(visited, adj, 1, 0, ret);
            return IsAllVisited(N, visited) && ret;
        }
};

class TestSpec : public BaseTestSpec <ProblemSpec>{
    protected:

        void BeforeTestCase(){
            a.clear();
            b.clear();
            x.clear();
            y.clear();
        }        

        void TestCases(){
            CASE(N = 3, a = {1, 1}, b={2, 3}, Q = 6, x = {1, 1, 1, 3, 2, 3}, y = {1, 2, 3, 2, 3, 3});
            CASE(N = 10, RandomTree(N, a, b), Q = 10, RandomQuery(Q, N, x, y));
            CASE(N = 1000, RandomTree(N, a, b), Q = 2000, RandomQuery(Q, N,  x, y));
            for (int i = 0; i < 10; i++){
                CASE(N = MAXN-i, 
                RandomTree(N, a, b), 
                Q = MAXN-i,
                RandomQuery(Q, N, x, y));
            }
            for (int i = 0; i < 37; i++){
                CASE(N = rnd.nextInt(1, MAXN),
                RandomTree(N, a, b), 
                Q = rnd.nextInt(1, MAXN),
                RandomQuery(Q, N, x, y));
            }
            for (int i = 0; i < 50; i++){
                CASE(N = rnd.nextInt(1, MAXN),
                RandomTree(N, a, b), 
                Q = rnd.nextInt(N, MAXN),
                RandomQuery(Q, N, x, y));
            }
        }

    private:
        void renumber(int N, vector<int> &a, vector<int> &b){
            vector<int> p;
            for (int i = 1; i <= N; i++)
                p.push_back(i);
            rnd.shuffle(p.begin(), p.end());
            for (int i = 0 ; i < (int)a.size(); i++){
                a[i] = p[a[i]-1];
                b[i] = p[b[i]-1];
            }
        }
        void RandomTree(int N, vector<int> &a, vector<int> &b){
            for (int i = 2; i <= N; i++){
                a.push_back(i);
                b.push_back(rnd.nextInt(1,i-1));
            }
            renumber(N, a, b);
        }
        void RandomQuery(int Q,int N, vector<int> &x, vector<int> &y){
            vector<int> p1, p2;
            for (int i = 1; i <= N; i++){
                p1.push_back(i);
                p2.push_back(N+1-i);
            }
            for (int i = 0; i < 10; i++)
                rnd.shuffle(p1.begin(), p1.end());
            for (int i = 0; i < 15; i++)
                rnd.shuffle(p1.begin(), p1.end());
            if (Q <= N){
                for (int i = 0; i < Q; i++){
                    x.push_back(p1[i]);
                    y.push_back(p2[i]);
                }
            }else{
                for (int i = 0; i < N; i++){
                    x.push_back(p1[i]);
                    y.push_back(p2[i]);
                }
                for (int i = 0; i < Q-N; i++){
                    x.push_back(rnd.nextInt(1, N));
                    y.push_back(rnd.nextInt(1, N));
                }
            }
        }
};
