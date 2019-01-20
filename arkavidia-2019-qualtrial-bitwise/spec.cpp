#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXVAL 1000000000
#define MAXN 1000
#define MAXT 1000

class ProblemSpec : public BaseProblemSpec {
protected:
    int X, N, T;
    string op;
    vector<int> ans;

    void InputFormat() {
        LINE(X, N, op);
    }

    void OutputFormat() {
        LINE(ans % SIZE(N));
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void MultipleTestCasesConfig() {
        Counter(T);
        OutputPrefix("");
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= MAXT);
    }

    void Constraints() {
        CONS(1 <= X <= MAXVAL);
        CONS(1 <= N <= MAXN);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void BeforeTestCase() {
        if (choice.size() == 0) {
            choice.push_back("AND");
            choice.push_back("XOR");
            choice.push_back("OR");
        }
        ans.clear();
    }

    void SampleTestCase1() {
        Input({
            "4 2 AND"
        });
        Output({
            "4 4"
        });
    }

    void SampleTestCase2() {
        Input({
            "11 3 OR"
        });
        Output({
            "11 11 11"
        });
    }

    void SampleTestCase3() {
        Input({
            "2 3 XOR"
        });
        Output({
            "2 1 1"
        });
    }

    void TestCases() {
        CASE(X = 1, N = 1, op = "XOR");
        CASE(X = 1, N = 2, op = "XOR");
        CASE(X = 1, N = 4, op = "XOR");
        CASE(X = 1, N = 8, op = "XOR");
        for(int i = 0; i < 996; i++){
            CASE(X = rnd.nextInt(1, MAXVAL), N = rnd.nextInt(1, MAXN), op = choice[rnd.nextInt(3)]);
        }
    }

private:
    vector<string> choice;
};
