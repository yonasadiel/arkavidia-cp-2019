#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    vector<long long> N,result;

    void InputFormat() {
        LINE(T);
        LINES(N) % SIZE(T);
    }

    void OutputFormat() {
        LINES(result) % SIZE(T);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= T <= 100000);
        CONS(eachElementBetween(N, 1, 100000));
    }
private:
    bool eachElementBetween(const vector<long long>& v, long long lo, long long hi) {
        for (long long x : v)
            if (x < lo || x > hi)
                return false;
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void BeforeTestCase() {
        N.clear();
    }

    void SampleTestCase1() {
        Input({
            "2",
            "1",
            "5"
        });
        Output({
            "1",
            "5"
        });
    }

    void TestCases() {
        CASE(T = 100000, sortedArray(N, 100000, 1));
        CASE(T = 100000, sortedArray(N, 1, 100000));
        CASE(T = 100000, randomArray(N, 1, 100000));
    }
private:
    void sortedArray(vector<long long>& v, long long lo, long long hi) {
        if (lo < hi) {
            for (long long i = lo; i <= hi; i ++)
                v.push_back(i);
        } else {
            for (long long i = lo; i >= hi; i --)
                v.push_back(i);
        }
    }

    void randomArray(vector<long long>& v, long long lo, long long hi) {
        sortedArray(v, lo, hi);
        random_shuffle(v.begin(), v.end());
    }
};