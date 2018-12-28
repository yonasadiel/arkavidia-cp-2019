#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define ull unsigned long long
#define MAXN 1000000000
#define MAXT 1000

class ProblemSpec : public BaseProblemSpec {
protected:
    int T, W, H, X1, X2, Y1, Y2;
    string result;

    void InputFormat() {
        LINE(W, H, X1, Y1, X2, Y2);
    }

    void OutputFormat() {
        LINE(result);
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
        CONS(1 <= W <= MAXN);
        CONS(1 <= H <= MAXN);
        CONS(1 <= X1 <= W);
        CONS(1 <= X2 <= W);
        CONS(1 <= Y1 <= H);
        CONS(1 <= Y2 <= H);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "1 2"
        });
        Output({
            "YAY"
        });
    }

    void TestCases() {
        CASE(L = 1, R = 2);

        for (long long i = 0; i <= 100; i++)
            for (long long j = 0; j <= 100; j++)
                CASE(L = 1 + i, R = 1000000000000000000 - j);

        for (long long i = 0; i <= 10; i++)
            for (long long j = 0; j <= 10; j++)
                CASE(L = 144115188075855871 + i, R = 288230376151711743 - j);

        for (long long i = 0; i <= 10; i++)
            for (long long j = 0; j <= 10; j++)
                CASE(L = 159202181970746799 + i, R = 529566899057755602 - j);

        for (long long i = 0; i <= 1000; i++)
            for (long long j = 0; j <= 100; j++)
                CASE(L = 297379960876591172 + i, R = 801972410549895275 - j);
    }
};
