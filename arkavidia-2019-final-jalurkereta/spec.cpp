#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define EPS 0.0000001
#define MAXN 10000
#define MAXT 10

class ProblemSpec : public BaseProblemSpec
{
  protected:
    int T, N, M, result;
    vector<char> tipe;
    vector<int> a, b, c;

    void InputFormat()
    {
        LINE(N, M);
        LINES(tipe, a, b, c) % SIZE(N);
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
        CONS(1 <= N <= MAXN);
        CONS(1 <= M <= MAXN);
        CONS(allElementBetween(a, N, 1, M));
        CONS(allElementBetween(b, N, 1, M));
        CONS(allElementBetween(c, N, 1, M));
        CONS(allElementBetween(tipe, N, 'A', 'B'));
    }

  private:
    bool allElementBetween(vector<int> arr, int N, int a, int b)
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < a or arr[i] > b)
                return false;
        }
        return true;
    }

    bool allElementBetween(vector<char> arr, int N, char a, char b)
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < a or arr[i] > b)
                return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
  protected:
    void SampleTestCase1()
    {
        Input({"4 9",
               "A 1 2 3",
               "A 3 4 5",
               "A 6 7 9",
               "B 5 7 8"});
        Output({"5"});
    }

    void BeforeTestCase()
    {
        a.clear();
        tipe.clear();
        b.clear();
        c.clear();
    }

    void TestGroup1()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(1, N - 1), createPlanarGraphWithList(N, M, tipe, a, b, c));
        }
    }

    void TestGroup2()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(1, N - 1), createPlanarGraphWithList(N, M, tipe, a, b, c));
        }
    }

    void TestGroup3()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(1, N - 1), createPlanarGraphWithList(N, M, tipe, a, b, c));
        }
    }

    void TestGroup4()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(1, N - 1), createPlanarGraphWithList(N, M, tipe, a, b, c));
        }
    }

  private:
    void createPlanarGraphWithList(int N, int M, vector<char> &t, vector<int> &a, vector<int> &b, vector<int> &c)
    {
        vector<int> v;
        int maxNum, totalEdge;
        maxNum = totalEdge = 0;
        v.push_back(0);
        vector<tuple<int, int, int, int>> temp;
        while (totalEdge < M)
        {
            for (int i = 0; i < v.size() && maxNum < N && totalEdge < M; i++)
            {
                if (rnd.nextInt(0, 4) == 0)
                {
                    totalEdge += 1;
                    if (v.size() > 1 && i != v.size() - 1 && (maxNum == N - 1 || rnd.nextInt(0, 1) == 0) && fabs(log(M - totalEdge) - (N - maxNum + 1)) <= EPS)
                    {
                        int x = v[i];
                        int y = v[i + 1];
                        v.erase(v.begin() + i);
                        v.erase(v.begin() + i);
                        maxNum++;
                        v.insert(v.begin() + i, maxNum);
                        auto it = make_tuple('A', maxNum, x, y);
                        temp.push_back(it);
                    }
                    else
                    {
                        int x = v[i];
                        v.erase(v.begin() + i);
                        maxNum++;
                        v.insert(v.begin() + i, maxNum);
                        maxNum++;
                        v.insert(v.begin() + i, maxNum);
                        auto it = make_tuple('B', maxNum - 1, maxNum, x);
                        temp.push_back(it);
                    }
                }
            }
        }

        for (int i = 0; i < temp.size(); i++)
        {
            int x, y, z, tipe;
            auto it = temp[i];
            tie(tipe, x, y, z) = it;
            t.push_back(tipe);
            a.push_back(x);
            b.push_back(y);
            c.push_back(z);
        }
    }
};
