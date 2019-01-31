#include <tcframe/spec.hpp>
using namespace tcframe;

#define MAXT 10
#define MAXN 100000
#define MAXVAL 1000000000

class ProblemSpec : public BaseProblemSpec {
private:

    template <class T>
    bool eachVectorElementBetween(const vector<T>& X, T lo, T hi) {
        for (T x : X)
            if (x < lo || x > hi)
                return false;
        return true;
    }

protected:
    int T, N;
    vector<int> A;
    long long ans;

    void InputFormat() {
        LINE(N);
        LINE(A % SIZE(N));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void MultipleTestCasesConfig(){
        Counter(T);
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= MAXT);
    }

    void GradingConfig() {
        TimeLimit(10);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N <= MAXN);
        CONS(eachVectorElementBetween(A, 0, MAXVAL));
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
private:

    template <class T>
    void randomVectorInBetween(vector<T>& v, int N, T lo, T hi) {
        for (int i = 0; i < N; i++)
            if (abs(lo) > 2000000000 || abs(hi) > 2000000000)
                v.push_back(rnd.nextLongLong(lo, hi));
            else
                v.push_back(rnd.nextInt(lo, hi));
    }

    template <class T>
    void shuffledVectorInBetween(vector<T>& v, T lo, T hi) {
        for (T i=lo; i<=hi; i++)
            v.push_back(i);
        rnd.shuffle(v.begin(), v.end());
    }

    void goodRandom(vector<int>& v, int n) {
        v.assign(n, 536870911);
        for (int bit=0; bit<29; bit++) {
            int n_segment= rnd.nextInt(0, min(50, n / 500));
            vector<int> segment;
            segment.push_back(0);
            segment.push_back(n);
            for (int i=0; i<2*n_segment; i++) {
                segment.push_back(rnd.nextInt(1, n-1));
            }
            sort(segment.begin(), segment.end());
            for (int i=0; i<segment.size(); i+=2) {
                for (int j=segment[i]; j<segment[i+1]; j++) {
                    v[j] ^= (1 << bit);
                }
            }
        }
    }

protected:

    void BeforeTestCase() {
        A.clear();
    }

    void SampleTestCase1() {
        Input({
            "4",
            "1 7 6 4"
        });

        Output({
            "2"
        });
    }

    void TestGroup1() {
        for (int i=0; i<MAXT; i++)
            CASE(N = rnd.nextInt(MAXN/2, MAXN), randomVectorInBetween(A, N, 1, MAXVAL));
    }

    void TestGroup2() {
        for (int i=0; i<MAXT; i++)
            CASE(N = rnd.nextInt(MAXN-20, MAXN), randomVectorInBetween(A, N, 536870911, 536870911));
    }

    void TestGroup3() {
        for (int i=0; i<MAXT; i++)
            CASE(N = rnd.nextInt(MAXN/2, MAXN), goodRandom(A, N));
    }
};