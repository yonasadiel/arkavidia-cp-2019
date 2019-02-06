#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXN 1e12
#define MAXT 100

class ProblemSpec : public BaseProblemSpec
{
  protected:
    int T;
    long long N, result;

    void InputFormat()
    {
        LINE(N);
    }

    void OutputFormat()
    {
        LINE(result);
    }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(64);
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
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
  protected:
    void SampleTestCase1()
    {
        Input({"1"});
        Output({"1"});
    }

    void SampleTestCase2()
    {
        Input({"4"});
        Output({"7"});
    }

    void TestGroup1()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextLongLong(1e9, 1e12));
        }
    }

    void TestGroup2()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1e6, 1e9));
        }
    }

    void TestGroup3()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, 1e6));
        }
    }
};
