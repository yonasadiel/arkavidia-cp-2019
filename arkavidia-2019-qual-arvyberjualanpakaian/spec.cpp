<<<<<<< HEAD
//by : irfan sofyana
=======
>>>>>>> 3188206d949504492f8794639a35632955bc1aef
#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

<<<<<<< HEAD
#define MAXT 100
#define MAXX 200

class ProblemSpec : public BaseProblemSpec{
    protected:
        int T;
        int X, K, ans_size;
        vector<int> ans;

        void MultipleTestConfig(){
=======
#define MAXT 10
#define MAXN 10
#define MINK 91
#define MAXK 100

class ProblemSpec : public BaseProblemSpec {
    private:
		bool eachElementBetween(const vector<int>& v, int lo, int hi) {
			for (int x : v) {
				if (x < lo || x > hi) {
					return false;
				}
			}
			return true;
		}

    protected:
        int T;
        int N, K;
        vector<int> ans_size;
        vector<vector<int> > ans;
        vector<int> X;

        void MultipleTestCasesConfig(){
>>>>>>> 3188206d949504492f8794639a35632955bc1aef
            Counter(T);
            OutputPrefix("");
        }

        void InputFormat(){
<<<<<<< HEAD
            LINE(X, K);
        }

        void OutputFormat(){
            LINE(ans_size, ans % SIZE(ans_size));
=======
            LINE(N, K);
            LINES(X) % SIZE(N);
        }

        void OutputFormat(){
            LINES(ans_size, ans) % SIZE(N);
>>>>>>> 3188206d949504492f8794639a35632955bc1aef
        }

        void GradingConfig(){
            TimeLimit(1);
            MemoryLimit(64);
        }

<<<<<<< HEAD
        void MultipleTestCasesConstraint(){
=======
        void MultipleTestCasesConstraints(){
>>>>>>> 3188206d949504492f8794639a35632955bc1aef
            CONS(1 <= T && T <= MAXT);
        }

        void Constraints(){
<<<<<<< HEAD
            CONS(1 <= X <= MAXX);
            CONS(1 <= K <= MAXX);
            CONS(1<= X && X < K);
=======
            CONS(MINK <= K <= MAXK);
            CONS(eachElementBetween(X, 1, K - 1));
            CONS(1 <= N <= MAXN);
>>>>>>> 3188206d949504492f8794639a35632955bc1aef
        }
};

class TestSpec : public BaseTestSpec <ProblemSpec>{
<<<<<<< HEAD
    void SampleTestCase1(){
        Input({
            "90 100"
        });
        Output({
            "4 20 50 50 50"
        });
    }
    void SampleTestCase2(){
        Input({
            "25 40"
        });
        Output({
            "3 10 8 15"
        });
    }

    void SampleTestCase3(){
        Input({
            "40 60"
        });
        Output({
            "6 10 12 10 6 10 12"
        });
    }

    void TestCases(){
        CASE(X = 1, K = 2);
        CASE(X = 1, K = rnd.nextInt(X+1, MAXX));
        for (int i = 0; i < 70; i++){
            CASE(X = rnd.nextInt(1, MAXX-1), K = rnd.nextInt(X+1, MAXX));
        }
        for (int i = 0; i < 28; i++){
            CASE(X = rnd.nextInt(1, MAXX-1), K = RandomK(X+1, MAXX));
        }
    }

    private:
        bool cek(int n){
            if (n <= 1) return false;
            for (int i = 2; i <= (int)sqrt(n); i++){
                if (n%i == 0) return false;
            }
            return true;
        }

        int RandomK(int lo,int hi){
            vector<int> bil;
            for (int i = lo; i <= hi; i++){
                if (!cek(i)){
                    bil.push_back(i);
                }
            }
            if ((int)bil.size() == 0) return rnd.nextInt(lo, hi);
            rnd.shuffle(bil.begin(), bil.end());
            int idx = rnd.nextInt(0, (int)bil.size()-1);
            return bil[idx];
        }

=======
    void BeforeTestCase() {
        X.clear();
    }

    void SampleTestCase1() {
        Input({
            "2 100",
            "90",
            "9"
        });
        Output({
            "4 50 50 50 20",
            "1 9"
        });
    }
    void SampleTestCase2() {
        Input({
            "1 92",
            "70"
        });
        Output({
            "3 46 46 4"
        });
    }

    void TestGroup1() {
        CASE(K = 100, X = {1, 2, 19, 64, 73, 82, 90, 91, 94, 98, 99}, N = X.size());
        CASE(K = 91, N = 1, X = {1});
        CASE(K = 99, X = {1, 2, 81, 89, 90, 98}, N = X.size());
    }

    void TestGroup3() {
        // random
        for (int i=0; i<MAXT; i++)
            CASE(
                K = rnd.nextInt(MINK, MAXK),
                N = MAXN,
                randomInBetween(X, N, K / 2, K - 1)
            );
    }

    void TestGroup2() {
        // random
        for (int i=0; i<MAXT; i++)
            CASE(
                K = rnd.nextInt(MINK, MAXK),
                N = MAXN,
                randomInBetween(X, N, K / 2, K - 1)
            );
    }

    void TestGroup4() {
        // worst time
        for (int i=0; i<MAXT; i++)
            CASE(K = 96, N = MAXN, randomInBetween(X, N, 95, 95));
    }

private:
    void randomInBetween(vector<int>& v, int N, int lo, int hi) {
        for (int i=0; i<N; i++) {
            v.push_back(rnd.nextInt(lo, hi));
        }
    }
>>>>>>> 3188206d949504492f8794639a35632955bc1aef
};