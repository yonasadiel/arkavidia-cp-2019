//by : irfan sofyana
#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXT 100
#define MAXX 200

class ProblemSpec : public BaseProblemSpec{
    protected:
        int T;
        int X, K, ans_size;
        vector<int> ans;

        void MultipleTestConfig(){
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

        void MultipleTestCasesConstraint(){
            CONS(1 <= T && T <= MAXT);
        }

        void Constraints(){
            CONS(1 <= X <= MAXX);
            CONS(1 <= K <= MAXX);
            CONS(1<= X && X < K);
        }
};

class TestSpec : public BaseTestSpec <ProblemSpec>{
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

};