#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXN 100000
#define MAXT 100

class ProblemSpec : public BaseProblemSpec
{
  protected:
    int T;
    long long N, K, result;

    void InputFormat()
    {
        LINE(N, K);
    }

    void OutputFormat()
    {
        LINE(result);
    }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void MultipleTestCasesConfig()
    {
        Counter(T);
        OutputPrefix("");
    }

    void MultipleTestCasesConstraints()
    {
        CONS(1 <= T && T <= MAXT);
    }

    void Constraints()
    {
        CONS(1 <= N && N <= MAXN);
        CONS(1 <= K && K <= N);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
  protected:
    void SampleTestCase1()
    {
        Input({"1 1"});
        Output({"1"});
    }

    void SampleTestCase2()
    {
        Input({"4 2"});
        Output({"3"});
    }

    void SampleTestCase3()
    {
        Input({"5 3"});
        Output({"4"});
    }

    void TestGroup1()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(MAXN / 2, MAXN), K = rnd.nextInt(1, N));
        }
    }

    void TestGroup2()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), K = rnd.nextInt(1, N));
        }
    }

    void TestGroup3()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), K = rnd.nextInt(1, N));
        }
    }

    void TestGroup4()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), K = rnd.nextInt(1, N));
        }
    }

    void TestGroup5()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), K = rnd.nextInt(1, N));
        }
    }
};
