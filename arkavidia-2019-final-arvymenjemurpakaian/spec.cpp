#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXT 100
#define MAXN 200000

class ProblemSpec : public BaseProblemSpec
{
  protected:
    int T;
    long long N, M;
    string result;

    void InputFormat()
    {
        LINE(N, M);
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
        CONS(1 <= M && M <= N);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
  protected:
    void SampleTestCase1()
    {
        Input({"4 2"});
        Output({"YA"});
    }

    void SampleTestCase2()
    {
        Input({"10 4"});
        Output({"YA"});
    }

    void SampleTestCase3()
    {
        Input({"10 1"});
        Output({"TIDAK"});
    }

    void SampleTestCase4()
    {
        Input({"12 7"});
        Output({"YA"});
    }

    void TestGroup1()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(1, N));
        }
    }

    void TestGroup2()
    {
        int cnt = 0;
        for (int i = 1; cnt < MAXT; i++)
        {
            for (int j = 1; j <= i && cnt < MAXT; j++)
            {
                CASE(N = i, M = j);
                cnt++;
            }
        }
    }

    void TestGroup3()
    {
        int cnt = 0;
        for (int i = 15; cnt < MAXT; i++)
        {
            for (int j = 1; j <= i && cnt < MAXT; j++)
            {
                CASE(N = i, M = j);
                cnt++;
            }
        }
    }
};
