#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXN 100000
#define MAXT 10

class ProblemSpec : public BaseProblemSpec
{
  protected:
    int T, N, result;
    vector<char> tipe;
    vector<int> a, b, c;

    void InputFormat()
    {
        LINE(N);
        LINES(tipe, a, b, c) % SIZE(N);
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
        CONS(1 <= N <= MAXN);
        CONS(N % 2 == 0);
        CONS(a.size() == N);
        CONS(b.size() == N);
        CONS(c.size() == N);
        CONS(allElementBetween(a, N, 1, 3 * N / 2 + 1));
        CONS(allElementBetween(b, N, 1, 3 * N / 2 + 1));
        CONS(allElementBetween(c, N, 1, 3 * N / 2 + 1));
        CONS(allElementBetween(tipe, N, 'A', 'B'));
        CONS(nodeCheck(N, a, b, c));
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

    bool nodeCheck(int N, const vector<int> &a, const vector<int> &b, const vector<int> &c)
    {
        int M = N * 3 / 2 + 1;
        int cek[M + 5];
        for (int i = 0; i < M; i++)
            cek[i] = 0;
        for (int i = 0; i < N; i++)
        {
            cek[a[i] - 1]++;
            cek[b[i] - 1]++;
            cek[c[i] - 1]++;
        }

        for (int i = 0; i < M; i++)
        {
            if (cek[i] <= 0 || cek[i] > 2)
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
        Input({"6",
               "A 1 2 3",
               "A 2 4 5",
               "B 4 7 6",
               "A 3 7 8",
               "B 5 6 9",
               "B 9 8 10"});
        Output({"4"});
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
            CASE(N = rnd.nextInt(1, MAXN / 2) * 2, createPlanarGraphWithList(N, tipe, a, b, c));
        }
    }

    // void TestGroup2()
    // {
    //     for (int i = 0; i < MAXT; i++)
    //     {
    //         CASE(N = rnd.nextInt(1, MAXN / 2) * 2, createPlanarGraphWithList(N, tipe, a, b, c));
    //     }
    // }

    // void TestGroup3()
    // {
    //     for (int i = 0; i < MAXT; i++)
    //     {
    //         CASE(N = rnd.nextInt(1, MAXN / 2) * 2, createPlanarGraphWithList(N, tipe, a, b, c));
    //     }
    // }

    // void TestGroup4()
    // {
    //     for (int i = 0; i < MAXT; i++)
    //     {
    //         CASE(N = rnd.nextInt(1, MAXN / 2) * 2, createPlanarGraphWithList(N, tipe, a, b, c));
    //     }
    // }

  private:
    list<int>::const_iterator getRandomElement(const list<int> &l, int lo, int hi)
    {
        int pos = rnd.nextInt(lo, hi);
        list<int>::const_iterator it = l.begin();
        while (pos--)
            ++it;
        return it;
    }

    void createPlanarGraphWithList(int N, vector<char> &t, vector<int> &a, vector<int> &b, vector<int> &c)
    {
        std::list<int> l;
        l.push_back(1);
        int jalurCount = 1;
        int aCount = 0, bCount = 0;
        while (aCount + bCount < N)
        {
            char typeNode = 'A' + rnd.nextInt(0, (l.size() > 1 ? 1 : 0));
            if (aCount == N / 2)
                typeNode = 'B';
            t.push_back(typeNode);

            if (typeNode == 'A')
            {
                list<int>::const_iterator pos = getRandomElement(l, 0, l.size() - 1);
                int _b = ++jalurCount, _c = ++jalurCount;
                a.push_back(*pos);
                b.push_back(_b);
                c.push_back(_c);
                l.insert(pos, _b);
                l.insert(pos, _c);
                l.erase(pos);
                aCount++;
            }
            else
            {
                list<int>::const_iterator pos1 = getRandomElement(l, 0, l.size() - 2);
                list<int>::const_iterator pos2 = pos1;
                pos2++;
                int _c = ++jalurCount;
                a.push_back(*pos1);
                b.push_back(*pos2);
                c.push_back(_c);
                l.insert(pos1, _c);
                l.erase(pos1);
                l.erase(pos2);
                bCount++;
            }
        }
    }
};
