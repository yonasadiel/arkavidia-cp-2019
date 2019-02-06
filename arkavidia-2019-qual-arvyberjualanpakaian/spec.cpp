#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

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
            Counter(T);
            OutputPrefix("");
        }

        void InputFormat(){
            LINE(N, K);
            LINES(X) % SIZE(N);
        }

        void OutputFormat(){
            LINES(ans_size, ans) % SIZE(N);
        }

        void GradingConfig(){
            TimeLimit(1);
            MemoryLimit(64);
        }

        void MultipleTestCasesConstraints(){
            CONS(1 <= T && T <= MAXT);
        }

        void Constraints(){
            CONS(MINK <= K <= MAXK);
            CONS(eachElementBetween(X, 1, K - 1));
            CONS(1 <= N <= MAXN);
        }
};

class TestSpec : public BaseTestSpec <ProblemSpec>{
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
};