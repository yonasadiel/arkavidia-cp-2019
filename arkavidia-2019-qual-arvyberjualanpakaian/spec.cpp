//by : irfan sofyana
#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXT 100
#define MAXX 100

class ProblemSpec : public BaseProblemSpec{
    protected:
        int T;
        int X, K, ans_size;
        vector<int> ans;

        void MultipleTestCasesConfig(){
            Counter(T);
            OutputPrefix("");
        }

        void InputFormat(){
            LINE(X, K);
        }

        void OutputFormat(){
            LINE(ans_size, ans % SIZE(ans_size));
        }

        void GradingConfig(){
            TimeLimit(1);
            MemoryLimit(64);
        }

        void MultipleTestCasesConstraints(){
            CONS(1 <= T && T <= MAXT);
        }

        void Constraints(){
            CONS(1 <= X <= MAXX);
            CONS(1 <= K <= MAXX);
            CONS(1<= X && X < K);
        }
};

class TestSpec : public BaseTestSpec <ProblemSpec>{
    void SampleTestCase1() {
        Input({
            "90 100"
        });
        Output({
            "4 50 50 50 20"
        });
    }
    void SampleTestCase2() {
        Input({
            "25 40"
        });
        Output({
            "3 15 10 8"
        });
    }

    void SampleTestCase3() {
        Input({
            "40 60"
        });
        Output({
            "6 12 12 10 10 10 6"
        });
    }

    void TestGroup1() {
        // corner cases
        CASE(X = 1, K = 2);
        CASE(X = 1, K = rnd.nextInt(X+1, MAXX));
        CASE(X = 99, K = 100);
        CASE(X = 89, K = 90);
    }

    void TestGroup2() {
        // random cases
        for (int i = 0; i < 100; i++){
            CASE(random_x_and_k(X, K));
        }
    }

    void TestGroup3() {
        // use prime K
        for (int i = 0; i < 100; i++){
            CASE(X = rnd.nextInt(1, MAXX-1), K = random_prime_k(X+1, MAXX));
        }
    }

    private:
        bool is_prime(int n){
            if (n <= 1) return false;
            for (int i = 2; i*i <= n; i++)
                if (n%i == 0) return false;
            return true;
        }

        int random_prime_k(int lo, int hi){
            vector<int> primes;
            for (int i = lo; i <= hi; i++)
                if (!is_prime(i))
                    primes.push_back(i);

            if ((int) primes.size() == 0) return rnd.nextInt(lo, hi);
            int idx = rnd.nextInt(0, (int) primes.size() - 1);
            return primes[idx];
        }

        void random_x_and_k(int& x, int& k) {
            int a = rnd.nextInt(1, MAXX), b;
            do {
                b = rnd.nextInt(1, MAXX);
            } while (a == b);
            x = min(a, b);
            k = max(a, b);
        }

};